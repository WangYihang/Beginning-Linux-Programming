#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024 * 1024
#define TIMES 1024

int main(int argc, char ** argv){
    char * buffer = 0;
    char data[] = "Hello world!\n";
    int i = 0;
    for (i = 0; i < TIMES; i++){
        printf("Allocing %dth memery block...\n", i);
        buffer = (char *)malloc(BLOCK_SIZE);
        strcpy(buffer, data);
        printf("Data : %s", buffer);
    }
    printf("Alloc and copy finished, but the program is still running...");
    getchar();
    return 0;
}
