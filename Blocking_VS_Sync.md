# Network Programming: Blocking & Non-blocking, Synchronous & Asynchronous

blocking operation does NOT equal to synchronous, also non-blocking operation does NOT equal to asynchronous. Actually, they don't have direct relevant with each other.


## Synchronous & Asynchronous

Synchronous/asynchronous describes the communication mechanism.

Synchronous is, when we started a function call, the call will not return anything until it gets the result, the function needs to finish everything before it can give anything to us.

Asynchronous does not need to wait for the function completes its operation, once we call it, it returns immediately without any result, the function uses callback function (or other notification method) to "notify" us to get the value after it completes execution.

## Blocking & Non-blocking
Unlike synchronous/asynchronous, blocking/non-blocking focuses on the status of the program while waiting for the result from the function call.

A blocking operation hangs up current thread before it gets the result, in other words, a blocking operation will let the current thread wait for the result returns, even if the target function will use a callback function to notify client side to fetch the result, the thread on the client side will still be blocked until it gets the returned result. In opposite way, the non-blocking operation will not hang up the current thread if no result returned immediately.


[REF]https://www.jianshu.com/p/aed6067eeac9
[REF]https://magickaichen.com/unblock-block/
