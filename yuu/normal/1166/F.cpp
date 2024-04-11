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
#define taskname "F"
map <int, vector <int> > g[100001];
vector <int> child[100001];
set <int> s[100001];
int r[100001];
int n, m, c, q;
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
    for(int x: child[v]){
        for(auto p: g[x]) for(auto a: p.second){
            s[a].erase(v);
            s[a].insert(u);
        }
        child[u].pb(x);
    }
    child[v].clear();
    return 1;
}

int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(m);
    read(c);
    read(q);
    {
        int x, y, z;
        FOR(i, 1, m){
            read(x);
            read(y);
            read(z);
            g[x][z].pb(y);
            g[y][z].pb(x);
        }
    }
    FOR(i, 1, n) r[i]=-1;
    FOR(i, 1, n) child[i].pb(i);
    FOR(i, 1, n) for(auto p: g[i]) for(auto a: p.second) s[i].insert(a);
    FOR(i, 1, n) for(auto p: g[i]) FFOR(j, 1, p.second.size()) unite(p.second[j], p.second[j-1]);
    {
        char c;
        int x, y, z;
        FOR(i, 1, q){
            while(c=getchar()) if(c=='+'||c=='?') break;
            read(x);
            read(y);
            if(c=='+'){
                read(z);
                g[x][z].pb(y);
                g[y][z].pb(x);
                s[x].insert(root(y));
                s[y].insert(root(x));
                if(g[x][z].size()>1) unite(g[x][z][g[x][z].size()-2], y);
                if(g[y][z].size()>1) unite(g[y][z][g[y][z].size()-2], x);
            }
            else{
                if(root(x)==root(y)) puts("Yes");
                else if(s[y].find(root(x))!=s[y].end()) puts("Yes");
                else puts("No");
            }
        }
    }
}