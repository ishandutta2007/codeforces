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
int n, m;
vector <int> g[300001];
int cnt;
int num[300001];
int low[300001];
int p[300001];
void dfs(int u){
    cnt++;
    num[u]=low[u]=cnt;
    for(int v: g[u]) if(!num[v]){
        p[v]=u;
        dfs(v);
        low[u]=min(low[u], low[v]);
    }
    else if(v!=p[u]) low[u]=min(low[u], num[v]);
}
int r[300001];
int root(int u){
    if(r[u]<0) return u;
    return r[u]=root(r[u]);
}
void joint(int u, int v){
    u=root(u);
    v=root(v);
    if(u==v) return;
    if(r[u]>r[v]) swap(u, v);
    r[u]+=r[v];
    r[v]=u;
}
vector <pair <int, int> > edge;
vector <int> h[300001];
queue <int> q;
bool done[300001];
int f[300001];
int bfs(int u){
    FOR(i, 1, n) done[i]=0;
    q.push(u);
    done[u]=1;
    f[u]=0;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int v: h[u]) if(!done[v]){
            f[v]=f[u]+1;
            done[v]=1;
            q.push(v);
        }
    }
    return u;
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    {
        int u, v;
        FOR(i, 1, m){
            read(u);
            read(v);
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    dfs(1);
    FOR(i, 1, n) r[i]=-1;
    FOR(u, 1, n) for(int v: g[u]) if((p[v]==u)){
        if(low[v]>num[u]) edge.pb(mp(u, v));
        else joint(u, v);
    }
    for(auto p: edge){
        h[root(p.first)].pb(root(p.second));
        h[root(p.second)].pb(root(p.first));
    }
    writeln(f[bfs(bfs(root(1)))]);
}