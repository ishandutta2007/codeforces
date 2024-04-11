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
#define taskname "D"
int n;
int x[200001];
int y[200001];
int c[200001];
int z[200001];
int o[200001];
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

int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    FFOR(i, 1, n){
        read(x[i]);
        read(y[i]);
        read(c[i]);
    }
    FOR(i, 1, n) r[i]=-1;
    FFOR(i, 1, n) if(c[i]==0) unite(x[i], y[i]);
    FOR(i, 1, n) z[i]=-r[root(i)];
    FOR(i, 1, n) r[i]=-1;
    FFOR(i, 1, n) if(c[i]==1) unite(x[i], y[i]);
    FOR(i, 1, n) o[i]=-r[root(i)];
    ll ans=0;
    FOR(i, 1, n) ans+=1LL*z[i]*o[i];
    writeln(ans-n);
}