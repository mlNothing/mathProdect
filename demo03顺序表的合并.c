#include <stdio.h>
#include <stdlib.h>
//合并两个顺序表 
#define MAXSIZE 100
//定义类型int 
typedef int ElemType;

//顺序表定义 
typedef struct{
	ElemType *data;//存储空间的基地址 
	int length;
}SqList;

//初始化顺序表
SqList initList(SqList L){
	L.data=(SqList *)malloc(MAXSIZE*sizeof(SqList));
	L.length=0;
	return L; 
} 
//创建顺序表
SqList createList(SqList L){
	ElemType i=0; 
	while(i<6){
		printf("请输入第%d个元素\n",i+1); 
		scanf("%d",&L.data[i]);
		++L.length;
		++i;
	} 
	printf("-----------\n");
    return L; 
} 
//合并顺序表
SqList mergeTwoList(SqList L1,SqList L2){
	SqList L;
	L.data =(SqList *)malloc((L1.length+L2.length)*sizeof(SqList));
	L.length= L1.length+L2.length;
	ElemType *p,*p1,*p2,*plast1,*plast2;
	p=L.data;
	p1=L1.data;
	p2=L2.data;
	plast1=L1.data+L1.length-1;
	plast2=L2.data+L2.length-1;
	//*plast1 是值 plast1 是地址 =&plast1  
	while((p1<=plast1)&&(p2<=plast2)){
		if(*p1<=*p2) *p++=*p1++;
		else *p++=*p2++; 
	}
	while(p1<=plast1)  *p++=*p1++;
	while(p2<=plast2)  *p++=*p2++;
	return L; 
} 
int main(){
	 SqList L1,L2,L;
	 L1=initList(L1);
	 L2=initList(L2);
	 printf("初始化顺序表成功!\n");
	 //插入运算
	  L1=createList(L1);
	  ElemType i=0;
	  for(i=0;i<L1.length;i++){
	  	printf("第%d个元素=%d,",i+1,L1.data[i]);
	  }
	  printf("顺序表1已经创建完成\n");
	  
	  printf("开始创建顺序表2\n");
	  	  L2=createList(L2);
	  for(i=0;i<L2.length;i++){
	  	printf("第%d个元素=%d,",i+1,L2.data[i]);
	  }
	  printf("顺序表2已经创建完成\n");

//	合并顺序表
	L=mergeTwoList(L1,L2);
	 	  for(i=0;i<L.length;i++){
	  	printf("第%d个元素=%d,",i+1,L.data[i]);
	  }
	  printf("顺序表已经合并完成\n");
	return 0;
}