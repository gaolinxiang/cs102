//
//  main.cpp
//  speed-byd-并查集
//
//  Created by gexiao on 28/08/2017.
//  Copyright © 2017 gexiao. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define N 100005
using namespace std;

struct edge{    // 边
    int u,v,l,r;
    bool operator < (const edge &e) const {return r<e.r;}
} es[N];

struct vertex{  // 顶点
    int parent,cnt;
} vs[N];

struct question {
    int id,s;
    bool operator < (const question &q) const {return s<q.s;}
} qs[N];

int n,m,answer[N];

int find (int x) {
//    return x==es[x].parent ? x: es[x].parent=find(es[x].parent);
    return x==vs[x].parent ? x: vs[x].parent=find(vs[x].parent);
}

void unite(int x,int y) {
    x=find(x); y=find(y);
    vs[x].parent=y; vs[y].cnt+=vs[x].cnt; vs[x].cnt=0;
}

int main (){
//    freopen("/Users/gexiao/Documents/fudan-course/speed.in","r", stdin);
    cin>>n>>m;
    for (int i=1;i<=n-1;++i) {
        cin>>es[i].r;
        es[i].u=i; es[i].v=i+1; es[i].l=1;
    }
    for (int i=1;i<=m;++i) { // 问询
        cin>>qs[i].s; qs[i].id=i;
    }
    for (int i=1;i<=n;++i) {
        vs[i].cnt=1; vs[i].parent=i;
    }

    sort(es+1,es+n);    // 按速度排序
    sort(qs+1,qs+m+1);

    for (int i=m,pos1=n,pos2,ans=-1;i>=1;--i,pos1=pos2) {
        for (pos2=pos1; pos2>1 && es[pos2-1].r>=qs[i].s;pos2--);    // 新加入的边范围
        for (int j=pos1-1;j>=pos2;--j) {
            unite(es[j].u,es[j].v); // 合并
            ans=max(ans,vs[find(es[j].u)].cnt); // 更新最大块
        }
        answer[qs[i].id]=ans-1;
    }
    for (int i=1;i<=m;++i) cout<<max(answer[i],0)<<" ";
    cout<<endl;
    return 0;
}

