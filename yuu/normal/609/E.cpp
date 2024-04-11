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
#define taskname "E"
int n, m;
vector <pair <int, ll> > g[200001];
class edge{
public:
    int id, u, v;
    ll w;
    bool accepted;
    void input(int id){
        this->id=id;
        read(u);
        read(v);
        read(w);
        accepted=0;
    }
    void accept(){
        g[u].pb(mp(v, w));
        g[v].pb(mp(u, w));
        accepted=1;
    }
};
vector <edge> e;
int r[200001];
int root(int u){
    if(r[u]<0) return u;
    return r[u]=root(r[u]);
}
bool uni(int u, int v){
    u=root(u);
    v=root(v);
    if(u==v) return 0;
    if(r[u]>r[v]) swap(u, v);
    r[u]+=r[v];
    r[v]=u;
    return 1;
}
int h[200001];
bool done[200001];
int acs[200001][20];
ll maxw[200001][20];
void dfs(int u){
    done[u]=1;
    for(int i=0; acs[acs[u][i]][i]; i++){
        acs[u][i+1]=acs[acs[u][i]][i];
        maxw[u][i+1]=max(maxw[u][i], maxw[acs[u][i]][i]);
    }
    for(pair <int, ll> v: g[u]) if(!done[v.first]){
        h[v.first]=h[u]+1;
        acs[v.first][0]=u;
        maxw[v.first][0]=v.second;
        dfs(v.first);
    }
}
ll query(int u, int v){
    if(h[u]<h[v]) swap(u, v);
    ll res=-2e9;
    DFOR(i, __lg(h[u]), 0){
        if(h[acs[u][i]]>=h[v]){
            res=max(res, maxw[u][i]);
            u=acs[u][i];
        }
    }
    if(u==v) return res;
    DFOR(i, __lg(h[u]), 0){
        if(acs[u][i]!=acs[v][i]){
            res=max(res, maxw[u][i]);
            res=max(res, maxw[v][i]);
            u=acs[u][i];
            v=acs[v][i];
        }
    }
    res=max(res, maxw[u][0]);
    res=max(res, maxw[v][0]);
    return res;
}
ll ans[200001];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    e.resize(m);
    FFOR(i, 0, m) e[i].input(i);
    sort(e.begin(), e.end(), [](edge A, edge B){
        return A.w<B.w;
    });
    FOR(i, 1, n) r[i]=-1;
    ll weight=0;
    for(auto t: e) if(uni(t.u, t.v)){
        t.accept();
        weight+=t.w;
    }
    h[1]=1;
    dfs(1);
    for(auto t: e){
        if(t.accepted) ans[t.id]=weight;
        else ans[t.id]=weight+t.w-query(t.u, t.v);
    }
    FFOR(i, 0, m) writeln(ans[i]);
}