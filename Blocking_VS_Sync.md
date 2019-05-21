# Network Programming: Blocking & Non-blocking, Synchronous & Asynchronous

blocking operation does NOT equal to synchronous, also non-blocking operation does NOT equal to asynchronous. Actually, they don't have direct relevant with each other.


## Synchronous & Asynchronous

Synchronous/asynchronous describes the communication mechanism.

Synchronous is, when we started a function call, the call will not return anything until it gets the result, the function needs to finish everything before it can give anything to us.

Asynchronous does not need to wait for the function completes its operation, once we call it, it returns immediately without any result, the function uses callback function (or other notification method) to "notify" us to get the value after it completes execution.

## Blocking & Non-blocking
Unlike synchronous/asynchronous, blocking/non-blocking focuses on the status of the program while waiting for the result from the function call.

A blocking operation hangs up current thread before it gets the result, in other words, a blocking operation will let the current thread wait for the result returns, even if the target function will use a callback function to notify client side to fetch the result, the thread on the client side will still be blocked until it gets the returned result. In opposite way, the non-blocking operation will not hang up the current thread if no result returned immediately.


## A Simple Example
You are the customer making the phone call to the hotel to make a reservation.

Synchronous: The hotel receptionist receives the call and ask you to wait while he/she needs to look up the calendar to see if there is any available time slot. After finished looking up, the receptionist tells you if the requested time slot is available (result returned).

Asynchronous: The hotel receptionist receives the call and tell you that they have got the information, then he/she hangs up, you will receive a call back from the hotel once they have finished checking (callback).

Blocking: You make the phone call, before you get any result back, you will sit on the couch and do nothing until the hotel tells you if your reservation can be made.

Non-blocking: You make the phone call, after telling the information to the hotel, you start to do something else (drink water, eat snacks, take shower, etc.) and check if you get any results every few minutes.

[REF]https://www.jianshu.com/p/aed6067eeac9
[REF]https://magickaichen.com/unblock-block/
