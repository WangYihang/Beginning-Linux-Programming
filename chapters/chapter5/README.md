# Chapter5 : 终端

---

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

标准模式和非标准模式 :

* 标准模式 : 行缓冲模式 , 例如用户输入 x\n , 然后字符 x 会被 getchar\(\) 函数接收 , 但是 \n 依然留存在缓冲区中
* 非标准模式 : 更为灵活 , 将会在后面的章节中详细讲解

---

##### 5.2 处理重定向输出

如何判断程序的标准输出是否被重定向 ?

利用函数 :

```c
#include <unistd.h>

int isatty(int fd);
```

```c
#include <stdio.h>

int main(int argc, char ** argv){
    printf("Hello world!\n");
    return 0;
}
```

```c
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
```

```
all:bind bright
bright:bright.c
    gcc -o bright bright.c
bind:bind.c
    gcc -o bind bind.c
clean:
    rm -rf ./bind
    rm -rf ./bright
```



