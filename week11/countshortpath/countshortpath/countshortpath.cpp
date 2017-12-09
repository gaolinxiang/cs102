//
//  main.cpp
//  countshortpath
//
//  Created by gexiao on 20/07/2017.
//  Copyright © 2017 gexiao. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <cstring>

using namespace std;
int m,n,st,ed;
const int N=1000010,M=2000010,MOD=100003;

struct edge {   // struct链表
    int to,val,next;    // next是指向edge的后向指针
} G[2*M];
int head[N],tot=0;    // head与G构成邻接表

int f[N];    // 最短路计数
struct node{    // 顶点类型
    int i,di;
};
bool operator <(node a,node b){ // 操作符重载
    return a.di>b.di;
}

void add_oriented_edge(int start,int end,int weight){ // 邻接表增加有向边
    G[tot].to=end;
    G[tot].val=weight;
    G[tot].next=head[start];
    head[start]=tot++;
}

void add_edge(int node1,int node2,int weight){ // 邻接表增加无向边
    add_oriented_edge(node1,node2,weight);
    add_oriented_edge(node2,node1,weight);
}

void dijkstra(int o){   // dijkstra+优先队列
    int dis[N];
    memset(dis,0x7f,sizeof(dis));   // 填充INF（为啥不是0xff？）
    memset(f,0,sizeof(f));  // 填充0
    
    priority_queue<node>q;
    q.push((node){st,0});
    
    dis[o]=0; f[o]=1;
    for(;!q.empty();){
        node now=q.top(); q.pop();    // 这里用堆优化选择dis最小的
        if(dis[now.i]!=now.di) continue;    // 这句实现了visited功能（想一想为什么）
        for(int i=head[now.i];i!=-1;i=G[i].next){   // 遍历出边
            int v=G[i].to;
            if(now.di+G[i].val==dis[v]){ // 通过tmp点访问v点刚好是最短路，累加路径条数
                f[v]=(f[now.i]+f[v])%MOD;
            } else if(now.di+G[i].val<dis[v]){ // 更新了到v的最短路并重新计数
                dis[v]=now.di+G[i].val;
                f[v]=f[now.i];
                q.push((node){v,dis[v]});
            }
        }
    }
}

int main(){
    int x,y;
    memset(head,-1,sizeof(head));   // -1为啥可以？
    scanf("%d%d",&n,&m); //输入
    st=1;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        add_edge(x,y,1); // 无权图？把边权全部设为1就不用改了
    }
    
    dijkstra(st);
    for(int i=1;i<n;i++) printf("%d ",f[i]);
    printf("%d\n",f[n]);
    return 0;
}
