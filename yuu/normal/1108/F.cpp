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
class edge{
public:
    int u, v, w;
    void input(){
        read(u);
        read(v);
        read(w);
    }
};
int n, m;
vector <edge> e;
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
    read(m);
    e.resize(m);
    for(auto &x: e) x.input();
    sort(e.begin(), e.end(), [](edge A, edge B){
        return A.w<B.w;
    });
    FOR(i, 1, n) r[i]=-1;
    int ans=0;
    FFOR(i, 0, m){
        int j=i;
        while((j+1<m)&&(e[j+1].w==e[j].w)) j++;
        int cost=j-i+1;
        FOR(k, i, j) if(root(e[k].u)==root(e[k].v)) cost--;
        FOR(k, i, j) if(unite(e[k].u, e[k].v)) cost--;
        ans+=cost;
        i=j;
    }
    writeln(ans);
}