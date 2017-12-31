#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>


int main(int argc, char ** argv){
    int fd = socket(AF_UNIX, SOCK_STREAM, 0);
    struct sockaddr_un address;
    // address.family = AF_UNIX;




    return 0;
}
