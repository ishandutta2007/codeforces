#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, mod, C[444][444], f[404][404], g[404];

void U(int &x,ll y){
    x=(x+y)%mod;
}

int main(){
    cin>>n>>mod;
    for (int i=0;i<=n;++i){
        C[i][0]=1;
        for (int j=1;j<=i;++j)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    g[1]=1;
    for (int i=2;i<=n;++i){
        for (int j=1;j<=i;++j)
            U(g[i],C[i-1][j-1]);
    }
    for (int i=1;i<=n;++i){
        U(f[i][i],g[i]);
        for (int j=1;j<=i-2;++j)
            for (int k=1;k<=j;++k)
                if (f[j][k]){
                    U(f[i][k+i-j-1],(ll)f[j][k]*C[k+i-j-1][k]%mod*g[i-j-1]);
                }
    }
    int ans=0;
    for (int i=1;i<=n;++i) U(ans,f[n][i]);
    cout<<ans<<endl;
}