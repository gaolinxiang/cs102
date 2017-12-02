//
//  main.cpp
//  countgraphpath
//
//  Created by gexiao on 28/07/2017.
//  Copyright © 2017 gexiao. All rights reserved.
//

#include <iostream>
#define LL long long
#define MOD 1000000007
#define N 1005
using namespace std;

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

int n,k;
int main(int argc, const char * argv[]) {
    cin>>n>>k;
    LL** mt=newMatrix(n);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) cin>>mt[i][j];
    }
    LL** ans=pow(mt,n,k);
    print(ans,n);
    return 0;
}
