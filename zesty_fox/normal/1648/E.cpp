// LUOGU_RID: 92399600
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
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

const int N=4e5+10;

int n,m;
struct Edge{int x,y,w,id;}e[N];
unordered_set<int> to[N];

struct Dsu{
    int f[N];
    int find(int x) {return x==f[x]?f[x]:f[x]=find(f[x]);}
    void init(int n) {iota(f+1,f+n+1,1);}
}d;

array<int,2> ch[N];
int v[N];

void build(){
    d.init(2*n);int tot=n;
    for(int i=1;i<=m;i++){
        int x=d.find(e[i].x),y=d.find(e[i].y);
        if(x==y) continue;
        d.f[x]=d.f[y]=++tot;
        ch[tot]={x,y},v[tot]=e[i].w;
    }
}

vi cp[N];
Dsu cpid;
void merge_cp(int x,int y){
    cpid.f[y]=x;bool rev=0;
    if(cp[x].size()<cp[y].size()) swap(x,y),rev=1;
    cp[x].insert(cp[x].end(),cp[y].begin(),cp[y].end()),cp[y].clear();
    if(rev) cp[x].swap(cp[y]);
}

Dsu d1;
array<int,2> ch1[N];
int tot,v1[N];
set<int> dfs(int x){
    if(x<=n) {cp[x]={x};return {x};}
    auto L=dfs(ch[x][0]),R=dfs(ch[x][1]);
    vi id;
    for(auto idl:L){
        vi tmp;
        for(auto idr:R){
            bool fl=0;
            auto merge = [&](int a,int b,int w){
                a=d1.find(a),b=d1.find(b);
                d1.f[a]=d1.f[b]=++tot,fl=1;
                v1[tot]=w,ch1[tot]={a,b};
            };
            for(auto a:cp[idl]){
                for(auto b:cp[idr])
                    if(!to[a].count(b)){
                        merge(a,b,v[x]);goto ed;
                    }
            }
ed:
            if(fl) tmp.pb(idr);
        }
        if(tmp.empty()) id.pb(0);
        else{
            id.pb(tmp[0]);
            for(int i=1;i<tmp.size();i++) 
                merge_cp(tmp[0],tmp[i]),R.erase(tmp[i]);
        }
    }

    auto it=id.begin();
    for(auto idl:L){
        if(*it) merge_cp(cpid.find(*it),idl);
        else R.insert(idl);
        ++it;
    }
    return R;
}

int f[N][19],dep[N];
inline int lg2(int x) {return !x?-1:__lg(x);}
void dfs1(int x,int fa){
    dep[x]=dep[fa]+1,f[x][0]=fa;
    for(int i=1;i<=lg2(dep[x]);i++) f[x][i]=f[f[x][i-1]][i-1];
    if(x<=n) return;
    dfs1(ch1[x][0],x),dfs1(ch1[x][1],x);
}

int LCA(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=lg2(dep[x]-dep[y]);i>=0;i--)
        if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    if(x==y) return x;
    for(int i=lg2(dep[x]);i>=0;i--)
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}

void solve(){
    sort(e+1,e+m+1,[&](const Edge &a,const Edge &b){return a.w<b.w;});
    build();

    d1.init(2*n),cpid.init(n),tot=n;
    dfs(2*n-1),dfs1(2*n-1,0);

    sort(e+1,e+m+1,[&](const Edge &a,const Edge &b) {return a.id<b.id;});
    for(int i=1;i<=m;i++)
        cout<<v1[LCA(e[i].x,e[i].y)]<<' ';
    cout<<'\n';
}

void solve_once(){
    n=rdi(),m=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi(),w=rdi();
        e[i]={x,y,w,i},to[x].insert(y),to[y].insert(x);
    }
    solve();

    for(int i=1;i<=n;i++)
        to[i].clear();
    for(int i=1;i<2*n;i++){
        for(int j=0;j<=lg2(dep[i]);j++)
            f[i][j]=0;
        dep[i]=0;
    }
}

int main(){
    int T=rdi();
    while(T--) solve_once();
    return 0;
}