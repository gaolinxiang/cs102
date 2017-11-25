//
//  main.cpp
//  fibonacci
//
//  Created by Ge, Xiao on 01/07/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007

unsigned long long** newMatrix(int n,int m){ // 创建矩阵
    unsigned long long** a=new unsigned long long*[n];
    for(int i=0;i<n;i++){
        a[i]=new unsigned long long[m];
    }
    return a;
}

unsigned long long** add(unsigned long long** a,unsigned long long** b,int n,int m) {   // 矩阵加法
    unsigned long long** c=newMatrix(n, m);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            c[i][j]=(a[i][j]+b[i][j])%MOD;
        }
    }
    return c;
}

unsigned long long** mul(unsigned long long** a,unsigned long long** b,int n1,int m1,int n2,int m2) {  // 矩阵乘法
    if (m1!=n2){
        return 0;
    }
    unsigned long long** c=newMatrix(n1, m2);
    for (int i=0;i<n1;i++){
        for (int j=0;j<m2;j++){
            c[i][j]=0;
            for (int k=0;k<m1;k++){
                c[i][j]+=(a[i][k]*b[k][j])%MOD;
            }
        }
    }
    return c;
}

unsigned long long** id=newMatrix(2,2);

unsigned long long** pow(unsigned long long** mt,int n,unsigned long long p){   // 矩阵幂次
    if (p==0){
        return id;
    }
    unsigned long long** x=pow(mt,n,p/2);
    unsigned long long** x2=mul(x,x,n,n,n,n);
    return p%2 ? mul(x2,mt,n,n,n,n) : x2;
}

void print(unsigned long long** a,int n,int m){ // 打印矩阵（日志）
    for (int i=0;i<n;i++){
        for (int j=0;j<m-1;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<a[i][m-1]<<endl;
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    
    id[0][0]=id[1][1]=1,id[0][1]=id[1][0]=0;
    unsigned long long n;
    cin>>n;

    unsigned long long** mt=newMatrix(2,2);
    mt[0][0]=0,mt[0][1]=mt[1][0]=mt[1][1]=1;
    unsigned long long** f=pow(mt,2,n);
//    print(f,2,2);
    cout<<(f[0][0]+f[0][1])%MOD<<endl;
    
    return 0;
}
