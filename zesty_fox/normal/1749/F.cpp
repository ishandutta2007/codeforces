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

const int N=2e5+10,D=23;

int n;
vi e[N];

int dep[N],f[N],siz[N],son[N];
void dfs(int x,int fa){
    dep[x]=dep[fa]+1,f[x]=fa,siz[x]=1;
    for(auto y:e[x]){
        if(y==fa) continue;
        dfs(y,x);
        siz[x]+=siz[y];
        if(siz[y]>siz[son[x]]) son[x]=y;
    }
}

int top[N],dfn[N],ti;
void dfs1(int x,int tp){
    top[x]=tp,dfn[x]=++ti;
    if(son[x]) dfs1(son[x],tp);
    for(auto y:e[x]){
        if(y==f[x]||y==son[x]) continue;
        dfs1(y,y);
    }
}

struct BIT{
    i64 sum[D+1][N];
private:
    void _add(int sx,int sy,i64 v){
        for(int x=sx;x<=D;x+=(x&(-x)))
            for(int y=sy;y<=n;y+=(y&(-y)))
                sum[x][y]+=v;
    }
    i64 _query(int sx,int sy){
        i64 ret=0;
        for(int x=sx;x;x-=(x&(-x)))
            for(int y=sy;y;y-=(y&(-y)))
                ret+=sum[x][y];
        return ret;
    }
public:
    void add(int d,int l,int r,i64 v){
        d=D-d;
        _add(d,l,v),_add(d,r+1,-v);
    }
    i64 query(int d,int x){
        d=D-d;
        return _query(d,x);
    }
}t,t1;
// t: exclude heavy son
// t1: all subtree

void add(int x,int y,int d,i64 v){
    int lst1=0,lst2=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y),swap(lst1,lst2);
        t.add(d,dfn[top[x]],dfn[x],v);
        if(d&&son[x]) t1.add(d-1,dfn[son[x]],dfn[son[x]],v);
        if(d&&lst1) t1.add(d-1,dfn[lst1],dfn[lst1],-v);
        lst1=top[x],x=f[top[x]];
    }
    if(dep[x]<dep[y]) swap(x,y),swap(lst1,lst2);
    t.add(d,dfn[y],dfn[x],v);
    if(d&&son[x]) t1.add(d-1,dfn[son[x]],dfn[son[x]],v);
    if(d&&lst1) t1.add(d-1,dfn[lst1],dfn[lst1],-v);
    if(d&&lst2) t1.add(d-1,dfn[lst2],dfn[lst2],-v);

    int nw=f[y];
    for(int i=1,lst=y;nw&&i<=d;i++){
        t.add(d-i,dfn[nw],dfn[nw],v);
        if(lst!=son[nw]){
            if(d-i-1>=0){
                if(lst) t1.add(d-i-1,dfn[lst],dfn[lst],-v);
                if(son[nw]) t1.add(d-i-1,dfn[son[nw]],dfn[son[nw]],v);
            }
        }
        lst=nw,nw=f[nw];
    }
}

i64 query(int x){
    i64 ret=0;
    for(int i=0,lst=-1;x&&i<D;i++){
        ret+=t1.query(i,dfn[x]);
        if(lst!=son[x])
            ret+=t.query(i,dfn[x]);
        lst=x,x=f[x];
    }
    return ret;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        e[x].pb(y),e[y].pb(x);
    }
    dfs(1,0),dfs1(1,1);
    int q=rdi();
    while(q--){
        int op=rdi();
        if(op==1){
            int x=rdi();
            cout<<query(x)<<'\n';
        }
        else{
            int x=rdi(),y=rdi(),v=rdi(),d=rdi();
            add(x,y,d,v);
        }
    }
    return 0;
}