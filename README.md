# SimpleLog
A Simple Log For C Applications In Console

By defining ENABLE_LOGGING, this library can be run otherwise library will be deactive.
When you print something, the output will appear like this:
[Caller] [Date & Time] Message

INFO() -> prints in green color
WARNING() -> prints in yellow color
TRACE() -> prints in blue color
EXIT(EXIT_CODE) -> prints in red color & prints aborted with EXIT_CODE

When this macros defined by core infront of it it changes caller as CORE otherwise you need to write as string.

CORE_INFO() -> [CORE]
INFO(Caller) -> [Caller]
