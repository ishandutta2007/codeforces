#include <bits/stdc++.h>

using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=1010;

int n,a[N][N],val[N][N];

void doit(int up,int dw,int le,int ri,int v=1){
    if(up>dw||le>ri) return;
    if(up==dw){
        for(int i=le;i<=ri;i++) val[up][i]=v;
        return;
    }
    if(up+2==dw){
        for(int i=le;i<=ri;i++) val[up][i]=val[dw][i]=val[up+1][i]=v;
        val[up+1][le]^=1,val[up+1][ri]^=1;
        return;
    }
    for(int i:{up,up+1,dw-1,dw})
        for(int j=le;j<=ri;j++) val[i][j]=v;
    for(int i:{le+1,ri-1})
        for(int j=up;j<=dw;j++) val[j][i]=v;
    for(int i:{le,ri})
        for(int j=up;j<=dw;j++) val[j][i]=(v^((j-up)&1));
    doit(up+2,dw-2,le+2,ri-2,v^1);
}

void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++) a[i][j]=rdi();
    doit(1,n-1,1,n);int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) ans^=(val[i][j]*a[i][j]),val[i][j]=0;
    cout<<ans<<'\n';
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int T=rdi();
    while(T--) solve();
    return 0;
}