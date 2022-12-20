// LUOGU_RID: 90821359
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back

const int N=55,MOD=1e9+7;

i64 qpow(i64 x,i64 y=MOD-2){
    i64 res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

int n,m;

inline i64 C(int n,int m){
    i64 ret=1;
    for(int i=1;i<=m;i++) ret=ret*i%MOD;
    ret=qpow(ret);
    for(int i=n-m+1;i<=n;i++) ret=ret*i%MOD;
    return ret;
}

i64 sum[N][N],f[N][N],g[N][N],h[N][N],dp[N][N];
void solve(){
    if(m>n+1){
        puts("0");
        return;
    }
    f[0][1]=sum[0][0]=sum[0][1]=1,dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n+1;j++){
            for(int k=0;k<i;k++)
                h[i][j]+=sum[k][j]*sum[i-k-1][j]%MOD;
            h[i][j]%=MOD;
            if(j){
                g[i][j-1]=(h[i][j-1]+MOD-h[i][j])%MOD;
                static i64 mul[N];
                for(int k=0;k<=n+1;k++) mul[k]=C(g[i][j-1]+k-1,k);
                for(int u=n;u>=i;u--){
                    for(int v=n+1;v>=j-1;v--){
                        for(int c=1;c*i<=u&&c*(j-1)<=v;c++)
                            dp[u][v]+=dp[u-c*i][v-c*(j-1)]*mul[c]%MOD;
                        dp[u][v]%=MOD;
                    }
                }
            }
        }
        for(int j=n+1;j>=0;j--){
            if(j) f[i][j]=dp[i][j-1];
            sum[i][j]=(sum[i][j+1]+f[i][j])%MOD;
        }
    }
    cout<<f[n][m]<<'\n';
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),m=rdi();
    solve();
    return 0;
}