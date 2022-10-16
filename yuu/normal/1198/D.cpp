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
#define taskname "D"
int n;
int s[51][51];
int f[51][51][51][51];
bool done[51][51][51][51];
int F(int u, int v, int x, int y){
    if(done[u][v][x][y]) return f[u][v][x][y];
    done[u][v][x][y]=1;
    if(s[x][y]-s[u-1][y]-s[x][v-1]+s[x-1][y-1]==0) return f[u][v][x][y]=0;
    f[u][v][x][y]=max(x-u+1, y-v+1);
    FFOR(i, u, x) f[u][v][x][y]=min(f[u][v][x][y], F(u, v, i, y)+F(i+1, v, x, y));
    FFOR(i, v, y) f[u][v][x][y]=min(f[u][v][x][y], F(u, v, x, i)+F(u, i+1, x, y));
    return f[u][v][x][y];
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
//    int ans=0;
//    FOR(i, 1, 50) FOR(j, i, 50) FOR(k, 1, 50) FOR(l, k, 50){
//        ans+=(j-i+1);
//        ans+=(l-k+1);
//    }
    read(n);
    FOR(i, 1, n) FOR(j, 1, n){
        char c;
        cin>>c;
        if(c=='#') s[i][j]=1;
    }
    FOR(i, 1, n) FOR(j, 1, n) s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
    writeln(F(1, 1, n, n));
}