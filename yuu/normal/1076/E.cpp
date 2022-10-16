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
int n;
bool done[300001];
int h[300001];
vector <int> g[300001];
void dfs(int u){
    done[u]=1;
    for(int v: g[u]) if(!done[v]){
        h[v]=h[u]+1;
        dfs(v);
    }
}
vector <pair <int, int>> q[300001];
ll ft[300001];
void update(int u, ll x){
    for(; u<=n; u+=u&-u) ft[u]+=x;
}
ll get(int u){
    ll res=0;
    for(; u>0; u-=u&-u) res+=ft[u];
    return res;
}
ll ans[300001];
void cal(int u){
    for(pair <int, int> d :q[u]){
        update(h[u], d.second);
        update(h[u]+d.first+1, -d.second);
    }
    ans[u]=get(h[u]);
    for(int v: g[u]) if(h[v]>h[u]) cal(v);
    for(pair <int, int> d :q[u]){
        update(h[u], -d.second);
        update(h[u]+d.first+1, d.second);
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
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
    {
        int m, v, d, x;
        read(m);
        FOR(i, 1, m){
            read(v);
            read(d);
            read(x);
            q[v].pb(mp(d, x));
        }
    }
    cal(1);
    FOR(i, 1, n){
        write(ans[i]);
        putchar(" \n"[i==n]);
    }
}