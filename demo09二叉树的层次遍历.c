#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 100
typedef struct  BiTNode
{
    char data;
    struct BiTree *lchild,*rchild;
}BiTNode,*BiTree;
typedef struct
{
    BiTree data[MAXSIZE]; //存放队中元素
    int front,rear;  //队头和队尾
}sqQueue;
//创建二叉树
 BiTree createBiTree(BiTree T){
    char ch;
    ch=getchar();
    if (ch=='#')
    {
        T=NULL;
    }else{
        T=(BiTree)malloc(sizeof(BiTNode));
        T->data=ch;
        T->lchild=createBiTree(T->lchild);
        T->rchild=createBiTree(T->rchild);
    }   
    return T; 
}
//中序遍历
void InOrderTransverse(BiTree  T){
    if(T==NULL){
        return;
    }
        InOrderTransverse(T->lchild);
        printf("%c",T->data);
        InOrderTransverse(T->rchild);
        printf("\n");
}
 
//队列初始化
void initSq(sqQueue *S){
    S->front=NULL;
    S->rear=NULL;
}
//进队列
void enQueue(sqQueue *S,BiTree p){
    printf("chuchus.front=%d s.rear==%d\n",S->front,S->rear);
    printf("p的值为%c \n",p->data);
    S->data[++S->rear]=p;
    printf("进队列s.front=%d s.rear==%d\n",S->front,S->rear);

}
//出队列
BiTree deQueue(sqQueue *S){
   return S->data[++S->front];
}
bool QueueEmptry(sqQueue *S){
    if (S->front==S->rear)
    {
        printf("该队列是空\n");
        return true;
    }
    printf("该队列不空\n");
    return false;

}
//层次遍历
void LevelOrder(BiTree T){
    sqQueue S; 
    //初始化队列
    initSq(&S);//如果只是传S的，是在栈区创建的，当方法销毁时，S的指针并不会移动，当传入地址的时候，S的地址才会改变 
    //*p=&S==>P=&S; p指定s的地址 修改p可以直接修改s的值
    enQueue(&S,T);//根结点进入队列
    while (!QueueEmptry(&S))
    {   BiTree P;
        P= deQueue(&S);//出队列结点
        printf("输出队首结点%c \n", P->data);  //输出队首结点
        printf("--------------\n");
        if (P->lchild!='#'&&P->lchild!=NULL)
        {
            printf("开始左结点\n");
            enQueue(&S,P->lchild);
        }
        if (P->rchild!='#'&&P->lchild!=NULL)
        {
                printf("开始右结点\n");
             enQueue(&S,P->rchild);
        }
    }
    
}
int main(){
    BiTree T;
    T=createBiTree(T);
    printf("创建二叉树完成！\n");
    InOrderTransverse(T);
    //输入例子为abd##e##cf##g##
    LevelOrder(T);
    printf("二叉树层次遍历结束\n");
    return 0;
}