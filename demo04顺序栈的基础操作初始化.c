#include <stdio.h>
#include <stdlib.h>
//顺序栈的操作 
#define MAXSIZE 8
#define STACKINCREMENT 10
#define OK 1 
#define OVERFLOW -1
#define ERROR 0
typedef int ElemType;
typedef int Status;
//定义类型int 

//顺序栈定义 
typedef struct{
	ElemType *base;//栈底指针 
	ElemType *top;//栈顶指针 
	int stackSize;//栈可用最大容量 
}SqStack;

//初始化
SqStack initStack(SqStack S){
	//为顺序栈动态分配一个最大容量为MAXSIZE 
	S.base=(int *)malloc(MAXSIZE*sizeof(int));
	S.top=S.base;
	S.stackSize=MAXSIZE;
	printf("初始化顺序栈完成\n");
	return S; 
} 
//入栈
SqStack Push(SqStack S){
	ElemType e;
	if(S.top-S.base==S.stackSize){
		printf("该栈已经满了\n") ;
		return S;
	} 
	printf("请输入进栈的元素\n");
	scanf("%d",&e);
	*S.top=e;
	S.top++;
	//*S.top++=e;
	printf("入栈结束-------\n");
	return S;
} 
//出栈
ElemType Pop(SqStack S){
	ElemType e;
	if(S.top==S.base){
		printf("该栈已经空了\n") ;
		return 0;
	} 
	e=*S.top ;
	printf("出栈的该元素为%d\n",e);
	printf("出栈成功\n");
	return e;
} 

int main(){
	SqStack S;
	ElemType e;
	S=initStack(S);
	S=Push(S);
	S=Push(S);
	S=Push(S);
	S=Push(S);
	S=Push(S);
	S=Push(S);
	S=Push(S);
	S=Push(S);
	S=Push(S);
	S=Push(S);
	S=Push(S);

	while(S.base!=S.top){
		S.top--;//先移动
		Pop(S);
	} 
	return 0;
}







