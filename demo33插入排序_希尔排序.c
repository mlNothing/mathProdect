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
//第一个元素不作数 传入0 只是过渡使用
void ListDisplay(SqList *L)
{
    int i;
    for (i = 1; i < 11; i++)
    {
        printf("%d\t", L->R[i]);
    }
    printf("\n");
}
//归并排序
void ShellSort(SqList *L,int dt[],int t){
    for (int i = 0; i < t; i++)
    {   printf("第%d次进行排序 \n",i);
        ShellInsert(L,dt[i]);
    }
}
//对顺序表做一次增量进行排序
void ShellInsert(SqList *L,int dk){
    for (int i = dk+1; i <= 11; i=i+dk)
    {
        if (L->R[i].key<L->R[i-dk].key)
        {   int j=0;
            L->R[0]=L->R[i];
            for (j = i-dk; L->R[0].key< L->R[j].key; j=j-dk)
            {
                L->R[j+dk]=L->R[j];
            }
            L->R[j+dk]=L->R[0];
        }
    }
}
int main(){
    SqList L;
    int num,i,j,t=0;//num :元素的个数 t 希尔排序的t趟
    printf("请输入需要排序元素的个数\n");
    scanf("%d",&num);
    L.length=num;
    printf("请输入元素\n");//11
    for ( i = 0; i < num; i++)
    {
        scanf("%d", &L.R[i].key);//0 49 38 65 97 76 13 27 49 55 04 
    }
    ListDisplay(&L);
    //归并排序
    printf("请输入增量的数\n");
    scanf("%d",&t);
    int dt[3]={5,3,1};
    ShellSort(&L,dt,t);
    //再次展示
    ListDisplay(&L);
    return 0;
}

