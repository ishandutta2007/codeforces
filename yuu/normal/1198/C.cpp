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
#define taskname "C"
int n, m;
bool done[300001];
vector <vector <pair <int, int>>> path;
vector <pair <int, int>> g[300001];
vector <pair <int, int>> now;
void dfs(int u, int f){
    done[u]=1;
    now.pb(mp(u, f));
    for(auto v: g[u]) if(!done[v.first]){
        dfs(v.first, v.second);
        break;
    }
}
void solve(){
    path.clear();
    read(n);
    FOR(i, 1, n*3) g[i].clear();
    FOR(i, 1, n*3) done[i]=0;
    read(m);
    {
        int u, v;
        FOR(i, 1, m){
            read(u);
            read(v);
            g[u].pb(mp(v, i));
            g[v].pb(mp(u, i));
        }
    }
    FOR(i, 1, n*3) if(!done[i]){
        now.clear();
        dfs(i, 0);
        path.pb(now);
    }
    if(path.size()>=n){
        puts("IndSet");
        FFOR(i, 0, n){
            write(path[i].back().first);
            putchar(" \n"[i+1==n]);
        }
    }
    else{
        puts("Matching");
        int cnt=0;
        for(auto &v: path){
            for(int j=1; j<v.size(); j+=2){
                cnt++;
                write(v[j].second);
                putchar(" \n"[cnt==n]);
                if(cnt==n) break;
            }
            if(cnt==n) break;
        }
    }
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    int t;
    read(t);
    while(t--) solve();
}