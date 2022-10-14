#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h> 
#include <sys/wait.h>

using namespace std;

int main() 
{
    pid_t child_pid;    
    int status;
    pid_t wait_result;
    child_pid = fork();
    
    if (child_pid == 0) 
    { 
        printf ("I am a child and my pid = %d\n", getpid());
        execl("/bin/ls", "ls", "-l", NULL);
        printf ("Could not execl file /bin/ls\n");
        exit(1);
    }
    else if (child_pid > 0) 
    {
        printf ("I am the parent and my pid = %d\n", getpid());
        printf ("My child has pid = %d\n", child_pid);
        printf ("I am a parent and I am going to wait for my child\n");
        do 
        {
            wait_result = wait(&status);
        } while (wait_result != child_pid);
        printf ("I am a parent and I am quitting.\n");
    }
    else 
    {
        printf ("The fork system call failed to create a new process\n");
        exit(1);
    }
    return 0;
}