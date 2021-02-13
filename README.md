# Lightspeed digits repetition count
A light and fast code to count digit repetition in a number written in c.

# How it works?



```
0000 0000 0000 0000 0000 0000
  6    5    4    3    2    1
```

* If we think an int 64bit as an array of bits you'll have something like this (if using 4bits in the BITS_LENGTH macro).
* Each 4bits can contains up to 1111 or 15 (decimal).
* We can consider each 4 bits block as a container which stores the repetion of the numbers.

for instance, if we have 2 occurance of 4 we'll have...
```
0000 0000 0010 0000 0000 0000
  6    5    4    3    2    1
```
where 0010 in decimal is 2.
