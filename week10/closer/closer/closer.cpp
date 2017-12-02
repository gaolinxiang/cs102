//
//  main.cpp
//  closer  SPFA-邻接表
//
//  Created by Ge, Xiao on 13/07/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include<cstdio>
#include<queue>
using namespace std;

const int N=1005,M=10005,INF=0x3f3f3f3f;    // 另一种定义常量的方式

// head和nxt构成邻接表（数组实现版本，nxt其实就是链表指针）
int n,m,d[N],u;
int t[M],w[M]; // 边的信息w为边长，t为每条边的末顶点
int nxt[M],head[N]; // 邻接表，这是一个用数组实现链表的方式，head是头结点，nxt是向后指针
int cnt[N]={},inq[N]; // cnt表示入队次数，inq表示是否在队列中

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1,u;i<=m;i++){
        scanf("%d%d%d",&u,t+i,w+i); // 指针方式数组引用
        nxt[i]=head[u]; head[u]=i; // 从头部插入链表
        w[i]*=-1;   // 取反，因为w表示缩短
    }
    for(int i=2;i<=n;i++)  d[i]=INF; // 初始化距离

    queue<int> q;
    q.push(1); cnt[1]=1; inq[1]=1; // 起点入队
    
    while (!q.empty()) {
        u=q.front(),q.pop(),inq[u]=0;   // 出队
        if(cnt[u]>=n){  // 重复入队超过n次，说明有负权回路
            printf("Forever love\n");
            return 0;
        }
        for (int e=head[u];e;e=nxt[e]){ // 遍历e出发的所有边
            if(d[t[e]]>d[u]+w[e]) {
                d[t[e]]=d[u]+w[e]; // 松弛
                if(!inq[t[e]]) {    // 如果不在队列中，则入队
                    q.push(t[e]); cnt[t[e]]+=1; inq[t[e]]=1;
                }
            }
        }
    }

    printf("%d\n",d[n]);
    return 0;
}
