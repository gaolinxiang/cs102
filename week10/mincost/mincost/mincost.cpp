//
//  main.cpp
//  mincost 最短路-Dijkstra算法-相邻矩阵
//
//  Created by Ge, Xiao on 13/07/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include<iostream>
#define MAXN 2001
#define inf 9999999
using namespace std;
int N,M,A,B;
double m[MAXN][MAXN];   // 相邻矩阵

int main() {
    
    cin>>N>>M;
    for (int i=1;i<=N;i++)
        for (int j=1;j<=N;j++)
            m[i][j]= i==j ? 1 :1/inf;   // 用无穷大表示没有边
    for (int i=0,x,y,t;i<M;i++) {
        cin>>x>>y>>t;
        m[x][y]=m[y][x]=max(m[x][y],1-t/100.0); // 换算费率
    }
    cin>>A>>B;
    
    double d[MAXN]; // 最短路径长度（目标值）
    bool visited[MAXN]={};    // 访问标志（是否已算出最短路）
    for (int i=1;i<=N;i++) d[i]=inf+1; // 初始距离
    d[A]=100.0;
    
    for (int j=1;j<=N;j++){
        int s=0;
        double dmin=inf+1;
        for (int i=1;i<=N;i++){
            if (d[i]<dmin && !visited[i]) { // 选择未算出的顶点中dis最小的
                s=i; dmin=d[i];
            }
        }
        if (s==B) break;
        visited[s]=true; // 该顶点加入已算出集合
        for (int t=1;t<=N;t++){
            if (d[s]/m[s][t]<d[t] && !visited[t]){
                d[t]=d[s]/m[s][t]; // 松弛操作
            }
        }
    }
    
    if (d[B]>=inf){
        cout<<-1<<endl;
    }else{
        cout.precision(8);
        cout<<fixed<<d[B]<<endl;
    }
    return 0;
}

