## Simple Daytime Server / Client
*By iJinjin (Youngjin Jin)*

### What it does

While the server is running, executing the client will print the local time and time zone.

### How to compile

Both the server and the client can be compiled by typing the `make` command in the terminal.  
`make clean` cleans all object / executable files  
`make clobber` cleans all object / executable files + all unnecessary files created from previous make commands

### Things to note

Server should be opened with a **port number** passed as the argument.

Client should be opened with a **valid IP address** (IPv4) and **port number**.

(Execute client and server in separate terminals: terminals such as **tmux** facilitate this job)

Note that the port number for server and client **must match** for the connection to work.

ex)
```
./daytimeserv 1234
```

ex)
```
./daytimecli 127.0.0.1 1234
```

The server should return the **local time** and the **time zone** to the client.

Example of execution:
```
terminal$ ./daytimecli 127.0.0.1 1234
Date: Fri Apr 13 17:18:22 2018 KST
terminal$ (client exits)
```
