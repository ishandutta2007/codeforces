#include <bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;
using vi=vector<int>;
using ll=long long;

template<typename T>
T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdll read<ll>

#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N=100010,INF=0x3f3f3f3f;

int n,rt,res[N];
vi e[N];

int siz[N],son[N];
int mx[N],misiz[N],mxsiz[N],mxsiz2[N];
void dfs(int x,int fa){
    siz[x]=1;
    mxsiz[x]=mxsiz2[x]=0,misiz[x]=INF;
    auto update = [&](int y,int sz){
        if(sz>mxsiz[x]) mxsiz2[x]=mxsiz[x],mxsiz[x]=sz,mx[x]=y;
        else if(sz>mxsiz2[x]) mxsiz2[x]=sz;
        if(sz<misiz[x]) misiz[x]=sz;
    };

    for(auto y:e[x]){
        if(y==fa) continue;
        dfs(y,x);
        update(y,siz[y]);
        siz[x]+=siz[y];
    }
    if(fa) update(fa,n-siz[x]);
}

set<int> s;
void update(int x,int delta){
    int val=(mxsiz[x]-misiz[x]+1)/2;
    auto it=s.lower_bound(val-delta);
    if(it!=s.end()) res[x]=min(res[x],max(misiz[x]+(*it+delta),mxsiz[x]-(*it+delta)));
    if(it!=s.begin()) it--,res[x]=min(res[x],max(misiz[x]+(*it+delta),mxsiz[x]-(*it+delta)));
}

void solve1(int x,int fa){
    if(mx[x]!=fa) solve1(mx[x],x),update(x,0);
    else update(x,0);
    for(auto y:e[x]){
        if(y==fa||y==mx[x]) continue;
        solve1(y,x);
    }
    s.insert(siz[x]);
}

void solve2(int x,int fa){
    if(mx[x]==fa) update(x,0);
    for(auto y:e[x]){
        if(y==fa) continue;
        solve2(y,x);
    }
    s.insert(siz[x]);
}
void solve2_re(int x,int fa){
    if(mx[x]==fa) update(x,0);
    reverse(e[x].begin(),e[x].end());
    for(auto y:e[x]){
        if(y==fa) continue;
        solve2_re(y,x);
    }
    reverse(e[x].begin(),e[x].end());
    s.insert(siz[x]);
}

void solve3(int x,int fa,int delta=0){
    if(mx[x]==fa) update(x,delta);
    bool flg=s.insert(-delta).se;
    for(auto y:e[x]){
        if(y==fa) continue;
        solve3(y,x,delta+siz[x]-siz[y]);
    }
    if(flg) s.erase(-delta);
}

int main(){
    n=rdi();
    for(int i=1;i<=n;i++){
        int x=rdi(),y=rdi();
        if(!x||!y) rt=x|y;
        else e[x].pb(y),e[y].pb(x);
    }

    int maxd=0;
	for(int i=1;i<=n;i++) maxd=max(maxd,(int)e[i].size());
	if(maxd<3){
		for(int i=1;i<=n;i++) printf("%d\n",e[i].size()&1?n-1:n/2);
		return 0;
	}
	if(maxd>n-2){
		for(int i=1;i<=n;i++) printf("%d\n",(int)(n-e[i].size()));
		return 0;
	}
    memset(res,0x3f,sizeof(res));

    dfs(rt,0);
    solve1(rt,0);s.clear();
    solve2(rt,0);s.clear();
    solve2_re(rt,0);s.clear();
    solve3(rt,0);s.clear();
    for(int i=1;i<=n;i++){
        if(mxsiz[i]==misiz[i]) res[i]=mxsiz[i];
        else res[i]=min(max(res[i],mxsiz2[i]),mxsiz[i]);
        cout<<res[i]<<'\n';
    }
    cout<<'\n';
    return 0;
}