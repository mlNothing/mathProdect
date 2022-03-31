#include<stdio.h>
#define MAXSIZE 10
typedef struct SqList{
    int R[MAXSIZE+1];
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
void MergeOne(int R[],int T[],int low,int mid,int high){
    //将有序表low-mid 与mid+1...high加入到T
    int i,j,k;
    i=low;     
    j=mid+1;
    k=low;//T中的起点
    while (i<=mid && j<=high)
    {
        if (R[i]<=R[j]) T[k++]=R[i++];
        else    T[k++]=R[j++];        
    }
    while (i<=mid)  T[k++]=R[i++];
    while (j<=high) T[k++]=R[j++];
}
void  MSort(int R[],int T[],int low,int high){
    int mid;//T是最后排序好的元素
    int S[MAXSIZE+1];
    if (low==high)  T[low]=R[low];//只有一个元素
    else{
        mid=(low+high)/2;//找出中间值
        MSort(R,S,low,mid);//运用递归 对子序列R[low...mid]递归放入S[low...mid]
        MSort(R,S,mid+1,high);
        MergeOne(S,T,low,mid,high);//将有序表S low-mid 与mid+1...high加入到T
    }
}
void MergeSort(SqList *L){
    MSort(L->R,L->R,0,L->length-1);
}
int main(){
    SqList L;
    int i,m;
    printf("请输入线性表La的长度:");//9
    scanf("%d", &m);
    L.length = m;
    for ( i = 0; i < m; i++)
    {
        scanf("%d",&L.R[i]);//0 49 38 65 97 76 13 27 49
    }
    printf("归并排序之前\n");
    ListDisplay(&L);
    MergeSort(&L);
    printf("归并排序之后\n");
    ListDisplay(&L);
    return 0;
}