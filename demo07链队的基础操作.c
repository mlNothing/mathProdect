#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 6
typedef int Element;
typedef struct Node{
    Element data;
    struct Node *next
}Node,*QueuePtr;
typedef struct {
    QueuePtr front; //队头指针
    QueuePtr near;//队尾指针
}LinkQueue;
//初始化
LinkQueue initQueue(LinkQueue Q){
    Q.front=Q.near=(QueuePtr)malloc(sizeof(Node));//生成新结点作为头结点，队头和队尾指针指向此结点
    Q.front->next=NULL;//头结点的指针域置空
    printf("初始化成功\n");
    return Q;
}
//进队列
LinkQueue PushQueue(LinkQueue Q){
    Element e;
    QueuePtr p;
    p=(QueuePtr)malloc(sizeof(Node));
    printf("请输入要进队列的元素\n");
    scanf("%d",&e);
    p->data=e;
    p->next=NULL;
    Q.near->next=p;
    Q.near=p;
    return Q;
}
//出队列
Element PopQueue(LinkQueue Q){
    Element e;
    QueuePtr p;
    if ( Q.near==Q.front)
    {
        Q.near=Q.front;
        printf("该队列为空\n");
        return -1;
    }
    p=Q.front->next;//p指向队头元素
    e=p->data;
    Q.front->next=p->next;//修改头结点的指针域
    if (Q.near==p)
    {
        Q.near=Q.front;//最后一个元素被删，队尾指针指向头结点
        printf("最后一个元素已经出来，该队列为空\n");
    }
    free(p);
    return e;
}
int main(){
    LinkQueue Q;
    Q=initQueue(Q);
    Q=PushQueue(Q);
    Q=PushQueue(Q);
    Q=PushQueue(Q);
    Q=PushQueue(Q);
    Q=PushQueue(Q);
    Q=PushQueue(Q);
    Q=PushQueue(Q);
    Q=PushQueue(Q);
    Element e;
    while (Q.near!=Q.front)
    {
       e= PopQueue(Q);
       printf("出队列的元素为%d\n",e);
    }
    
    return 0;
}