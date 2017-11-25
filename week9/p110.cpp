#include<iostream>
#include<stdlib.h>
#include<algorithm>
#define N 20005

using namespace std;
long long n,m,a[N],f1[N],f2[N];

int main(){
    
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
        f1[a[i]]++;
    }
    
    for (int j=0;j<=m;j++){
        for (int i=0;i<n;i++){
            if (j>a[i]) f2[j]+=f1[j-a[i]];
        }
    }
    
    long long ans=0;
    for (int j=0;j<=m;j++){
        ans+=f2[j]*f2[m-j];
    }
    
    cout<<ans<<endl;
    
}