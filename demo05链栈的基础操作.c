#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node,*LinkStack;

//初始化
LinkStack initLink(LinkStack S){
        // S=(LinkStack)malloc(sizeof(Node));

    S=NULL;
    return S;
}
//入栈
LinkStack pushLink(LinkStack S){
    ElemType e;
    LinkStack p;
    scanf("%d",&e);
    p=(LinkStack)malloc(sizeof(Node));
    p->data=e;
    p->next=S;
    S=p;
    return S;
}
//出栈
ElemType PopStack(LinkStack S){
    ElemType e;
    e=S->data;
    return e;
}
int main(){
    LinkStack S;
    S=initLink(S);
    S=pushLink(S);    
    S=pushLink(S);
    S=pushLink(S);
    S=pushLink(S);
    S=pushLink(S);
    S=pushLink(S);
    S=pushLink(S);
    S=pushLink(S);
    S=pushLink(S);
    S=pushLink(S);

    int e;
    while (S!=NULL)
    {
            e=PopStack(S);
            printf("出栈的元素为%d\n",e);
           S=S->next;
    }
    
}