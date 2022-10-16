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
#define taskname "F"
class edge{
public:
    int u, v, x;
    edge(int u, int v){
        this->u=u;
        this->v=v;
        x=u^v;
    }
};
vector <edge> e;
vector <int> g[1000001];
bool done[2000001];
bool visited[1000001];
bool chosen[2000001];
int n, m;
vector <int> odd;
vector <int> path;
void dfs(int u){
    while(!g[u].empty()){
        while((!g[u].empty())&&(done[g[u].back()])) g[u].pop_back();
        if(g[u].empty()) return;
        int id=g[u].back();
        g[u].pop_back();
        done[id]=1;
        int v=u^e[id].x;
        dfs(v);
        path.pb(id);
    }
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(m);
    {
        int u, v;
        FFOR(i, 0, m){
            read(u);
            read(v);
            g[u].pb(i);
            g[v].pb(i);
            e.pb(edge(u, v));
        }
    }
    FOR(i, 1, n) if(g[i].size()%2) odd.pb(i);
//    bug(odd.size());
    while(!odd.empty()){
        int u=odd.back();
        odd.pop_back();
        int v=odd.back();
        odd.pop_back();
        g[u].pb(e.size());
        g[v].pb(e.size());
        e.pb(edge(u, v));
    }
    FOR(i, 1, n) while(!g[i].empty()){
        path.clear();
        dfs(i);
//        bug(path.size());
//        FFOR(j, 0, path.size()){
//
//            bug(j);
//            bug(path[j]);
//        }
        for(int j=0; j<path.size(); j+=2){
            if(path[j]>=m) j--;
            if(j>=0) chosen[path[j]]=1;
        }
    }
    int cnt=0;
    FFOR(i, 0, m) if(chosen[i]) cnt++;
    writeln(cnt);
    FFOR(i, 0, m) if(chosen[i]){
        write(e[i].u);
        putchar(' ');
        writeln(e[i].v);
    }
}