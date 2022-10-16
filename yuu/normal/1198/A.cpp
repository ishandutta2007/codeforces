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
#define taskname "A"
ll I;
ll sz=1;
int n;
int a[400001];
vector <pair <int, int>> v;
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(I);
    I*=8;
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, 60){
        if((ll(n))*i<=I) sz*=2;
        else break;
    }
    sort(a+1, a+n+1);
    v.pb(mp(-1, 0));
    FOR(i, 1, n) if(v.back().first!=a[i]) v.pb(mp(a[i], 1)); else v.back().second++;
    sz=min(sz, ((ll)v.size())-1);
    FFOR(i, 1, v.size()) v[i].second+=v[i-1].second;
    int f=0;
    FFOR(i, sz, v.size()){
        f=max(f, v[i].second-v[i-sz].second);
    }
    f=n-f;
    writeln(f);
}