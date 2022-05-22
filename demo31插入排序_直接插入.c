#define MAXSIZE 20 //顺序表的最大长度
typedef struct  
{
    int key; //关键子项
    int otherinfo;//其他关键子项
}RedInfo;
typedef struct  
{
    RedInfo R[MAXSIZE+1];//r[0]闲置或用作哨兵
    int length;//顺序表的长度
}SqList;
//初始化线性表
void initSqList(SqList *L)
{
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
// void InsertSort(SqList *L)
// {
//     int i,j;
//     for ( i = 2; i < L->length; i++)
//     {
//         if (L->R[i].key<L->R[i-1].key)
//         {
//              L->R[0].key=L->R[i].key;
//             L->R[i].key=L->R[i-1].key;
//             for ( j = i-2; L->R[0].key<L->R[j].key; --j)
//             {
//                 L->R[j+1]=L->R[j];
//             }
//             L->R[j+1]=L->R[0];
//         }  
//     }
    
// }
void InsertSort(SqList *L)
{
    int i,j;
    for ( i = 2; i < L->length; i++)
    {
        if (L->R[i].key<L->R[i-1].key)
        {
             L->R[0].key=L->R[i].key;
            for ( j = i-1; L->R[0].key<L->R[j].key; --j)
            {
                L->R[j+1]=L->R[j];
            }
            L->R[j+1]=L->R[0];
        }  
    }
    
}
int main()
{
     SqList L;
    //顺序表的初始化
    initSqList(&L);
    int m, n,i;
    printf("请输入线性表La的长度：");//5
    scanf("%d", &m);
    L.length = m;
    printf("请输入线性表La中的元素（共%d个）\n", m);
       for (i = 0; i < m; i++)
    {
        scanf("%d", &L.R[i].key);//0 38 29 39 40
    }
    printf("***  此时线性表La中的元素  ***\n");
    ListDisplay(&L);
    //插入排序--直接插入排序
    InsertSort(&L);
    printf("***  此时线性表La中的元素  ***\n");
    ListDisplay(&L);//29 38 39 40
    return 0;
}
