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
    L->R[0].key=i;
    int j;
    for (j = L->length-1; L->R[j].key!=i; j--);
    if (j==0)
    {
        printf("该元素没有");
    }else printf("该元素的位置为%d\n",j);
    
    
}
int main(){
      //顺序表的初始化
     SqList L;
    int i,m;
    printf("请输入线性表La的长度：");//5
    scanf("%d", &m);
    L.length = m;
    for ( i = 0; i < m; i++)
    {
        scanf("%d",&L.R[i].key);//0 38 23 2 39 3 
        
    }
    printf("查找之前");
    ListDisplay(&L);
    search_SQ(&L,38);
    return 0;
}