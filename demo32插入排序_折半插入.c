#include <stdio.h>
#define MAXSIZE 10
typedef struct 
{
    int key;//关键值
    int info;//其他类行
}InfoInsert;
typedef struct 
{
    InfoInsert R[MAXSIZE+1];
    int length;
}SqList;
void initSqList(SqList *L){
    L->length=0;
}
//第一个元素不作数 传入0 只是过渡使用
void ListDisplay(SqList *L)
{
    int i;
    for (i = 1; i < L->length; i++)
    {
        printf("%d\t", L->R[i]);
    }
    printf("\n");
}
//折半插入
void InsertOrder(SqList *L)
{
    int i,low,high,mid;
    for ( i = 2; i <= L->length; ++i)
    {
        L->R[0]=L->R[i];
        low=1;high=i-1;
        while (low<=high)
        {
            mid=(low+high)/2;
            if (L->R[0].key<L->R[mid].key)
            {
                high=mid-1;
            }else low=mid+1;
        }
        int j;
        for ( j = i-1; j>=high+1; --j)
        {
            L->R[j+1]=L->R[j];
        }
        L->R[high+1]=L->R[0];
    }
    
}
int main(){
    SqList L;
    initSqList(&L);
    int i,m;
    printf("请输入线性表La的长度：");//5
    scanf("%d", &m);
    L.length = m;
    for ( i = 0; i < m; i++)
    {
        scanf("%d",&L.R[i].key);
        
    }
    printf("折半插入排序之前");
    ListDisplay(&L);
    InsertOrder(&L);
    printf("折半插入排序之后");
    ListDisplay(&L);

    return 0;
}

