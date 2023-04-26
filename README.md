<h1 align="center"> Holberton School Simple Shell.</h1>
<h2 align="center">This repository contains the code of Simple Shell.</h2>

## Examples

h1> Description. </h1>
Is a command-line interpreter or shell that provides a command line user interface for Unix-like operating systems.

## Files Descriptions:
### execve.c :       <br>
-The execve function is an implementation that uses fork and execve to execute a command on the system. The args parameter is an array of strings that contains the arguments for the command. In summary, the function creates a child process using fork, then executes the specified command in the child process using execve. The parent process waits for the child process to finish using wait, and then the function returns. <br>
### getenv.c :     <br>
-  The getenv.c function searches for an environment variable by iterating through the environ array and comparing each element to the specified string. If a match is found, the function returns a pointer to the value of the variable. If no match is found, the function returns NULL. <br>
