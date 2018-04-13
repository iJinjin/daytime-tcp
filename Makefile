CC = gcc

all: daytimecli daytimeserv
clobber: clean
	rm -f *~ \#*\# core
clean:
	rm -f daytimecli daytimeserv *.o

daytimecli: daytimecli.c
	$(CC) -o $@ $?

daytimeserv: daytimeserv.c
	$(CC) -o $@ $?
