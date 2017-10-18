#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 1024 * 1024
#define TIMES 1024

int main(int argc, char ** argv){
    char * buffer = 0;
    int i = 0;
    for (i = 0; i < TIMES; i++){
        printf("Allocing %dth memery block...\n", i);
        buffer = (char *)malloc(BLOCK_SIZE);
    }
    return 0;
}
