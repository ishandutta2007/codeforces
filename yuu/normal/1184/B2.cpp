#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
#define __builtin_popcount __builtin_popcountll
using ll=long long; using ld=long double;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); const ld pi=acos(0)*2;
template <typename T> inline void read(T &x){char c; bool nega=0; while((!isdigit(c=getchar()))&&(c!='-')); if(c=='-'){nega=1; c=getchar();} x=c-48; while(isdigit(c=getchar())) x=x*10+c-48; if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10); putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){ putchar('-'); x=-x;} writep(x);}
template <typename T> inline void writeln(T x){write(x); putchar('\n');}
template <typename CT, typename T> inline void reset_container(CT &c, int sz, T v){c.resize(sz); for(auto &x: c) x=v;}
#define taskname "B2"
int n, m;
int c[101][101];
ll s, b, k, h;
class ship{
public:
    int x, a, f;
    void input(){
        read(x);
        read(a);
        read(f);
    }
} S[1001];
class base{
public:
    int x, d;
    void input(){
        read(x);
        read(d);
    }
} B[1001];
vector <int> g[1001];
int done[1001];
int t;
int match[1001];
bool dfs(int u){
    if(done[u]==t) return 0;
    done[u]=t;
    for(int v: g[u]) if(!match[v]){
        match[v]=u;
        return 1;
    }
    for(int v: g[u]) if(dfs(match[v])){
        match[v]=u;
        return 1;
    }
    return 0;
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(m);
    FOR(i, 1, n) FOR(j, 1, n) if(i!=j) c[i][j]=(1e9)+420;
    FOR(i, 1, m){
        int u, v;
        read(u);
        read(v);
        if(u!=v) c[u][v]=c[v][u]=1;
    }
    FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) c[i][j]=min(c[i][j], c[i][k]+c[k][j]);
    read(s);
    read(b);
    read(k);
    read(h);
    FOR(i, 1, s) S[i].input();
    FOR(i, 1, b) B[i].input();
    FOR(i, 1, s) FOR(j, 1, b) if((S[i].f>=c[S[i].x][B[j].x])&&(S[i].a>=B[j].d)) g[i].pb(j);
    int res=0;
    FOR(i, 1, s){
        t++;
        res+=dfs(i);
    }
    int free=s-res;
    writeln(min(k*res, h*(res+free)));
}