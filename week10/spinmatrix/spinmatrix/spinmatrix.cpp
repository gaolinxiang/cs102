//
//  main.cpp
//  spinmatrix
//
//  Created by Ge, Xiao on 13/07/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//Ç

#include <iostream>
using namespace std;

long long n,x,y;

int main(int argc, const char * argv[]) {
    cin>>n>>x>>y;
    long long outer=min(min(x,y),min(n-x+1,n-y+1))-1;    // 外层圈数
    long long ans=n*n-(n-outer*2)*(n-outer*2);  // 外圈总数
    x-=outer,y-=outer,n-=outer*2;  // 移除外圈
    if (x==1) ans+=y;  // 上边
        else if (y==n) ans+=n+x-1;    // 右边
        else if (x==n) ans+=2*n-1+(n-y);   // 下边
        else ans+=3*n-2+(n-x);   // 左边
    cout<<ans<<endl;
    return 0;
}
