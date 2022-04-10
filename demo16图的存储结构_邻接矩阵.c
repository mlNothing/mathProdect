#include<stdio.h>
#define MaxInt 32767 //表示极大值，即无穷
#define MVNum 100 //最大顶点事
typedef char VerTextType; //假设顶点的数据类型为字符型
typedef int ArcType; //假设边的权值类型为整形
typedef struct 
{
    VerTextType ver[MVNum];//顶点表
    ArcType arc[MVNum][MVNum];//邻接矩阵
    int vexnum,arcnum;//图的当前顶点数和边数
}AMGraph,*AAMGraph;
//使用邻接矩阵表示法创建无向网
int CreateUDN(AAMGraph G){
    printf("请输入总顶点数\n"); 
    scanf("%d",G.vexnum);
    printf("请输入总边数\n");
    scanf("%d",G.arcnum);
    for (int i = 0; i < G.vexnum; i++)
    {   //依次输入点的信息
        scanf("%d",G.ver[i]);
    }
    for (int i = 0; i < G.vexnum; i++)
    {   //初始化邻接矩阵，边的权值，均为最大值MaxInt
        for (int j = 0; j <G.vexnum; j++)
        {
            G.arc[i][j]=0;
        }
    }
    for (int k = 0; k < G.arcnum; k++)
    {
        int v1,v2;
        scanf("%d%d",v1,v2);
        i=LocateVex(G,v1);
        j=LocateVex(G,v2);
        G.arc[i][j]=1;//边v1和v2的权值置为1
        G.arc[j][i]=G.arc[i][j];
    }
    return 0;
}
