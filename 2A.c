#include<syscall.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

char buf[1024];

int main(int argc, char** argv)
{
    int src, dst, amount;
    src = open("file1.txt",O_RDONLY);
    if (src==-1)
    {
        printf("Unable to open filess\n");
        return 1;
    }
    dst = open("file2.txt",O_RDWR);
    if (dst==-1)
    {
        printf("Unable to open files\n");
        return 1;
    }
    while ((amount = read(src,buf,1024))>0)
    {
        write(dst, buf, amount);
        printf("The contents being copied are \n");
        printf(buf);
    }
    close(src);
    close(dst);
    return 0;
}
