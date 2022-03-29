#include<stdio.h>
#define MAXSIZE 10
typedef struct InfoInsert{
    int key;
    int info;
}InfoInsert;
typedef struct SqList{
    InfoInsert R[MAXSIZE+1];
    int length;
}SqList;
void ListDisplay(SqList *L)
{
    int i;
    for (i = 0; i <L->length; i++)
    {
        printf("%d\t", L->R[i]);
    }
    printf("\n");
}
// 冒泡排序
void BobbleSort(SqList *L){
    int m,i,j,flag=1;
    m=L->length-1;
    InfoInsert temp;
    for ( i = 0; i <m&&flag==1; i++)
    {
        flag=0;
        for ( j = 0; j < m-i; j++)
        {
            if (L->R[j].key>L->R[j+1].key)
            {
                flag=1;
                temp=L->R[j];
                L->R[j]=L->R[j+1];
                L->R[j+1]=temp;
            } 
        }
    }
}
int main(){
    SqList L;
    int i,m;
    printf("请输入线性表La的长度：");//5
    scanf("%d", &m);
    L.length = m;
    for ( i = 0; i < m; i++)
    {
        scanf("%d",&L.R[i].key);//2 3 4 1 3
        
    }
    printf("冒泡排序之前");
    ListDisplay(&L);
    BobbleSort(&L);
    printf("冒泡排序之后");
    ListDisplay(&L);
    return 0;
}
