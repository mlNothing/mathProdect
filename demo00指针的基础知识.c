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
//结构体指针
typedef struct Node  
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}Node;

结构体定义好之后,就要用它来制作新结点了;
有两种方法：
1. Node bt;
2. Node *bt; bt=(Node *) malloc(sizeof(Node)); 先定义一个结点的指针bt,然后用函数malloc申请一个结点的内存空间，然后bt指向这片内存空间;
一般用第二个:
    2中的bt是指针型变量,虽然现在可以指向刚生成的结点,但是以后bt可以离开这个结点转向其他结点。而1就不可以了；
    取分量的操作：
        1.x=bt.data;
        2.x=(*bt).data=bt->data;

关于参数引用类型的例子
void insert (sqlist &L,int x);
    因为L本来需要发生变化,所以要用引用型;L是个结构体,data数组是它的一个分量,属于sqlist的一部分,data改变就是sqlist自身的变量
int search(LNode *C,int x)
    C是指向一个链表表头的指针,它不代表整个链表,其他链表或许会改变,但是c不改变,因此这里传入c的时候不需要引用型。
