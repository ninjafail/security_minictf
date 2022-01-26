'I heard about an encryption technique which is impossible to break, so my secret is 100% safe. I also encrypted the 
flag with the start of the key, so you can never reach it. Here's the program where I implemented it. Feel free to fail 
trying to break my superior implementation.' 
- Evil Minion.

Hint:   You can use pwntools (pwn.process) to talk to the binary. You can also use bitstring.BitArray to transform 
        string bits to BitArrays, which you can do calculations on and transform them to real bytes using 
        BitArray.tobytes(). Also note that the key and flag used on the server differ from the ones in this binary.

