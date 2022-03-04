#include <stdio.h>
#include <stdlib.h>
//顺序栈的操作 
#define MAXSIZE 100
//定义类型int 
typedef int ElemType;

//顺序栈定义 
typedef struct{
	ElemType *base;//栈底指针 
	ElemType *top;//栈顶指针 
	int stackSize;//栈可用最大容量 
}SqStack;

//初始化
SqStack initStack(SqStack S){
	S.base=(SqStack *)malloc(MAXSIZE*sizeof(SqStack));//为顺序栈动态分配一个最大容量为MAXSIZE 
	S.top=S.base;
	S.stackSize=MAXSIZE;
	return S; 
} 
//入栈
SqStack Push(SqStack S){
	ElemType e;
	if(S.top-S.base==S.stackSize){
		printf("该栈已经满了\n") ;
		return S;
	} 
	printf("请输入进栈的元素/n");
	scanf("%d",&e);
	*S.top=e;
	S.top++;
	return S;
} 
//出栈
ElemType Pop(SqStack S){
	ElemType e;
	if(S.top=S.base){
		printf("该栈已经空了\n") ;
		return 0;
	} 
	e=*S.top ;
	S.top--;
	printf("出栈的该元素为%d\n",e);
	return e;
} 

int main(){
	SqStack S;
	scanf("请输入最大容量%d",S.stackSize);
	S=Push((initStack(S)));
	while(S.base!=S.top){
		Pop(S);
	} 
	return 0;
}