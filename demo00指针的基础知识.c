#include <stdio.h>
int main(){
    int a=0;
    printf("a=%d,&a=%d\n",a,&a);
    int *b;
    b=&a;
    printf("b=%d,&b=%d,*b=%d\n",b,&b,*b);
    *b=9;
    printf("b=%d,&b=%d,*b=%d,a=%d,&a=%d\n",b,&b,*b,a,&a);
    return 0;
}