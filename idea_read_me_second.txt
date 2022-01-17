Or idea is about the one time pad. However the students have to find that out first. Since finding that out is a difficulty in itself, we intruduced the classic vulnerability of the one-time-pad: Namely having to reuse the finite key.

How can they find out, that it't a one time pad?
1. a good hint in the description (TODO)
2. all messages are being encrypted at the same length
3. no keys being shared -> seems like symmetric crypto
4. when you xor the known message with its encryption, you can leak part of the key, which might include another hint (key includes a text from shakeseare or a transctipt from the shrek)

In the beginning part of the key there is another tip. Something like, that no infinite keys exist.
They can also see, that the same message always encrypts to different values, however the key always to the same. Now the idea would be to do exactly what's being done in the exploit.
