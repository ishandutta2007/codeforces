#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll;
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
const int mo=1e9+7,M=2e4+5;
using namespace std;

int n,a[15],g[15][M],dp[15][M];

int mul(int a,int b){
    int ans=1,w=a%mo;
    for(;b;b/=2){
        if(b&1)ans=(ll)ans*w%mo;
        w=(ll)w*w%mo;
    }
    return ans;
}

int main() {
    scanf("%d",&n);
    rep(i,0,n-1)scanf("%d",&a[i]);
    int st=(1<<n)-1;
    rep(i,0,n-1)rep(S,0,st)if(!((S>>i)&1)){
        g[i][S]=1;
        rep(j,0,n-1)if((S>>j)&1)g[i][S]=(ll)g[i][S]*a[i]%mo*mul(a[i]+a[j],mo-2)%mo;
    }
    rep(i,0,n-1)rep(S,0,st)if((S>>i)&1){
        dp[i][S]=1;
        if(S==(1<<i))continue;
        for(int j=(S-1)&S;j>0;j=(j-1)&S){
            int res=1;
            rep(k,0,n-1)if((j>>k)&1)res=(ll)res*g[k][S^j]%mo;
            dp[i][S]-=(ll)dp[i][S^j]*res%mo;dp[i][S]%=mo;
        }
    }
    int res=0;
    rep(i,0,n-1)res=(res+dp[i][st])%mo;
    printf("%d\n",(res+mo)%mo);
    return 0;
}