#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=200010;

int n;
vi e[N];

int p[N],f[N];
bool dfs(int x,int fa){
    bool ret=true;
    int cnt[2]={0};
    for(auto y:e[x]){
        if(y==fa) continue;
        f[y]=x,ret&=dfs(y,x),cnt[p[y]]++;
    }
    if(fa) cnt[p[x]=(cnt[0]>=cnt[1])]++;
    if(cnt[1]<cnt[0]||cnt[1]>cnt[0]+1) ret=false;
    return ret;
}

void dfs1(int x){
    vi to[2];
    for(auto y:e[x]){
        if(y==f[x]) to[p[x]].pb(x);
        else to[p[y]].pb(y);
    }
    int nw=e[x].size()&1;
    for(int i=0;i<e[x].size();i++){
        int y=to[nw].back();
        if(y==x) cout<<x<<' '<<f[x]<<'\n';
        else dfs1(y);
        to[nw].pop_back(),nw^=1;
    }
}

void clear(){
    for(int i=1;i<=n;i++) f[i]=p[i]=0,e[i].clear();
}

void solve(){
    n=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        e[x].pb(y),e[y].pb(x);
    }
    if(!dfs(1,0)) {puts("NO");clear();return;}
    puts("YES");dfs1(1);clear();
}

int main(){
    int T=rdi();
    while(T--) solve();
    return 0;
}