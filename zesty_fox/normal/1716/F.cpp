#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=2010,MOD=998244353;

i64 qpow(i64 x,i64 y=MOD-2){
    i64 res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

i64 s2[N][N];
void init(int n){
    s2[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            s2[i][j]=(s2[i-1][j-1]+s2[i-1][j]*j)%MOD;
    }
}

int n,m,k,A,B;
void solve(){
    n=rdi(),m=rdi(),k=rdi(),A=(m+1)/2,B=m-A;
    i64 ans=0,mul=qpow(A+B,n),inv=qpow(A+B);
    for(int i=0;i<=min(n,k);i++){
        ans+=s2[k][i]*mul%MOD;
        mul=mul*(n-i)%MOD*A%MOD*inv%MOD;
    }
    ans%=MOD;
    cout<<ans<<'\n';
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int T=rdi();init(N-10);
    while(T--) solve();
    return 0;
}