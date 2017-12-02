//
//  main.cpp
//  random
//
//  Created by Ge, Xiao on 13/07/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include<cstdio>    // c打头的表示c语言类库
#define LL long long    // 类型别名
using namespace std;

struct matrix{ // 矩阵类型，只需要维护第一列
    LL a,c;
};

// 初始化struct的简单方写法（强制类型转换）
const matrix id = (matrix){1,0};  // 单位矩阵
LL m,a,c,x,n,g;

LL mm(LL x, LL y){  // 防越界的LL乘法（mod m）
    if (!y) return 0;
    LL ans = mm(x, y >> 1) << 1;
    if (y & 1) ans += x;
    return ans % m;
}

inline matrix mul(matrix a, matrix b){  // 矩阵乘法（特殊版）
    return (matrix){mm(b.a,a.a),(mm(b.a,a.c)+b.c)%m};
}

matrix pow(matrix a, LL t){ // 矩阵幂次
    if (t==0) return id;
    matrix p = pow(a, t >> 1);
    p = mul(p, p);
    return t&1 ? mul(a, p) : p;
}

int main(){
    scanf("%lld%lld%lld%lld%lld%lld", &m,&a,&c,&x,&n,&g);
    matrix s = (matrix){a,1};
    matrix p = pow(s, n);   // 幂次
    printf("%lld", (mm(p.a, x) + mm(p.c, c))%m%g);
    return 0;
}
