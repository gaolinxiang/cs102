//
//  main.cpp
//  agrinet MST-Kruskal算法+并查集
//
//  Created by Ge, Xiao on 13/07/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 105

using namespace std;

int n,p[N],tot=0,m=0,x;   // p为顶点连通性的（并查集）
struct edge {   // 边类型
    int s,t,w;
}e[N*N];    // 邻接表

int cmp(const edge &e1,const edge &e2) { return e1.w<e2.w; } // 比较器

int findLeader(int x) {
    if (p[x]!=x) p[x]=findLeader(p[x]); // 路径压缩
    return p[x];
}

int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>x;
            if(x!=0) {
                e[++m].s=i, e[m].t=j; e[m].w=x;
            }
        }
    }
    for(int i=1;i<=n;i++)  p[i]=i;  // 初始时所有顶点都是连通分支

    sort(e+1,e+m+1,cmp);  // 排序所有边
    for(int i=1,k=0;k<n-1;i++) { // 从短到长遍历所有边
        int la=findLeader(e[i].s);
        int lb=findLeader(e[i].t);
        if(la!=lb) {    // 属于不同连通分支，添加到ST
            p[la]=lb; // 合并连通分支
            tot+=e[i].w;  // 累加边长
            k++;
        }
    }
    cout<<tot<<endl;
    return 0;
}
