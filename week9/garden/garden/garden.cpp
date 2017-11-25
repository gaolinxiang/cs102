//
//  main.cpp
//  garden 状态压缩DP+矩阵加速
//
//  Created by gexiao on 28/07/2017.
//  Copyright © 2017 gexiao. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#define LL long long
#define MOD 1000000007
using namespace std;

LL **a,**v,n,ans;
bool ok[64];
int m,k,b[6]; // b为6位01状态（dfs穷举用）

void generateMatrixV(int len,int b){    // DFS生成转移矩阵
    if(len==m+1){  // 边界
        int x=b&((1<<m)-1),y=b>>1;    // 低m位，高m位
        int cnt1=0,cnt2=0;  // 数有几位1
        for(int i=1;i<=m;i++){
            cnt1+=((b&(1<<i))>0);
            cnt2+=((b&(1<<(i+1)))>0);
        }
        if(cnt1>k || cnt2>k) return; // 检验合法性
        v[x][y]=1; ok[x]=ok[y]=1;
        return; // 回溯
    }
    generateMatrixV(len+1,b<<1);    // dfs下一位
    generateMatrixV(len+1,(b<<1)|1);
}

LL** newMatrix(int n){ // 创建矩阵
    LL** a=new LL*[n];
    for(int i=0;i<n;i++) {
        a[i]=new LL[n];
        for (int j=0;j<n;j++) a[i][j]=0;
    }
    return a;
}

LL** mul(LL** a,LL** b,int n) {  // 矩阵乘法
    LL** c=newMatrix(n);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++) c[i][j]+=(a[i][k]*b[k][j])%MOD;
            c[i][j]%=MOD;
        }
    }
    return c;
}

LL** pow(LL** mt,int n,LL p){   // 矩阵幂次
    if (p==1) return mt;
    LL** x=pow(mt,n,p/2);
    LL** x2=mul(x,x,n);
    return p%2 ? mul(x2,mt,n) : x2;
}

void print(LL** a,int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n-1;j++) cout<<a[i][j]<<" ";
        cout<<a[i][n-1]<<endl;
    }
    cout<<endl;
}

int main() {
    scanf("%lld%d%d",&n,&m,&k);
    int w=(1<<m); // 状态数上限
    v=newMatrix(w);
    generateMatrixV(0,0);   // 构造矩阵
    a=pow(v,w,n);   // 矩阵快速幂
    for(int i=0;i<w;i++) {
        if(ok[i]) ans+=a[i][i]%MOD;
    }
    printf("%lld\n",ans%MOD);
}
