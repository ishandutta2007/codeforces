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
#define taskname "C"
int n, m, h;
vector <int> g[100001];
int t[100001];
int comp[100001];
vector <int> s[100001];
int cc=0;
namespace kosaraju{
    vector <int> order;
    vector <int> rg[100001];
    bool done[100001];
    void dfs(int u){
        done[u]=1;
        for(int v: g[u]) if(!done[v]) dfs(v);
        order.pb(u);
    }
    void dfs(int u, int c){
        comp[u]=c;
        s[c].pb(u);
        for(int v: rg[u]) if(!comp[v]) dfs(v, c);
    }
    void solve(){
        FOR(u, 1, n) for(int v: g[u]) rg[v].pb(u);
        FOR(i, 1, n) if(!done[i]) dfs(i);
        reverse(order.begin(), order.end());
        FOR(i, 1, n) if(!comp[i]) dfs(i, ++cc);
    }
}
namespace tarjan{
    int num[100001];
    int low[100001];
    int done[100001];
    int cnt;
    vector <int> a;
    void dfs(int u){
        done[u]=1;
        cnt++;
        num[u]=low[u]=cnt;
        a.pb(u);
        for(int v: g[u]) if(!done[v]){
            dfs(v);
            low[u]=min(low[u], low[v]);
        }
        else if(done[v]!=2) low[u]=min(low[u], num[v]);
        if(low[u]==num[u]){
            int v;
            cc++;
            while(true){
                v=a.back();
                a.pop_back();
                comp[v]=cc;
                s[cc].pb(v);
                if(v==u) break;
            }
        }
    }
    void solve(){
        FOR(i, 1, n) if(!done[i]) dfs(i);
    }
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(m);
    read(h);
    FOR(i, 1, n) read(t[i]);
    {
        int u, v;
        FOR(i, 1, m){
            read(u);
            read(v);
            if((t[u]+1)%h==t[v]) g[u].pb(v);
            if((t[v]+1)%h==t[u]) g[v].pb(u);
        }
    }
    tarjan::solve();
    int best=0;
    FOR(i, 1, cc){
        for(int u: s[i]) for(int v: g[u]) if(comp[v]!=comp[u]) goto line0;
        if(!best) best=i;
        else if(s[i].size()<s[best].size()) best=i;
        line0:;
    }
    writeln(s[best].size());
    for(int x: s[best]) write(x), putchar(' ');
}