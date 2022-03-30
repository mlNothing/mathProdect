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
void SelectSort(SqList *L){
    int m,i,j,k;
    InfoInsert temp;
    m=L->length;
    for ( i = 0; i < m; i++)
    {
        k=i;
        for ( j = i+1; j < m; j++)
        {
            if (L->R[k].key>L->R[j].key)
            {
                k=j;
            }
        }
        if (k!=i)
        {
                 temp=L->R[i];
                L->R[i]=L->R[k];
                L->R[k]=temp;
        }
        
    }
    
}
int main(){
    SqList L;
    int i,m;
    printf("请输入线性表La的长度：");//9
    scanf("%d", &m);
    L.length = m;
    for ( i = 0; i < m; i++)
    {
        scanf("%d",&L.R[i].key);//0 3 4 1 3 3 5 2 4 
        
    }
    printf("直接选择排序之前");
    ListDisplay(&L);
    SelectSort(&L);
    printf("直接选择排序之后");
    ListDisplay(&L);
    return 0;
}