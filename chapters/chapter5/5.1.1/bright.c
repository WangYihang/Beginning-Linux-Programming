#include <stdio.h>
#include <unistd.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2

int main(int argc, char ** argv){
    char redirect[] = "Redirection!\n";
    if(!isatty(STDOUT)){
        write(STDERR, redirect, sizeof(redirect));
    }
    printf("Hello world!\n");
    return 0;
}
