#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+7;
const ll M=998244353;
const int E=3001;
ll w[maxn],o[maxn],p,q,dp[3005][3005],A,B;
int n,m;
ll pow_(ll x,ll y){
    ll ret=1;
    while (y){
        if (y&1) ret=ret*x%M;
        x=x*x%M; y>>=1;
    }
    return ret;
}
void add(ll &x,ll y){
    x+=y; if (x>=M) x-=M;
}
int main(){
    cin >> n >> m;
    for (int i=0;i<n;i++) scanf("%I64d",&o[i]);
    for (int i=0;i<n;i++) {
        scanf("%I64d",&w[i]);
        if (o[i]) p+=w[i]; else q+=w[i];
    }
    dp[0][0]=1;
    for (int i=0;i<m;i++){
        for (int j=0;j<=i;j++) if (dp[i][j]){
            ll r=(p+j)*pow_(p+j+q-(i-j),M-2)%M;
            add(dp[i+1][j+1],dp[i][j]*r%M);
            add(dp[i+1][j],dp[i][j]*(M+1-r)%M);
        }
    }
    for (int i=0;i<=m;i++) if (dp[m][i]){
        add(A,dp[m][i]*(p+i)%M);
        add(B,dp[m][i]*(q-(m-i))%M);
    }
    p=pow_(p,M-2);
    q=pow_(q,M-2);
    for (int i=0;i<n;i++) if (o[i]) printf("%I64d ",A*w[i]%M*p%M); else printf("%I64d ",B*w[i]%M*q%M);
    puts("");
    return 0;
}