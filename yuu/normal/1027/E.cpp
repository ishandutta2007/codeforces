#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll base=998244353;
int n, k;
ll f[501];
ll g[501];
ll s[501];
int main(){
    cin>>n>>k;
    for(int l=1; l<=n; l++){
        for(int i=1; i<=n; i++) g[i]=0;
        for(int i=1; i<=n; i++) s[i]=0;
        g[0]=s[0]=1;
        for(int i=1; i<=n; i++){
            g[i]=s[i-1]-(((i-l)>0)?s[i-l-1]:0);
            g[i]%=base;
            s[i]=(s[i-1]+g[i])%base;
        }
        f[l]=g[n];
    }
    for(int i=n; i>=1; i--) f[i]-=f[i-1];
    ll res=0;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        if(i*j<k) (res+=f[i]*f[j])%=base;
    }
    (res*=2)%=base;
    res=(res+base)%base;
    cout<<(res)<<'\n';
}