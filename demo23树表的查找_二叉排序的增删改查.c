#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20 //顺序表的最大长度
typedef struct  BiTNode
{
    int data;
    struct BiTree *lchild,*rchild;
}BiTNode,*BiTree;
void insertBiTree(BiTree *L,int i){
    if (!(*L)){  
            (*L)=(BiTree )malloc(sizeof(BiTNode)); 
            (*L)->data=i;
            (*L)->lchild=(*L)->rchild=NULL;
        }else{
                if ((*L)->data>i)
                {
                    insertBiTree((&(*L)->lchild),i);
                }else{
                    insertBiTree(&((*L)->rchild),i);
                }
            } 
}
BiTree search_BT(BiTree L,int i){
    if (!L||L->data==i)
    {
        return L;
    }else if(i<L->data) return search_BT(L->lchild,i);
    else return search_BT(L->rchild,i);
    
}
void createBiTree(BiTree L){
    int m;
    L=NULL;
    printf("请输入元素\n");
    scanf("%d",&m);
    while (m!=0)
    {    
         insertBiTree(&L,m);
         printf("请输入count元素\n");// 9 3 2 4 5 2
         scanf("%d",&m);
    }
        //查看遍历
         frontOrder(L);
         //查询
         BiTree k=0;
         k=search_BT(L,5);
         printf("是否查找成功呢?\n");
        printf("是的  \n%d",k->data);//如果是5则证明查找成功否则不是
         

}

//遍历二叉树前序
void frontOrder(BiTree L){
    if (L)
    {   
        printf("%d",L->data);
        frontOrder(L->lchild);
        frontOrder(L->rchild);
    }
}
int main(){
      //顺序表的初始化
     BiTree L;
     createBiTree(L);
    return 0;
}