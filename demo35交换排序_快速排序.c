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
void QuickSort(SqList *L,int low,int high){
        int mid;
        if (low<high)
        {
            mid=Partition(L,low,high);
            QuickSort(L,low,mid-1);
            QuickSort(L,mid+1,high);
        }
}
int Partition(SqList *L,int low,int high){
        L->R[0]=L->R[low];int mid;
        mid=L->R[low].key;
        while (low<high)
        {
            while (low<high && L->R[high].key>=mid)
            {
                high--;
            }
            L->R[low]=L->R[high];
            while (low<high && L->R[low].key<=mid)
            {
                low++;
            }
            L->R[high]=L->R[low];
        }
        L->R[low]=L->R[0];
        return low;
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
    printf("快速排序之前");
    ListDisplay(&L);
    QuickSort(&L,1,m);
    printf("快速排序之后");
    ListDisplay(&L);
    return 0;
}
