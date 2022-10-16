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
#define taskname "B"
int n;
vector <int> g[200001];
bool done[200001];
void dfs(int u){
    done[u]=1;
    for(int &v: g[u]) if(done[v]){
        swap(v, g[u].back());
        g[u].pop_back();
        break;
    }
    for(int v: g[u]) dfs(v);
}
ll f[200001];
const ll base=998244353;
ll fact[200001];
ll inv[200001];
ll power(ll a, ll b){
    if(b==0) return 1;
    ll t=power(a, b/2);
    t=(t*t)%base;
    if(b%2) t=(t*a)%base;
    return t;
}
void dp(int u){
    if(g[u].empty()) f[u]=1;
    else{
        for(int v: g[u]) dp(v);
        f[u]=1;
        for(int v: g[u]) f[u]=(f[u]*f[v])%base;
        if(u>1) f[u]=(f[u]*fact[g[u].size()+1])%base;
        else f[u]=(f[u]*fact[g[u].size()])%base;
    }
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    fact[0]=1;
    FOR(i, 1, n) fact[i]=(fact[i-1]*i)%base;
//    inv[n]=power(fact[n], base-2);
//    DFOR(i, n, 1) inv[i-1]=(inv[i]*i)%base;
    {
        int u, v;
        FFOR(i, 1, n){
            read(u);
            read(v);
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    dfs(1);
    dp(1);
    writeln((f[1]*n)%base);

//    ll ans=1;
//    FOR(i, 1, n) ans=(ans*fact[g[i].size()])%base;
//    writeln(ans);
}