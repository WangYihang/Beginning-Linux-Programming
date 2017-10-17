# Chapter5 : 终端

##### 5.1 对终端进行读写

```c
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
```

```c
#include <stdio.h>

int main(int argc, char** argv){
    char i = 0;
    while(1){
        printf("Give me your choose : ");
        // 将缓冲区中多余的 \n 清空
        // c 标准中并没有定义类似 : fflush(stdin); 这样用于清空缓冲区的做法
        while(1){
            i = getchar();
            if(i != '\n'){
                break;
            }
        }
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
```

```
all:incorrect correct
incorrect:incorrect.c
	gcc -o incorrect incorrect.c
correct:correct.c
	gcc -o correct correct.c
clean:
	rm -rf incorrect
	rm -rf correct
```





