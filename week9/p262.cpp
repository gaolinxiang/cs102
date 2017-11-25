#include <iostream>
using namespace std;

const int maxn=1e6+10;
const long long p=1e9+7;

int h,w,a,b;
long long WITH_NIYUAN[maxn],NIYUAN_JIECHENG[maxn],JIE_CHENG[maxn];
long long ROUTES_NUM,TMP_REST;

long long CALCULATE_C_WITH_NIYUAN(int num1,int num2) {  // 计算mod p意义下的组合数
    if (num2==0||num1==num2)  return 1LL;
    long long yushu=JIE_CHENG[num1]*NIYUAN_JIECHENG[num2];
    yushu=yushu%p*NIYUAN_JIECHENG[num1-num2]%p;
    return yushu;
}

int main () {
    cin>>h>>w>>a>>b;
    NIYUAN_JIECHENG[1]=JIE_CHENG[1]=WITH_NIYUAN[1]=1;
    for (int i=2;i<maxn;++i) {  // 计算逆元和阶乘的逆元
        WITH_NIYUAN[i]=-(p/i)*WITH_NIYUAN[p%i];
        WITH_NIYUAN[i]%=p;
        while (WITH_NIYUAN[i]<0) WITH_NIYUAN[i]+=p; // 负数变为正数
        NIYUAN_JIECHENG[i]=(NIYUAN_JIECHENG[i-1]*WITH_NIYUAN[i])%p;
        JIE_CHENG[i]=(JIE_CHENG[i-1]*i)%p;
    }

    for  (int i=h-a;i>0;i--) {
         TMP_REST=CALCULATE_C_WITH_NIYUAN(i+b-2,i-1)*CALCULATE_C_WITH_NIYUAN(h-i+w-b-1,h-i)%p;
        ROUTES_NUM=(ROUTES_NUM+TMP_REST)%p;
    }
    while (ROUTES_NUM<0) ROUTES_NUM+=p;
    cout<<ROUTES_NUM<<endl;
    return 0;
}

