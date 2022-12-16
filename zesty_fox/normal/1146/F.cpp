#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=200010,MOD=998244353;

ll qpow(ll x,ll y=MOD-2){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

int n;
vi e[N];

ll f[N][3];
void dfs(int x){
    if(e[x].empty()) {f[x][0]=f[x][1]=1;return;}
    ll mul=1,sum=0;f[x][0]=1;
    for(auto y:e[x]){
        dfs(y);
        /*
        f[x][2]=((f[x][1]+f[x][2])*(f[y][1]+f[y][2])%MOD+f[x][2]*f[y][0])%MOD;
        f[x][1]=(f[x][1]*(f[y][2]+f[y][0])+f[x][0]*f[y][1])%MOD;
        f[x][0]=(f[x][0]*(f[y][2]+f[y][0]))%MOD;
        */
        (f[x][0]*=(f[y][0]+f[y][2]))%=MOD;
        (sum+=qpow(f[y][0]+f[y][2])*(f[y][1]+f[y][2]))%=MOD;
        (mul*=(f[y][0]+f[y][1]+2*f[y][2]))%=MOD;
    }
    f[x][1]=f[x][0]*sum%MOD;
    f[x][2]=(mul+2*MOD-f[x][0]-f[x][1])%MOD;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=2;i<=n;i++) e[rdi()].pb(i);
    dfs(1);
    ll ans=(f[1][0]+f[1][2])%MOD;
    cout<<ans<<endl;
    return 0;
}