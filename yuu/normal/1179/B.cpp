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
#define taskname "B"
deque <pair <int, int>> res;
int n, m;
set <pair <int, int>> v;
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(m);
    #ifdef Aria
        n=rng()%1000+1;
        m=rng()%1000+1;
    #endif // Aria
    FOR(i, 1, n) FOR(j, 1, m) res.pb(mp(i, j));
    bool fr=1;
    pair <int, int> old=mp(1, 1);
    while(!res.empty()){
        pair <int, int> p;
        if(fr){
            p=res.front();
            res.pop_front();
        }
        else{
            p=res.back();
            res.pop_back();
        }
        fr=!fr;
        #ifdef Aria
            pair <int, int> q=mp(p.first-old.first, p.second-old.second);
            assert(v.find(q)==v.end());
            v.insert(q);
        #else
            write(p.first);
            putchar(' ');
            writeln(p.second);
        #endif
    }
}