/*
C program using ‘gcc’ compiler to extract PID of parent and child processes.
Child process is to be created using fork() system call.
*/

#include<stdio.h>
#include<unistd.h>
int main(){
    int pid = fork();
    if(pid != 0){
        printf("---From parent process---\n");
        printf("Child PID: %d\n", pid);
        printf("Itself(Parent) PID: %d\n", getpid());
    }
    else{
        printf("\n---From child process---\n");
        printf("Parent PID: %d\n", getppid());
        printf("Itself(Child) PID: %d\n", getpid());
    }
}

/********************OUTPUT********************
---From parent process---
Child PID: 12068
Itself(Parent) PID: 12067

---From child process---
Parent PID: 12067
Itself(Child) PID: 12068
***********************************************/
