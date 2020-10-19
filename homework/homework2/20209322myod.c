#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define BUFFERSIZE 1000
void Change(int LJ,int tx[],char tx2[]);
void dToH(int H,int tx[]);
char intToChar(int t);
int count(int *tSY,int *Dan,int *LJ,int *SY,int *num);
void outputAscii(char tx2[],int Dan,int LJ,int tx[],char str[]);
void main(int argc,char *argv[])
{
    char str[BUFFERSIZE];
    int num,i,j,i2;
    int fd;
    for(num=0; num<strlen(str); num++)str[num] = '0';
    num = 0;
 
    if ( (fd = open(argv[1], O_RDONLY)) == -1 )
        {
                perror(argv[1]);
                exit(1);
        }
    num = read(fd, str, BUFFERSIZE);
    close(fd);
    int LJ;
    int SY;
    int tx[8];
    char tx2[8];
    int tSY,Dan;
    for(LJ = 0,SY = num;;)
    {
 
        for(j=0; j<8; j++)tx[j] = 0;
        Change(LJ,tx,tx2);
        for(j=0; j<8; j++)
        {
            printf("%c",tx2[j]);
        }
        printf(" ");
 
//累计字符输出完毕
 
 
 
        tSY = SY;
        if(tSY>=16)
        {
            Dan = 16;
        }
        else
        {
            Dan = tSY;
        }
        for(j=LJ; j<Dan+LJ; j++)
        {
            if(str[j]=='\n')
            {
                printf("\\n  ");
            }
            else
            {
                printf("%c \t",str[j]);
            }
        }
        printf("\n");
 
//输出文本
        outputAscii(tx2,Dan,LJ,tx,str);
 
        if(2==count(&tSY,&Dan,&LJ,&SY,&num))exit(0);
    }
}
void Change(int LJ,int tx[],char tx2[])
 
{
    dToH(LJ,tx);
    int i;
    for(i=0; i<8; i++)
    {
        tx2[i] = intToChar(tx[i]);
    }
}
void dToH(int H,int tx[])//十进制转十六进制，但此时仍用int存储
{
    if(H>536870911)
    {
        printf("字符数太大，超出限制\n");
        exit (0);
    }
    int i=7;
    for(; i>0;)
    {
        tx[i] = H%16;
        H = H/16;
        i--;
    }
}
char intToChar(int t)//十六进制，把int[]转为char[]
{
    if((t>=0)&&(t<10))
    {
        return t+48;
    }
    else
    {
        return t+87;
    }
}
int count(int *tSY,int *Dan,int *LJ,int *SY,int *num)//计数并判定是否终止
{
    *tSY = *tSY-*Dan;
    printf("\n");
    if(*SY>=16)
    {
        *LJ = *LJ+16;
    }
    else if((*SY>0)&&(*SY<16))
    {
        *LJ = *LJ+*SY;
    }
    else if(*SY==0)
    {
        return 2;
    }
    *SY = *num-*LJ;
    return 1;
}
void outputAscii(char tx2[],int Dan,int LJ,int tx[],char str[])
{
        int tt,j,i2;
        printf("         ");
        for(j=LJ; j<Dan+LJ; j++)
        {
            tt = str[j];
            Change(tt,tx,tx2);
            for(i2=0; i2<8; i2++)
            {
                if(tx2[i2]!='0')break;
            }
            for(;i2<8;i2++)printf("%c",tx2[i2]);
            printf("  \t");
        }
        printf("\n");
}
