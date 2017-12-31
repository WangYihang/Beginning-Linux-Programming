#include <stdio.h>

int main(int argc, char ** argv){
    FILE *input = fopen("/dev/tty", "r");
    FILE *output = fopen("/dev/tty", "w");
    fprintf(output, "This output cannot be redirected!\n");
    printf("Normal output...\n");
    return 0;
}
