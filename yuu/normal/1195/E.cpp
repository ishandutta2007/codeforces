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
#define taskname "E"
int n, m, a, b;
int h[3001][3001];
int f[3001][3001];
ll x, y, z;
ll g[9000001];
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(m);
    read(a);
    read(b);
    read(g[0]);
    read(x);
    read(y);
    read(z);
    int cnt=n*m;
    FOR(i, 1, cnt) g[i]=(g[i-1]*x+y)%z;
    FOR(i, 1, n) FOR(j, 1, m) h[i][j]=g[(i-1)*m+j-1];
    FOR(i, 1, n){
        deque <int> q;
        FOR(j, 1, m){
            while((!q.empty())&&(h[i][j]<=h[i][q.back()])) q.pop_back();
            q.push_back(j);
            while(j-q.front()>=b) q.pop_front();
            if(j>=b) f[i][j-b+1]=h[i][q.front()];
        }
    }
    m=m-b+1;
    FOR(j, 1, m){
        deque <int> q;
        FOR(i, 1, n){
            while((!q.empty())&&(f[i][j]<=f[q.back()][j])) q.pop_back();
            q.push_back(i);
            while(i-q.front()>=a) q.pop_front();
            if(i>=a) h[i-a+1][j]=f[q.front()][j];
        }
    }
    n=n-a+1;
    ll ans=0;
    FOR(i, 1, n) FOR(j, 1, m) ans+=h[i][j];
    writeln(ans);
}