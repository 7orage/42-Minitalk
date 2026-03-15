14 mars


exec = client 
exec = server 
==
1 makefile = 2 output

server (output) = PID
client (input) = PID "message to print"


deux signals ? SIGUSR1 SIGUSR2 (GLOBAL VARIABLE)
pour un SIGUSR == signal_handler fonction 
	sending signals to processses by using kill <signal name> <PID> command 



Client Checklist

In the "client.c" file, you will...

*Write a program (main) in which the client takes two parameters/arguments

	*The PID of the server to which it wants to send the message

    *A message

*Encrypt the message (I did the encryption via bits)
{
	chaques character a un indice dan sle tableau ascii (H == 72 ), ce nombre la doit etre convertit en bits et envoye biuts par bits au server 
}

*Send the message to the server (via its PID)

*Create a stop condition so that the server knows when it has finished receiving the message



Server Checklist

In the "server.c" file, you will...

*Display its PID

*Create an endless loop so that the server can receive signals at any time

*Receive signals

*Decrypt signals

        *For each signal received (SIGUSR1 & SIGUSR2) it should take a certain action



Basic Checklist

Of course you will also need to do these three things:

*Makefile (create the "server" and "client" executables)

*Manage errors & remove all leaks

*Deal with the holy norminette


ressources 
- https://www.cs.kent.edu/~ruttan/sysprog/lectures/signals.html //article pour PID 