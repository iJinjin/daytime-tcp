/* Simple Daytime Server */
/* From EE323 Assignment */
/* Youngjin Jin */

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXLINE 1024
#define LISTENQ 8

int main (int argc, char **argv) {

    int listenfd, connfd; /* listening socket, connection socket */
    struct sockaddr_in servaddr, cliaddr;
    int enable = 1;       /* for setsockopt */
    socklen_t len;        /* for accept, length of cliaddr */
    char buf[MAXLINE];    /* buffer */
    int n;                /* the number of bytes read */
    time_t ticks;

    listenfd = socket (AF_INET, SOCK_STREAM, 0); /* make a listening socket */

    /* make the listening socket *reusable*, otherwise we need to wait 15 mins */
    setsockopt (listenfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof (int));

    /* sets the servaddr to zero bytes */
    bzero (&servaddr, sizeof (servaddr));
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons (atoi (argv[1]));

    /* INADDR_ANY indicates the listening socket will accept any connection
       request regardless of the IP address */
    servaddr.sin_addr.s_addr = htonl (INADDR_ANY);

    /* bind the servaddr to listenfd */
    bind (listenfd, &servaddr, sizeof (servaddr));

    /* make listenfd into a passive socket, waiting for incoming connections */
    listen (listenfd, LISTENQ);

    for ( ; ; ) {
        
        connfd = accept (listenfd, NULL, NULL);

        ticks = time (NULL);

        /* format local time into a string */
        strftime (buf, sizeof (buf), "Date: %c %Z\r\n", localtime (&ticks));
        write (connfd, buf, strlen (buf));

        close (connfd);

    }

}
