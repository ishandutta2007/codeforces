#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using db = double;
using pii = pair<int, int>;
using vi = vector<int>;

template <typename T>
T read(){
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

const int MOD=998244353,N=5010;

i64 qpow(i64 x,i64 y=MOD-2){
    i64 res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

int n;
i64 a,b,p;
i64 f[N],h[N][N],g[N];
i64 pw[N],pw1[N];

void solve(){
    pw[0]=pw1[0]=1;
    for(int i=1;i<=n;i++) pw[i]=pw[i-1]*p%MOD,pw1[i]=pw1[i-1]*(MOD+1-p)%MOD;

    // h[i][j]: i-j win, j lose
    h[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            h[i][j]=h[i-1][j]*pw1[j];
            if(j) h[i][j]+=h[i-1][j-1]*pw[i-j];
            h[i][j]%=MOD;
        }
    }
    g[1]=1;
    for(int i=2;i<=n;i++){
        g[i]=1;
        for(int j=1;j<i;j++) g[i]-=g[j]*h[i][j]%MOD;
        g[i]=(g[i]%MOD+MOD)%MOD;
    }

    f[1]=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++)
            f[i]+=h[i][j]*g[j]%MOD*(f[i-j]+f[j]+j*(j-1)/2+j*(i-j))%MOD;
        f[i]+=g[i]*(i*(i-1)/2)%MOD;f[i]%=MOD;
        f[i]=f[i]*qpow(MOD+1-g[i])%MOD;
    }
    cout<<f[n]<<endl;
}

int main(){
    n=rdi(),a=rdi(),b=rdi(),p=a*qpow(b)%MOD;solve();
    return 0;
}