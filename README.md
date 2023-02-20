# Malloc / Free / Realloc



## Strategies:

* Make all the tiny/small allocations take the same size (equivalent to the threshold).
    * This could make the re-use of free blocks more efficient.


* No re-use of freed blocks, but occasional operations to free empty zones.

