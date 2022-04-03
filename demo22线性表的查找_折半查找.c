#define MAXSIZE 20 //顺序表的最大长度
typedef struct  
{
    int key; //关键子项
    int otherinfo;//其他关键子项
}EleType;
typedef struct  
{
    EleType R[MAXSIZE+1];//r[0]闲置或用作哨兵
    int length;//顺序表的长度
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
void search_SQ(SqList *L,int i){
    //设置监视哨
    int low =0 ,high=L->length-1,mid=-1;
    while(low<=high)
    {
        mid=(low+high+1)/2;
        if (L->R[mid].key<i)
        {
            high=mid-1;
        }if (L->R[mid].key>i)
        {
            low=mid+1;
        }
        else{
                printf("该值的位置为%d",mid);
                return;
            };
    }
    printf("找不到该元素\n");
    return ;
}
int main(){
      //顺序表的初始化
     SqList L;
    int i,m;
    printf("请输入线性表La的长度：");//6
    scanf("%d", &m);
    L.length = m;
    for ( i = 0; i < m; i++)
    {
        scanf("%d",&L.R[i].key);//0 2 3 4 6 7
        
    }
    printf("查找之前");
    ListDisplay(&L);
    search_SQ(&L,3);
    return 0;
}