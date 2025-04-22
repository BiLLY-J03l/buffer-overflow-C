#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void debug() 
{
    printf("!! ENTERING DEBUG MODE !!\n");
    system("/bin/bash");
}

void checkPassword(long long key)
{
    char password[64];

    printf("password: ");
    gets(password);
    
    if (key == 0x100911AFFED){
	    debug();
    }
    else{
	    printf("[x] WRONG HEHEHEHEH...\n");
	    return;
    }

    return;
}

int main(int argc, char **argv)
{
    printf("WELCOME TO THE SECURE PROGRAM\n");	
    checkPassword(0xDEADBEEF0123);
}
