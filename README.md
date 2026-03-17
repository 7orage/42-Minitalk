_This project has been created as part of the 42 curriculum by lheteau._  
_We are the 14th march 2025._

# Minitalk
![Previsualisation of the Minitalk's output](https://github.com/user-attachments/assets/042ab962-9ca3-4952-bce5-a177e37d0504)
### Table of contents
***
1. _Description_
2. _Instructions_
3. _Ressources_

***
## **Description**
***
• Minitalk is a client-server communication system that transmits data using only UNIX signals (SIGUSR1 and SIGUSR2). The goal is to send strings from a client to a server by converting characters into binary, demonstrating a mastery of bitwise operations and inter-process synchronization.
***
• The communication relies on a bit-by-bit protocol using two UNIX signals: the client decomposes each character into 8 bits, sending a SIGUSR1 for a bit set to 1 and a SIGUSR2 for a bit set to 0. 

The server receives these signals, reconstructs the byte using bitwise operations, and employs a static boolean flag to switch between two phases: it first collects and stores the client's PID as a string, then switches to printing the message characters directly to the terminal. Both the PID and the message are terminated by a null character (\0), allowing the server to know exactly when to transition states or send a final confirmation signal back to the client to acknowledge receipt.

## **Instructions**
***
• To use it in your own project, include the header :
```#include "minitalk.h"```.

To compile the project :
```make```  

To proceed with execution, utilize the two a.out files as detailed below :
```./server```

```./client <PID_SERVER> <MESSAGE>```
![Previsualisation of the error message when ](https://github.com/user-attachments/assets/39931b31-0ba7-4d6c-8065-b08b094d559b)

## **Ressources**
***
• [Kent Uni's introduction to Unix signals](https://www.cs.kent.edu/~ruttan/sysprog/lectures/signals.html) was a fundamental resource for understanding the concept of PID.  

[Open group's article](https://pubs.opengroup.org/onlinepubs/009695399/basedefs/signal.h.html) is a comprehensive deep-dive into <signal.h>.  

To better understand volatile variables and the use of atomic global variables, I dived into [Duino's post on projectduino.com](https://projetsduino.com/1647/volatile/) and [Dthe documentation of IBM](https://www.ibm.com/docs/fr/i/7.5.0?topic=qualifiers-volatile-type-qualifier ).
***
• Artificial Intelligence tools were used to master the optimization of the Makefile.

They were also helpful in the writing and structuring of this README.
***
• To push the project to its highest standard, the following generators were instrumental in identifying edge cases and validating the robustness of the sending and receiving processes :

[Loremipsum360 one](https://fr.loremipsum360.com/) to have the choice of character's number and

[The famous Lorem ipsum website](https://www.lipsum.com/) .
***
<a href="https://www.linkedin.com/in/laura-heteau/" target="_blank"><img align="center" alt="LinkedIn" height="60" src="https://user-images.githubusercontent.com/81205527/157161849-01a9df02-bf32-45be-add4-122bc40b48cf.png"></a>
<a href = "mailto:laura.heteauu@gmail.com"> <img align="center" alt="Gmail - laura.heteauu@gmail.com" height="60" src="https://user-images.githubusercontent.com/81205527/157161831-eb9dffee-404b-4ffe-b0af-34671219f7fb.png"></a>
