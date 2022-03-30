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
void HeapAdjust(SqList *L,int i,int n){
    //假设L.R[i+1...n]已经是堆，将L.R[i...n]调整以L.R[i]为根的小根堆
    InfoInsert rc;
    rc=L->R[i];
    for (int j = 2*i; j<=n; j*=2)
    {
        printf("i=%d j=%d\n",i,j);
        printf("L->R[j].key=%d L->R[j+1].key=%d\n",L->R[j].key,L->R[j+1].key);
        if (j<n && L->R[j].key<L->R[j+1].key)//找出j为孩子结点较大的那个
        {
            ++j;
            printf("1111\n");
        }
        if (L->R[j].key<=rc.key)//孩子结点比父节点小，则结束本次循环
        {
            printf("22222   %d\n",j);
            break;//
        }
        printf("交换位置开始\n");
        L->R[i]=L->R[j];i=j;//交换位置
    }
    L->R[i]=rc;
    ListDisplay(L);
}
void CreateHeap(SqList *L){
    int n;
    n=L->length;
    for (int i = n/2; i >=1; i--)//从最后一个非叶子结点开始调整
    {
        printf("第%d\n",i);
        HeapAdjust(L,i,n);
    }
}

void heapSort(SqList *L){
    CreateHeap(L);
    InfoInsert temp;
    int n=0;
    n=L->length;
    printf("\n\\\\\\\n");
    ListDisplay(L);
    for (int i = n-1; i>1; i--)
    {
        temp=L->R[1];
        L->R[1]=L->R[i];
        L->R[i]=temp;
        HeapAdjust(L,1,i-1);
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
        scanf("%d",&L.R[i].key);//0 49 38 65 97 76 13 27 49
    }
    printf("堆排序之前");
    ListDisplay(&L);
    heapSort(&L);
    printf("堆排序之后");
    ListDisplay(&L);
    return 0;
}