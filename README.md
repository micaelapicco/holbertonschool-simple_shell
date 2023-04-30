
# <h1> <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/C_Programming_Language.svg/1200px-C_Programming_Language.svg.png" width=3% heigth=3% ></img></h1> <h1 align="center"> Holberton School Simple Shell.</h1>

- In C, a shell typically refers to a program that provides a command-line interface (CLI) for interacting with an operating system. The shell allows users to execute various commands and programs, navigate through directories, and manage files and processes on the system.




## Table of Contents
- [Learning Objectives](#learning-objectives)
- [Requirements](#requirements)
- [Files and Function descriptions](#files-and-function-descripctions)
- [Usage](#usage)
- [Example of usage](#Example-of-usage)
- [Man or help](#man-or-help)
- [Authors](#authors)
## Learning Objectives

In this project, we learned about:
- The original design and implementation of the Unix operating system
- The creation of the first version of the Unix shell
- The invention of the B programming language and its relationship to C
- The work of **Ken Thompson**
- How a shell works
- The difference between a **function** and a **system call**
- How to **create processes**
- The three **prototypes of main**
- How a shell **uses the `PATH` environment variable** to find programs
- How to execute another program with the `execve`system call
- How to **suspend the execution** of a process until one of its children terminates
- What is `EOF` (end-of-file)
## Requirements
- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on `Ubuntu 20.04` LTS using gcc, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All your header files should be include guarded

## Files and Functions descriptions
### shell.c 
- This is the main function of a Unix command-line program that allows users to execute commands in the terminal. The function defines some variables and starts an infinite loop to read and process user input. Within the loop, the function checks if the input mode is interactive or not, and prints a command prompt if it is. It then reads the user's input using the getline() function and stores it in the variable command.

- The function then performs several checks on the user's input, such as if the user entered "exit" to exit the program or if the input line is empty. If the command is valid, the function uses the strtok_str() function to split the command line into individual arguments, which are stored in the argv array.

- It checks if the first argument is null, and if it is, it frees up resources and continues with the next iteration of the loop. Otherwise, it uses the getenv_str() function to get the system's search path (PATH) and uses the which_str() function to search for the executable file corresponding to the entered command in the argv variable. If an executable file is found, the function uses the execve_str() function to execute the file. If the file is not found, it displays an error message.

- Finally, the function frees up assigned resources and repeats the infinite loop until the user enters "exit" to exit the program.

### main.h
- Header file
### which.c (which_str)
- This function takes a path and an array of arguments as input. It first checks if the argument is already a valid path, and returns it if it is. Otherwise, it tokenizes the PATH environment variable and generates different paths by concatenating each token with the argument. It then checks if each of these paths exists, and returns the full path of the first one it finds. If none of the paths exist, it returns NULL.

### strtok.c (strtok_str)
- This function takes a string as input and tokenizes it by whitespace characters such as space or tab. It returns an array of strings, with each element of the array containing a tokenized part of the input string. The function first counts the number of tokens in the input string and allocates memory for the array of strings. It then uses the strtok function to tokenize the input string and store each token in a separate string in the array. Finally, the function sets the last element of the array to NULL and returns the array.

### getenv.c (getenv_str)
- This function takes an environment variable as input and searches for it in the current environment variables. If it is found, it returns the value of the environment variable as a string. The function searches the environ variable, which is a global variable containing the current environment variables. It uses strncmp to compare the input environment variable with each environment variable in the environ array until it finds a match. If a match is found, the function returns the value of the environment variable as a string. If the function does not find a match, it returns NULL.

### execve.c (execve_str)
- This function forks a new child process and uses the execve system call to execute the command passed as an argument in argv. If the execve system call fails, it prints an error message using perror and exits with status code 1. The parent process waits for the child process to finish using wait. The function returns 0 on success and 1 on failure.
### auxiliar Functions (count_str)
- This function takes a string as input, and it counts the number of space/tab separated tokens in the string. It does this by creating a copy of the input string, and then tokenizing the copy using the strtok function. It iterates over each token and increments the count until there are no more tokens left. Finally, it frees the memory allocated to the copy and returns the count.

### Authors
Name and Email of Authors.




## Usage
 - Clone the repository
**https://github.com/micaelapicco/holbertonschool-simple_shell**
- Change the repository. `
`cd holbertonschool-simple_shell`
- Compilation
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
- Run shell
`./hsh`
- Execute commands 
Now you can put commands and when you want exit of the "hsh" you can put `ctrl+D` or write `exit`.

## Example of usage
### Interactive mode
```
root@07abb08b2192:~/holbertonschool-simple_shell# ./hsh 
$ ls
AUTHORS  README.md shell.c
$ /usr/bin/ls
AUTHORS README.md  shell.c          
$ exit
```

### Non-interactive mode
```
root@07abb08b2192:~/holbertonschool-simple_shell# echo "ls" | ./hsh 
AUTHORS  README.md shell.c
```
## Man or help

- `access` (man 2 access)
- `execve` (man 2 execve)
- `exit` (man 3 exit)
- `fflush` (man 3 fflush)
- `fork` (man 2 fork)
- `free` (man 3 free)
- `getline` (man 3 getline)
- `getpid` (man 2 getpid)
- `isatty` (man 3 isatty)
- `malloc` (man 3 malloc)
- `perror` (man 3 perror)
- `printf` (man 3 printf)
- `strtok` (man 3 strtok)
- `wait` (man 2 wait)
## Authors
This project was created by Holberton School Uruguay students ***Micaela Picco*** *(@micaelapicco)* and ***Vicenzo Anza*** *(@vicenzoanza)*.