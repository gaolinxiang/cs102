//
//  main.cpp
//  invitation Dijkstra+邻接表+priority_queue
//
//  Created by System Administrator on 2017/7/14.
//  Copyright © 2017年 System Administrator. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <stdio.h>
#define N 100005
using namespace std;
typedef long long LL;

int n,m;
struct edge{
    int s,t,w;
} es[N];    // 边集合

struct point{
    int id;
    LL d;
    bool operator < (point p) const {
        return d>p.d;
    }
};

vector<int> g[N]; // 邻接表，值为边的id

LL spfa(){
    LL d[N];
    int inq[N]={};
    memset(d, 127, sizeof(LL)*N);
    
    stack<int> q;   // 用栈做spfa也可以哦
    q.push(1); inq[1]=1; d[1]=0; // 起点
    
    while (!q.empty()) {
        int u=q.top();
        q.pop(); inq[u]=0;   // 出栈
        for (int i=0;i<g[u].size();i++){ // 遍历e出发的所有边
            if(d[es[g[u][i]].t]>d[u]+es[g[u][i]].w) {
                d[es[g[u][i]].t]=d[u]+es[g[u][i]].w; //松弛
                if(!inq[es[g[u][i]].t]) {    // 如果不在栈中，则入栈
                    q.push(es[g[u][i]].t); inq[es[g[u][i]].t]=1;
                }
            }
        }
    }
    LL sum=0;
    for (int i=2;i<=n;i++) sum+=d[i];
    return sum;
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++) { // 建图
        scanf("%d%d%d",&es[i].s,&es[i].t,&es[i].w);
        g[es[i].s].push_back(i);
    }
    LL ans=spfa();  // 单源最短路
    
    for (int i=1;i<=n;i++)  g[i].clear();
    for (int i=0;i<m;i++) { // 反向边并重新建图
        swap(es[i].s,es[i].t);
        g[es[i].s].push_back(i);
    }
    ans+=spfa();  // 单源最短路
    printf("%lld\n",ans);
    return 0;
}
