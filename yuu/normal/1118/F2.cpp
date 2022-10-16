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
#define taskname "F2"
int n;
vector <int> g[300001];
int a[300001];
int acs[300001][20];
int h[300001];
#define left Kafuu
#define right Chino
int left[300001];
int right[300001];
bool done[300001];
int bad[300001];
void dfs(int u){
    done[u]=1;
    if(left[a[u]]==0) left[a[u]]=u;
    right[a[u]]=u;
    for(int &v: g[u]) if(done[v]){
        v=g[u].back();
        break;
    }
    if(u!=1) g[u].pop_back();
    for(int i=0; acs[acs[u][i]][i]; i++) acs[u][i+1]=acs[acs[u][i]][i];
    for(int v: g[u]){
        acs[v][0]=u;
        h[v]=h[u]+1;
        dfs(v);
    }
}
const ll base=998244353;
int lca(int u, int v){
    if(h[u]<h[v]) swap(u, v);
    DFOR(i, __lg(h[u]), 0) if(h[acs[u][i]]>=h[v]) u=acs[u][i];
    if(u==v) return u;
    DFOR(i, __lg(h[u]), 0) if(acs[u][i]!=acs[v][i]){
        u=acs[u][i];
        v=acs[v][i];
    }
    return acs[u][0];
}
ll f[300001][3];///0: no cut needed, 1: x[i] is not done, 2: cut needed but done
int x[300001];
void dp(int u){
    if(g[u].empty()){
        if(a[u]==0) f[u][0]=1;
        else{
            if(bad[a[u]]==h[u]) f[u][2]=1;
            else{
                f[u][1]=1;
                x[u]=a[u];
            }
        }
    }
    else{
        for(int v: g[u]) dp(v);
        set <int> dx;
        for(int v: g[u]) if(x[v]){
            dx.insert(x[v]);
            if(dx.size()>1){
                puts("0");
                exit(0);
            }
        }
        if(a[u]) dx.insert(a[u]);
        if(dx.size()>1){
            puts("0");
            exit(0);
        }
        else if(dx.empty()){
            f[u][0]=1;
            for(int v: g[u]){
                f[u][2]=(f[u][2]*(f[v][0]+f[v][2])+f[u][0]*f[v][2])%base;
                f[u][0]=(f[u][0]*(f[v][0]+f[v][2]))%base;
            }
        }
        else{
            ll temp=1;
            for(int v: g[u]) if(x[v]==0) temp=(temp*(f[v][0]+f[v][2]))%base; else temp=(temp*f[v][1])%base;
            x[u]=*dx.begin();
            if(bad[x[u]]==h[u]){
                x[u]=0;
                f[u][2]=temp;
            }
            else f[u][1]=temp;
        }
    }
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    int k;
    read(k);
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
    FOR(i, 1, k) bad[i]=h[lca(left[i], right[i])];///can't cut anything contain i until this height
    dp(1);
//    FOR(i, 1, n){
//        bug(i);
//        cerr<<f[i][0]<<' '<<f[i][1]<<' '<<f[i][2]<<' '<<x[i]<<'\n';
//    }
    writeln(f[1][2]);
}