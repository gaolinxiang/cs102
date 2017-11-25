//
//  main.cpp
//  fibonacci
//
//  Created by Ge, Xiao on 01/07/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
#define MOD 1000000007
typedef unsigned long long ull;
using namespace std;

// a为转移矩阵
ull n,a[2][2]={{0,1},{1,1}},f[2][2];

void mul(ull a[2][2],ull b[2][2],ull c[2][2]) {  // 矩阵乘法
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            c[i][j]=0;
            for (int k=0;k<2;k++) c[i][j]+=(a[i][k]*b[k][j])%MOD;
        }
    }
}

void pow(ull a[2][2],ull p,ull c[2][2]){   // 矩阵幂次
    if (p==0) {
        c[0][0]=c[1][1]=1;  // 单位矩阵
        c[0][1]=c[1][0]=0;
        return ;
    }
    ull tmp1[2][2],tmp2[2][2];
    pow(a,p/2,tmp1); // a^(n/2)
    if (p%2){   // 快速幂
        mul(tmp1,tmp1,tmp2); // a^((n/2)*2)
        mul(tmp2,a,c);
    } else{
        mul(tmp1,tmp1,c);
    }
}

int main(int argc, const char * argv[]) {
    cin>>n;
    pow(a,n,f); // a^n
    cout<<(f[0][0]+f[0][1])%MOD<<endl;
    return 0;
}