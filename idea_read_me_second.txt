Our idea is about the one time pad. However, the students have to find that out first. Since finding that out is a
difficulty in itself, we introduced the classic vulnerability of the one-time-pad: Namely having to reuse the finite key.

How can they find out, that it's a one time pad?
1. a good hint in the description (TODO: a better hint?)
2. all messages are being encrypted at the same length
3. no keys being shared -> seems like symmetric crypto
4. when you xor the known message with its encryption, you can leak part of the key, which might include another hint
   (e.g. key includes a text from shakespeare or a transcript from shrek)

Once they have found out, that it's a one time pad, they might start to decrypt the key...
While decrypting the plaintext key shows some more hints:
    - the key is too long to always reconnect and use the known message once everytime (TODO: maybe introduce a loading time)
    - however there are no infinite keys *sus emoji*

The rest they have to figure out themselves.

For the tutors who want to see an example exploit, take a look into private/writeup.txt and private/exploit_mockup.py
(or README.md if you want to see our messy notes).

