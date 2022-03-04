#include <stdio.h>
#include <stdlib.h>
//合并两个有序链表 
//将两个非递减的有序链表合并成一个非递增的有序链表，要求结果链表仍使用原来链表的存储空间，不另外占用其他的存储空间，表中允许有重复数据 
//
//定义类型int 
typedef int ElemType;

//链表定义 
typedef struct Node{
	ElemType data;
	struct Node *next;
}Node,*LinkStack;
//初始化
LinkStack initList(LinkStack L){
	L =(LinkStack)malloc(sizeof(Node));//动态创建头结点 
	L->next=NULL;
	printf("初始化成功！\n");
	return L; 
} 
//头插法 
LinkStack headLinkList(LinkStack L){
	ElemType x;
	int i=0;
	while(i<3){
		scanf("%d",&x);
     	LinkStack	p;
      p=(LinkStack)malloc (sizeof(Node));
      p->data=x;
      p->next=L->next;
      L->next=p;
      i++;
	}
	return L;
}
//尾插法 
LinkStack InsertLinkList(LinkStack L){
		ElemType x,i=0;
//		初始化链表
		LinkStack r;//定义尾结点  L指向尾结点 
		r=L;
		while(i<3){
		scanf("%d",&x);
//		创建新节点 
	    LinkStack	p;
        p=(LinkStack)malloc (sizeof(Node));
        p->data=x;
        p->next=NULL;
        r->next=p;
        r=p;
        i++;
	}
	return L;
}
//合并有序链表，使用前插法 
LinkStack mergeTwoLists(LinkStack L1,LinkStack L2){
	//返回新链表 
	LinkStack L;
	L=(LinkStack)malloc(sizeof(Node));
	//使用两个新节点指向L1,L2,防止修改原本的指针的指向
	LinkStack p1,p2,p,q;
	p1=L1->next;
	p2=L2->next; 
	p=L=L1;//用L1的头结点做为L的头结点 
	L->next=NULL;///!!!必须在这个时候进行NULL值设置 
//	只要有一个没到终点即可 
	while(p1||p2){
		//L1表为空，q指向l2,l2指针后移 
			if(!p1){
				q=p2;
				p2=p2->next;
			}			
			else if(!p2){
				q=p1;
				p1=p1->next;
			}
			else if (p1->data<=p2->data){
				q=p1;
				p1=p1->next;
			}else{
				q=p2;
				p2=p2->next;
			} 
			q->next=p->next;
			p->next=q; 
	}
		return L;
}
int main()
{
	//初始化变量 
    LinkStack L1,L2,L;
	printf("请输入L1的元素\n"); 
	L1=InsertLinkList(initList(L1));
	LinkStack one,two,sum;
	for(one=L1->next;one!=NULL;one =one->next){
		printf("%d",one->data);
	}
	printf("\nL1创建完成\n");
	printf("请输入L2的元素\n"); 
	L2=InsertLinkList(initList(L2));
	for(two=L2->next;two!=NULL;two =two->next){
		printf("%d",two->data);
	}
	printf("\nL2创建完成\n");
	L=mergeTwoLists(L1,L2);
	for(sum=L->next;sum!=NULL;sum =sum->next){
		printf("%d",sum->data);
	}
	return 0;
}