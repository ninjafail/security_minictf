FROM ubuntu:20.04

# install socat
RUN apt-get update && apt-get install -y socat

# setup 'ctf' user
RUN useradd -d /home/ctf/ -m -p ctf -s /bin/bash ctf
RUN echo "ctf:ctf" | chpasswd
WORKDIR /home/ctf

# copy relevant files into /home/ctf
COPY mockup .


# make sure that the ctf user can't break stuff
RUN chown -R root:root /home/ctf

# let `socat` spawn the vulnerable process on each network connection
USER ctf
CMD socat -d -d TCP4-LISTEN:1337,fork,reuseaddr EXEC:'./mockup',stderr
