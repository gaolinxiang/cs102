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
int m,k,b[6],w; // b为6位01状态（dfs穷举用）

void generateMatrixV(){    // DFS生成转移矩阵
    for (int b=0;b<(w<<1);b++){
        int x=b&((1<<m)-1),y=b>>1;    // 低m位，高m位
        int cnt1=0,cnt2=0;  // 数有几位1
        for(int i=0;i<m;i++){
            cnt1+=((x&(1<<i))>0);
            cnt2+=((y&(1<<i))>0);
        }
        v[y][x]=(cnt1<=k && cnt2<=k); // 检验合法性
    }
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

void print(LL** a,int n){   // 打印矩阵
    for (int i=0;i<n;i++){
        for (int j=0;j<n-1;j++) cout<<a[i][j]<<" ";
        cout<<a[i][n-1]<<endl;
    }
    cout<<endl;
}

int main() {
    scanf("%lld%d%d",&n,&m,&k);
    w=(1<<m); // 状态数上限
    v=newMatrix(w);
    generateMatrixV();   // 构造矩阵
    
    a=pow(v,w,n);   // 矩阵快速幂
    print(a,w);
    for(int i=0;i<w;i++) ans+=a[i][i]%MOD;
    printf("%lld\n",ans%MOD);
}
