#include <algorithm>
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

const int N=500010;
const ll INF=2e18;

int n,a[N];
vi e[N];
ll ans;

int f[N][20],dep[N],rt;
int lg2(int x){return x?__lg(x):-1;}
void dfs(int x,int fa){
    f[x][0]=fa;ll mi=a[fa];
    for(int i=1;i<=lg2(dep[x]);i++){
        f[x][i]=f[f[x][i-1]][i-1];
        mi=min(mi,(ll)(i+1)*a[f[x][i]]);
    }
    mi=min(mi,(ll)(lg2(dep[x])+2)*a[rt]);
    if(fa) ans+=mi+a[x];
    for(auto y:e[x]){
        if(y==fa) continue;
        dep[y]=dep[x]+1;
        dfs(y,x);
    }
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        e[x].pb(y),e[y].pb(x);
    }
    dfs(rt=min_element(a+1,a+n+1)-a,0);
    cout<<ans<<endl;
    return 0;
}