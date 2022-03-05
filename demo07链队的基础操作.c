#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 6
typedef int Element;
typedef struct
{
    Element *base;//存储空间的基地址
    int front;//头指针
    int rear;//尾指针
}SqQueue;
//队列的初始化
SqQueue initSq(SqQueue S){
    S.base=(int *)malloc(sizeof(int)*MAXSIZE);
    S.front=S.rear;
    return S;
}
//入队列
SqQueue PushSq(SqQueue S){
    if ((S.rear+1)%MAXSIZE==S.front)
    {
        /* code */
        printf("该队列已满\n");
        return S;
    }
    int e;
    scanf("%d",&e);
    S.base[S.rear]=e;
    S.rear=(S.rear+1)%MAXSIZE;
    return S;
}
//出队
int PopSq(SqQueue S){
    if (S.front==S.rear)
    {
        printf("该队列已空\n");
        return -1;
    }
    int e;
    e=S.base[S.front];
    return e;
    
}
int main(){
    SqQueue S;
    S=initSq(S);
    S=PushSq(S);
    S=PushSq(S);
    S=PushSq(S);
    S=PushSq(S);
    S=PushSq(S);
    S=PushSq(S);
    S=PushSq(S);
    S=PushSq(S);
    S=PushSq(S);
    int e;
    while (S.front!=S.rear)
    {
        e=PopSq(S);
        printf("出队列的元素为%d\n",e);
        S.front=(S.front+1)%MAXSIZE;
    }
    return 0;
}