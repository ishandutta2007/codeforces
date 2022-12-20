#include <bits/stdc++.h>

using namespace std;

using i64=long long;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=1e5+10;

int n,b[N],k,num[N];
vi e[N];

int seq[N],ti;
void dfs(int x){
    if(x>=1&&x<=n) seq[++ti]=x;
    sort(e[x].begin(),e[x].end(),[&](int x,int y){return e[x].size()<e[y].size();});
    for(auto y:e[x]) dfs(y);
}

void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) b[i]=rdi();

    copy(b+1,b+n+1,num+1);sort(num+1,num+n+1);
    for(int i=n,pos=n;i>=0;i--){
        while(pos>=1&&num[pos]>i) --pos;
        if(i==n-pos) {k=i;break;}
    }

    for(int i=1;i<=n;i++) e[b[i]].pb(i);
    dfs(0),dfs(n+1);
    cout<<k<<'\n';
    for(int i=1;i<=n;i++) cout<<seq[i]<<' ';
    cout<<'\n';

    ti=0;
    for(int i=0;i<=n+1;i++) e[i].clear();
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