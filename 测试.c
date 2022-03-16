#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE]; //存放队中元素
    int front,rear;  //队头和队尾
}sqQueue;
void initSQ(sqQueue *S){
    printf("s.front=%d s.rear==%d\n",S->front,S->rear);
    S->front=NULL;
    S->rear=NULL;
    printf("s.front=%d s.rear==%d\n",S->front,S->rear);
    printf("初始化成功\n");
}
void pushSQ(sqQueue *S){
    printf("请输入进入队列的元素\n");
    ElemType a;
    scanf("%d",&a);
    S->data[S->rear]=a;
    S->rear++;
    printf("s.front=%d s.rear==%d\n",S->front,S->rear);
}
void popSQ(sqQueue *S)
{
    ElemType a;
    a=S->data[S->front];
    printf("出队的元素为%d\n",a);
    S->front++;
}
int isqueueempty(sqQueue *S)
{
    printf("qu.front=%d qu.rear==%d\n",S->front,S->rear);
	if(S->front==S->rear)
		return 1;
	else
		return 0;
}
int main(){
    sqQueue S;
    initSQ(&S);
    pushSQ(&S);
    pushSQ(&S);
    pushSQ(&S);
    pushSQ(&S);
    pushSQ(&S);
    while (isqueueempty(&S)==0)
    {
       popSQ(&S);
    }
    return 0;
}