#include <stdio.h>

int main(int argc, char** argv){
    char i = 0;
    while(1){
        printf("Give me your choose : ");
        i = getchar();
        if (i == 'x'){
            printf("Your input : x\n");
            printf("Hello world!\n");
        }else if(i == 'q'){
            printf("Your input : q, quiting...\n");
            break;
        }else{
            printf("Incorrect input : %c\n", i);
        }
    }
    return 0;
}
