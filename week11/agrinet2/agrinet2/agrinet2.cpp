//
//  main.cpp
//  agrinet2 MST-Prim算法+邻接表
//
//  Created by Ge, Xiao on 13/07/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#define N 105
int n,visited[N*N]={0,1},tot=0,x;
struct edge {   // 边类型
    int s; int t; int w;
    bool operator < (edge e) const { return w>e.w; }   // 操作符重载
};
vector<edge> es[N];  // 邻接表的vector方式实现

int main() {
    cin>>n;
    for(int i=0;i<n;i++){   // 建图
        for(int j=0;j<n;j++){
            cin>>x;
            if(x!=0) es[i].push_back((edge){i,j,x});
        }
    }
    priority_queue<edge> heap;  // 边优先队列（只存至少有一端在ST中的边）
//    for (edge e:es[1]) heap.push(e);  // foreach语法（快快上不能用~）
    for (int i=0;i<es[1].size();i++) heap.push(es[1][i]);   // 初始为起点出发的边

    for(int k=0;k<n-1 && !heap.empty();) {  // k为当前生成树的边数
        edge e=heap.top();
        heap.pop();
        if(!visited[e.t]) {    // 另一头不在ST中，添加到ST
//            tot+=e.w;
            tot=max(tot,e.w);  // 更新边长
            visited[e.t]=1; // 加入这条边
            k++;
//            for (edge e2:es[e.t]) heap.push(e2);
            // 对点相关的边加入优先队列
            for (int i=0;i<es[e.t].size();i++) heap.push(es[e.t][i]);
        }
    }
    cout<<tot<<endl;
    return 0;
}
