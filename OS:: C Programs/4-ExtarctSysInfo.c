/*
C program using ‘gcc’ compiler to extract system information...
Model name, Cache Size, Number of CPU cores, CPU clock speed, Total Memory,
Free Memory, OS Name, OS Version.
*/

#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("---CPU Information---\n");
    system("cat /proc/cpuinfo|grep -m 1 'model name'");
    system("cat /proc/cpuinfo|grep -m 1 'cache size'");
    system("cat /proc/cpuinfo|grep -m 1 'cpu cores'");
    system("cat /proc/cpuinfo|grep -m 1 'cpu MHz'");

    printf("\n---Memory Information---\n");
    system("cat /proc/meminfo|grep 'MemTotal'");
    system("cat /proc/meminfo|grep 'MemFree'");

    printf("\n---Operating Information---\n");
    system("cat /etc/os-release|grep -m 1 'NAME'");
    system("cat /etc/os-release|grep -m 1 'VERSION'");
}

/********************OUTPUT********************
---CPU Information---
model name	: Intel(R) Core(TM) i5-7200U CPU @ 2.50GHz
cache size	: 3072 KB
cpu cores	: 2
cpu MHz		: 2700.000

---Memory Information---
MemTotal:        8007888 kB
MemFree:         3523656 kB

---Operating Information---
NAME="Ubuntu"
VERSION="20.04.3 LTS (Focal Fossa)"
***********************************************/
