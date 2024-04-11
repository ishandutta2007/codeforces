#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
using ll=long long;
using ld=long double;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "827D"
class edge{
public:
    int u, v, c, id;
    bool chosen;
    void input(int id){
        this->id=id;
        read(u);
        read(v);
        read(c);
        chosen=0;
    }
} e[200001];
int r[200001];
int root(int u){
    if(r[u]<0) return u;
    return r[u]=root(r[u]);
}
bool unite(int u, int v){
    u=root(u);
    v=root(v);
    if(u==v) return 0;
    if(r[u]>r[v]) swap(u, v);
    r[u]+=r[v];
    r[v]=u;
    return 1;
}
vector <pair <int, int>> g[200001];
bool done[200001];
int h[200001];
int child[200001];
int f[200001][20];
int w[200001][20];
void dfs(int u){
    done[u]=1;
    for(auto &x: g[u]) if(done[x.first]){
        swap(x, g[u].back());
        g[u].pop_back();
        break;
    }
    child[u]=1;
    for(int i=0; f[f[u][i]][i]; i++){
        f[u][i+1]=f[f[u][i]][i];
        w[u][i+1]=max(w[u][i], w[f[u][i]][i]);
    }
//    bug(u);
//    cerr<<f[u][0]<<' '<<f[u][1]<<' '<<f[u][2]<<'\n';
//    cerr<<w[u][0]<<' '<<w[u][1]<<' '<<w[u][2]<<'\n';
    for(auto &x: g[u]) if(!done[x.first]){
        f[x.first][0]=u;
        w[x.first][0]=e[x.second].c;
        h[x.first]=h[u]+1;
        dfs(x.first);
        child[u]+=child[x.first];
        if(child[x.first]>child[g[u][0].first]) swap(x, g[u][0]);
    }
}
class segment_tree{
public:
    using pointer=segment_tree*;
    int l, r, m;
    int value;
    pointer left, right;
    segment_tree(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        value=1e9+7;
        if(l!=r){
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
        }
    }
    void down(){
        left->value=min(left->value, value);
        right->value=min(right->value, value);
    }
    void update(int u, int v, int x){
        if(l>v||r<u) return;
        else if(u<=l&&v>=r) value=min(value, x);
        else{
            down();
            left->update(u, v, x);
            right->update(u, v, x);
        }
    }
    int get(int u, int v){
        if(l>v||r<u) return 1e9+7;
        else if(u<=l&&v>=r) return value;
        else{
            down();
            return min(left->get(u, v), right->get(u, v));
        }
    }
};
segment_tree::pointer tree[200001];
int head[200001];
//vector <int> chain[200001];
void hld(int u, int hd){
    head[u]=hd;
    if(g[u].empty()){
        tree[hd]=new segment_tree(h[hd], h[u]);
    }
    else{
        hld(g[u][0].first, hd);
        for(auto x: g[u]) if(head[x.first]==0) hld(x.first, x.first);
    }
}
int lca(int u, int v){
    if(h[u]<h[v]) swap(u, v);
    DFOR(i, __lg(h[u]), 0) if(h[f[u][i]]>=h[v]) u=f[u][i];
    if(u==v) return u;
    DFOR(i, __lg(h[u]), 0) if(f[u][i]!=f[v][i]){
        u=f[u][i];
        v=f[v][i];
    }
    return f[u][0];
}
void update_root(int u, int r, int x){
    while(true){
        if(head[u]==head[r]){
            if(h[r]!=h[u]) tree[head[u]]->update(h[r]+1, h[u], x);
            break;
        }
        else{
            tree[head[u]]->update(h[head[u]], h[u], x);
            u=f[head[u]][0];
        }
    }
}
void update(int u, int v, int x){
    int l=lca(u, v);
    update_root(u, l, x);
    update_root(v, l, x);
}
int get_max_edge(int u, int v){
    if(u==v) return 0;
    if(h[u]<h[v]) swap(u, v);
    int res=0;
    DFOR(i, __lg(h[u]), 0) if(h[f[u][i]]>h[v]){
        res=max(res, w[u][i]);
        u=f[u][i];
    }
    res=max(res, w[u][0]);
    if(f[u][0]==v) return res;
    if(h[u]!=h[v]) u=f[u][0];
    DFOR(i, __lg(h[u]), 0) if(f[u][i]!=f[v][i]){
        res=max(res, w[u][i]);
        res=max(res, w[v][i]);
        u=f[u][i];
        v=f[v][i];
    }
    res=max(res, w[u][0]);
    res=max(res, w[v][0]);
    return res;
}
int ans[200001];
void visit(int u){
    for(auto x: g[u]){
        int v=x.first;
        int res=tree[head[v]]->get(h[v], h[v]);
        if(res>1e9) ans[e[x.second].id]=-1;
        else ans[e[x.second].id]=res-1;
        visit(v);
    }
}
int n, m;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    FOR(i, 1, m) e[i].input(i);
    sort(e+1, e+m+1, [](edge A, edge B){
        return A.c<B.c;
    });
    FOR(i, 1, n) r[i]=-1;
    FOR(i, 1, m) if(unite(e[i].u, e[i].v)){
        g[e[i].u].pb(mp(e[i].v, i));
        g[e[i].v].pb(mp(e[i].u, i));
        e[i].chosen=1;
    }
    h[1]=1;
    dfs(1);
    hld(1, 1);
    FOR(i, 1, m) if(!e[i].chosen){
        ans[e[i].id]=get_max_edge(e[i].u, e[i].v)-1;
        update(e[i].u, e[i].v, e[i].c);
    }
    visit(1);
    FOR(i, 1, m){
        write(ans[i]);
        putchar(" \n"[i==m]);
    }
}