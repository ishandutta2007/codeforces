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
typedef long long ll;
typedef long double ld;
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
#define taskname "E"
int n, q;
ll a[100001];
vector <int> g[100001];
int c;
int pos[100001];
int last[100001];
int base[100001];
int f[100001][21];
int h[100001];
void dfs(int u){
    c++;
    pos[u]=c;
    base[c]=u;
    for(int i=0; f[f[u][i]][i]; i++) f[u][i+1]=f[f[u][i]][i];
    for(int v: g[u]) if(!pos[v]){
        f[v][0]=u;
        h[v]=h[u]+1;
        dfs(v);
    }
    last[u]=c;
}
inline int lca(int u, int v){
    if(h[u]<h[v]) swap(u, v);
    int i=__lg(h[u]);
    while(i>=0){
        if(h[f[u][i]]>=h[v]) u=f[u][i];
        i--;
    }
    if(u==v) return u;
    i=__lg(h[u]);
    while(i>=0){
        if(f[u][i]!=f[v][i]){
            u=f[u][i];
            v=f[v][i];
        }
        i--;
    }
    return f[u][0];
}
#define ischild(u, v) ((pos[v]<=pos[u])&&(last[v]>=pos[u]))
//inline int first(int u, int v, int r){
//    if(ischild(v, r)) swap(u, v);
//    if(ischild(u, r)){
//        if(ischild(v, r)) return lca(u, v);
//        return r;
//    }
//    int ur=lca(u, r);
//    int vr=lca(v, r);
//    if(ischild(ur, vr)) return ur;
//    return vr;
//}

int first(int u, int v, int r){
    int uv=lca(u, v);
    int ur=lca(r, u);
    int vr=lca(r, v);
    if(lca(r, uv)!=uv)
        return uv;
    else{
        if(vr==uv&&uv==ur)
            return uv;
        else{
            if(ur!=uv)
                return ur;
            else return vr;
        }
    }
}
class segment_tree{
    public: typedef segment_tree* iterator;
    iterator left, right;
    ll value, lazy;
    int l, r, m;
    segment_tree (int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        lazy=0;
        left=right=nullptr;
        if(l==r) value=a[base[l]];
        else{
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
            value=left->value+right->value;
        }
    }
    void down(){
        left->value+=lazy*(m-l+1);
        left->lazy+=lazy;
        right->value+=lazy*(r-m);
        right->lazy+=lazy;
        lazy=0;
    }
    void update(int u, int v, ll x){
        if(l>v||r<u) return;
        if(u<=l&&v>=r){
            value+=x*(r-l+1);
            lazy+=x;
        }
        else{
            down();
            left->update(u, v, x);
            right->update(u, v, x);
            value=left->value+right->value;
        }
    }
    ll get(int u, int v){
        if(l>v||r<u) return 0;
        if(u<=l&&v>=r) return value;
        else{
            down();
            return left->get(u, v)+right->get(u, v);
        }
    }
};
segment_tree::iterator tree;
int root=1;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(q);
    FOR(i, 1, n) read(a[i]);
    {
        int u, v;
        FFOR(i, 1, n){
            read(u);
            read(v);
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    h[1]=1;
    dfs(1);
    tree=new segment_tree(1, n);
    {
        int o, u, v, x;
        FOR(i, 1, q){
            read(o);
            if(o==1) read(root);
            else if(o==2){
                read(u);
                read(v);
                read(x);
                int uv=first(u, v, root);
                if(uv==root) tree->update(1, n, x);
                else if(!ischild(root, uv)) tree->update(pos[uv], last[uv], x);
                else{
                    int r=root;
                    DFOR(j, __lg(h[r]), 0) if(h[f[r][j]]>h[uv]) r=f[r][j];
                    tree->update(1, n, x);
                    tree->update(pos[r], last[r], -x);
                }
            }
            else{
                read(u);
                ll ans;
                if(u==root) ans=tree->get(1, n);
                else if((!ischild(root, u))) ans=tree->get(pos[u], last[u]);
                else{
                    int r=root;
                    DFOR(j, __lg(h[r]), 0) if(h[f[r][j]]>h[u]) r=f[r][j];
                    ans=tree->get(1, n)-tree->get(pos[r], last[r]);
                }
                writeln(ans);
            }
        }
    }
}