#include<cstring>
#include<iostream>
#define ll long long
#define N 35
using namespace std;

int ans=1e9,n,m,a[N][N],f[N*N*2][N][N];

int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<=N*(n+m);k++) f[k][i][j]=1000000;
    
    f[a[1][1]][1][1]=a[1][1]*a[1][1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<=N*(n+m);k++)
                if(f[k][i][j]!=1000000){
                    int x=i+1,y=j,v=a[x][y];
                    f[k+v][x][y]=min(f[k+v][x][y],f[k][i][j]+v*v);
                    x=i; y=j+1; v=a[x][y];
                    f[k+v][x][y]=min(f[k+v][x][y],f[k][i][j]+v*v);
                }
    
    for(int i=1;i<=N*(n+m);i++)
        if(f[i][n][m]!=1000000) ans=min(ans,(n+m-1)*f[i][n][m]-i*i);
    cout<<ans<<endl;
    return 0;
}