#ifndef PIPEX_H
#define PIPEX_H

// Standard Libraries
#include <stdio.h>     // For printf, perror, etc.
#include <stdlib.h>    // For malloc, free, exit, etc.
#include <unistd.h>    // For fork, pipe, execve, dup2, etc.
#include <fcntl.h>     // For open, O_RDONLY, O_WRONLY, etc.
#include <sys/wait.h>  // For wait, waitpid
#include <string.h>    // For strer
#include <sys/stat.h>

#define BUFFER_SIZE 1024

#endif  // PIPEX_H

