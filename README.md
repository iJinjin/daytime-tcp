## Simple Daytime Server / Client
*By iJinjin (Youngjin Jin)*

Server should be opened with a **port number** passed as the argument

Client should be opened with a **valid IP address** (IPv4) and **port number**

Note that the port number for server and client **must match** for the connection to work

ex)
```
./daytimeserv 1234
```

ex)
```
./daytimecli 127.0.0.1 1234
```

The client should return the local time and the time zone

Example of execution:
```
Date: Fri Apr 13 17:18:22 2018 KST
```
