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
vector <int> g[300001];
int p[300001];
bool done[300001];
int num[300001];
int low[300001];
int cnt=0;
void dfs(int u){
    done[u]=1;
    cnt++;
    num[u]=low[u]=cnt;
    for(int v: g[u]) if(!done[v]){
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
void uni(int u, int v){
    u=root(u);
    v=root(v);
    if(u!=v){
        if(r[u]>r[v]) swap(u, v);
        r[u]+=r[v];
        r[v]=u;
    }
}
bool good[300001];
vector <pair <int, bool> > h[300001];
class edge{
public:
    int x, y;
    bool z;
    void input(){
        read(x);
        read(y);
        read(z);
        g[x].pb(y);
        g[y].pb(x);
    }
    void process(){
        x=root(x);
        y=root(y);
        if(x!=y){
            h[x].pb(mp(y, z));
            h[y].pb(mp(x, z));
        }
        else if(z) good[x]=1;
    }
} e[300001];
int a, b;
void find_path(int u, bool now){
    done[u]=1;
    now=now||good[u];
    if(u==b){
        puts(now?"YES":"NO");
        exit(0);
    }
    for(pair <int, bool> v: h[u]) if(!done[v.first]) find_path(v.first, now||v.second);
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    FOR(i, 1, m) e[i].input();
    dfs(1);
    FOR(i, 1, n) r[i]=-1;
    FOR(u, 1, n) for(int v: g[u]) if(p[v]==u) if(low[v]<=num[u]) uni(u, v);
    FOR(i, 1, m) e[i].process();
    read(a);
    read(b);
    a=root(a);
    b=root(b);
    FOR(i, 1, n) done[i]=0;
    find_path(a, 0);
}