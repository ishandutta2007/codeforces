#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n=30, L, R, len[44];

map<int,int>G[44];

int main(){
    G[n-1][n]=1; len[n-1]=1;
    for (int i=n-2;i>=2;--i){
        len[i]=len[i+1]*2;
        G[i][n]=1; int p=1;
        for (int j=n-1;j>i;--j){
            G[i][j]=p; p+=len[j];
        }
    }
    cin>>L>>R;
    {
        G[1][n]=L;
        int p=L;
        for (int j=2;j<=n-1;++j){
            if (p+len[j]<=R){
                G[1][j]=p; p+=len[j];
            }
        }
    }
    int m=0;
    for (int i=1;i<=n;++i) m+=G[i].size();
    puts("YES");
    printf("%d %d\n",n,m);
    for (int i=1;i<=n;++i){
        for (auto o:G[i])
            printf("%d %d %d\n",i,o.first,min(1000000,o.second));
    }
}