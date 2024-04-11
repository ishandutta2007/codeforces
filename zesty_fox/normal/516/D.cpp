#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=100010;
int n,Q;
vector<pair<int,ll> > e[N];
void addedge(int x,int y,ll w){
    e[x].pb(mp(y,w));e[y].pb(mp(x,w));
}

ll dis[N];
void dfs(int x,int fa){
    for(auto tmp:e[x]){
        int y=tmp.fi;
        if(y==fa) continue;
        dis[y]=dis[x]+tmp.se;
        dfs(y,x);
    }
}

vector<pair<ll,int> > p;
bool find_path(int x,int fa,int dest,vector<pair<ll,int> > &p){
    if(x==dest) return true;
    for(auto tmp:e[x]){
        int y=tmp.fi;
        if(y==fa) continue;
        p.pb(mp(p.back().fi+tmp.se,y));
        if(find_path(y,x,dest,p)) return true;
        p.pop_back();
    }
    return false;
}

int st,ed,rt;
int deledge(int x,int y){
    int ret=0;
    for(auto it=e[x].begin();it!=e[x].end();it++){
        if((*it).fi==y) {e[x].erase(it);ret=(*it).se;break;}
    }
    for(auto it=e[y].begin();it!=e[y].end();it++){
        if((*it).fi==x) {e[y].erase(it);break;}
    }
    return ret;
}

int f[N];
void dfs1(int x,int fa){
    f[x]=fa;
    for(auto tmp:e[x]){
        int y=tmp.fi;
        if(y==fa) continue;
        dis[y]=dis[x]+tmp.se;
        dfs(y,x);
    }
}

int nodes[N],id[N];
void init(){
    dis[1]=0;dfs(1,0);
    for(int i=1;i<=n;i++){
        if(dis[i]>dis[st]) st=i;
    }
    dis[st]=0;dfs(st,0);
    for(int i=1;i<=n;i++){
        if(dis[i]>dis[ed]) ed=i;
    }
    p.pb(mp(0,st));
    find_path(st,0,ed,p);
    ll len=p.back().fi/2;
    auto it=lower_bound(p.begin(),p.end(),mp(len,0));
    if((*it).fi==len){
        rt=(*it).se;
        dis[rt]=0;dfs1(rt,0);
    }
    else{
        rt=n+1;
        int x=(*prev(it)).se,y=(*it).se;
        int bak=deledge(x,y);
        addedge(y,rt,(*it).fi-len),addedge(x,rt,len-(*prev(it)).fi);
        dis[rt]=0;dfs1(rt,0);
        deledge(y,rt);deledge(x,rt);
        addedge(x,y,bak);
    }
    for(int i=1;i<=n;i++) nodes[i]=i;
    sort(nodes+1,nodes+n+1,[&](const int &x,const int &y){return dis[x]>dis[y];});
    for(int i=1;i<=n;i++) id[nodes[i]]=i;
}

int ans;
namespace DSU{
int f[N],siz[N];
void init(){
    for(int i=1;i<=n;i++) f[i]=i,siz[i]=1;
    siz[n+1]=0;
}
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y) return;
    if(siz[x]<siz[y]) swap(x,y);
    f[y]=x;siz[x]+=siz[y];
    ans=max(ans,siz[x]);
}
}

int solve(ll lim){
    DSU::init();
    int l=1,r=1;ans=1;
    while(l<=n&&r<=n){
        while(r<=n&&dis[nodes[l]]-dis[nodes[r]]<=lim){
            int x=nodes[r];
            for(auto tmp:e[x]){
                int y=tmp.fi;
                if(l<=id[y]&&id[y]<r) DSU::merge(x,y);
            }
            r++;
        }
        DSU::siz[DSU::find(nodes[l])]--;l++;
    }
    return ans;
}

int main(){
    n=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi(),w=rdi();
        addedge(x,y,w<<1);
    }
    init();
    Q=rdi();
    while(Q--) printf("%d\n",solve(rdll()<<1));
    return 0;
}