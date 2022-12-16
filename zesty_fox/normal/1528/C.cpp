#include <algorithm>
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

const int N=300010,INF=0x3f3f3f3f;

int n,f[N];
vi t1[N],t2[N];

int dfn[N],low[N],ti;
void dfs(int x){
    dfn[x]=++ti;
    for(auto y:t2[x]) dfs(y);
    low[x]=ti;
}

set<pii> s;
set<pii>::iterator it;
void solve(int x){
    pii tmp1(0,0);
    it=s.lower_bound({dfn[x],0});
    if(it==s.end()||(it!=s.end()&&it->se>low[x])){
        it=s.upper_bound({dfn[x],0});
        if(it!=s.begin()){
            it--;
            if(it->se>=low[x]) tmp1=*it,s.erase(it);
        }
        s.insert({dfn[x],low[x]});
    }
    f[x]=s.size();

    for(auto y:t1[x]) solve(y);
    s.erase({dfn[x],low[x]});
    if(tmp1.fi) s.insert(tmp1);
}

void clear(){
    s.clear(),ti=0;
    for(int i=1;i<=n;i++) f[i]=dfn[i]=low[i]=0,t1[i].clear(),t2[i].clear();
}

void solve(){
    n=rdi();
    for(int i=2;i<=n;i++) t1[rdi()].pb(i);
    for(int i=2;i<=n;i++) t2[rdi()].pb(i);
    dfs(1);solve(1);
    int ans=*max_element(f+1,f+n+1);
    cout<<ans<<'\n';
    clear();
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