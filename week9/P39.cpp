#include <stdio.h>
#include <iostream>
#define N 35
#define T 205
using namespace std;
int main() {
    
    int s1,s2,e1,e2,n=0;
    scanf("%d:%d %d:%d %d",&s1,&s2,&e1,&e2,&n);
    int time=e1*60+e2-s1*60-s2;//时间转换
    struct tree {   // 结构体数组
        int t,c,p;  // 时间，价值，次数
    }a[N];
    
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i].t,&a[i].c,&a[i].p);
        if(a[i].p==0){
            a[i].p=time/a[i].t;// 无限->有限
        }
    }
    
    int f[2][T]={};
    //背包问题
    for(int i=1;i<=n;i++){  // 阶段，前i棵树
        for(int t=0;t<=time;t++){   // 状态，时间
            f[i&1][t]=0;
            for (int k=0;k<=a[i].p && t>=a[i].t*k;k++){  // 决策，第i棵看几遍
                f[i&1][t]=max(f[i&1][t],f[1-i&1][t-a[i].t*k]+a[i].c*k);
            }
        }
    }
    printf("%d",f[n&1][time]);
    return 0;
}
