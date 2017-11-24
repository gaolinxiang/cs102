#include<iostream>
#include<vector>
#define DAY 86400
#define MAX 100000

using namespace std;
int n,exist[MAX],t[MAX],tot;
vector<int> x[MAX];

int main(){
    cin>>n;
    for(int i=1,past=0,a,k;i<=n;i++){
        cin>>t[i]>>k;
        for(int j=0;j<k;j++){    // 到达
            cin>>a; // 依次输入国籍
            x[i].push_back(a);
            exist[a]++;
            tot+=exist[a]==1;   // 多一个新国家
        }
        for(;t[i]-t[past]>=DAY;past++){ // 离开
            for(int j=0;j<x[past].size();j++){
                exist[x[past][j]]--;
                tot-=exist[x[past][j]]==0;
            }
        }
        cout<<tot<<endl;
    }
    return 0;
}
