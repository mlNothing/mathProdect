#include<stdio.h>
#include <stdlib.h>
#define NVNum 100 //最大顶点数
typedef char VerTextType; //假设顶点的数据类型为字符型
typedef int ArcType; //假设边的权值类型为整型

typedef struct ArcNode{
    int adjvex;//该边所指向的顶点位置
    struct ArcNode * nextAre;//指向下一条边的指针
    int info;//和边相关的信息
}ArcNode,* AArcNode;//边结点

typedef struct VNode
{
    VerTextType data;
     AArcNode firstarc;//指定第一条依附该顶点的边的指针
}VNode,AdjList[NVNum];//顶点结点 AdjList表示邻接表类型

typedef struct ALGraph
{
    VNode * vertices;
    int vernum,arcnum;//图的当前顶点数和边数
}ALGraph;
//通过连接表表示法,创建无向图
int CreateUDG(ALGraph *G){
    //采用邻接表表示法,创建无向图 输入总顶点数和总边数
    scanf("%d%d",G->arcnum,G->vernum);
    for (int i = 0; i < G->vernum; i++)
    {
        scanf("%d",G->vertices[i].data);//输入顶点值
        G->vertices[i].firstarc=NULL;//初始化表头结点的指针域为null;
    }
    for (int k = 0; k < G->arcnum; k++)
    {
        int v1,v2,i,j;//输入一条边依附的两个顶点
        scanf("%d%d",v1,v2);
        i=localVex(G,v1);
        j=localVex(G,v2);
        ArcNode p1,p2;
        p1=(AArcNode)malloc(ArcNode*NVNum);
        p1.adjvex=j;
        p1.nextAre=G->vertices[i].firstarc;
        G->vertices[i].firstarc=p1;
        p2=(AArcNode)malloc(ArcNode*NVNum);
        p2.adjvex=i;
        p2.nextAre=G->vertices[j].firstarc;
        G->vertices[j].firstarc=p2;
    }
    return 0;
    
}

