#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,a[55][55];
ll c[55][55],ans=0;

void doit(int x){
    for (int i=2;i<=x;i++){
        ans+=c[x][i];
    }
}

int main(){
    scanf("%d%d",&n,&m);
    ans=n*m;
    memset(c,0,sizeof c);
    c[0][0]=1;
    for (int i=1;i<=50;i++){
        c[i][0]=1;
        for (int j=1;j<=50;j++){
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
    int t[2];
    for (int i=1;i<=n;i++){
        t[0]=t[1]=0;
        for (int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            t[a[i][j]]++;
        }
        doit(t[0]);
        doit(t[1]);
    }
    for (int j=1;j<=m;j++){
        t[0]=t[1]=0;
        for (int i=1;i<=n;i++){
            t[a[i][j]]++;
        }
        doit(t[0]);
        doit(t[1]);
    }
    cout<<ans;
}