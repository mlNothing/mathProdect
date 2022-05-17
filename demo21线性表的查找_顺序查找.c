#include <stdio.h>
#define MaxSize 100
typedef struct
{
    int key;   //关键子项
    int other; //其他子项
} elementType;
typedef struct
{
    elementType *p;
    int length; //顺序表的长度
} sqList;
void initSqlist(sqList s, int one)
{
    printf("请依次输入%d个元素的值", one);
    for (int i = 0; i < one; i++)
    {
        scanf("%d", &s.p[i].key);
    }
}
void displaySqlist(sqList s)
{
    for (int i = 0; i < s.length; i++)
    {
        printf("第%d元素的值为%d\n", i, s.p[i].key);
    }
}
void search_Sq(sqList s, int one)
{
    for (int i = s.length - 1; i >= 0; i--)
    {
        if (one == s.p[i].key)
        {
            printf("找到了,i=%d\n", i);
            return;
        }
    }
    printf("没找到\n");
    return;
}
void search_Seq(sqList s, int one)
{
    s.p[-1].key = one;
    int i = -1;
    for (i = s.length; i >= 0 && s.p[i].key != one; i--)
        ;
    printf("如果i!=-1就找到了i=%d", i);
    return;
}
void main()
{
    sqList s;
    printf("请输入线性表的长度\n");
    scanf("%d", &s.length);
    //进行初始化
    initSqlist(s, s.length);
    displaySqlist(s);
    //从后往前的顺序查找
    search_Sq(s, 5);  //不设置监视哨
    search_Seq(s, 5); //设置监视哨
}
