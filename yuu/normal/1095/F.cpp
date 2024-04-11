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
using ll=long long;
using ld=long double;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "F"
int n, m;
class edge{
public:
    int u, v;
    ll w;
    void input(){
        read(u);
        read(v);
        read(w);
    }
    edge(int u, int v, ll w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
    edge(){}
};
vector <edge> e;
ll a[200001];
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
    FOR(i, 1, n) read(a[i]);
    e.resize(m);
    for(auto &x: e) x.input();
    int mi=1;
    FOR(i, 2, n) if(a[i]<a[mi]) mi=i;
    FOR(i, 1, n) e.pb(edge(i, mi, a[i]+a[mi]));
    sort(e.begin(), e.end(), [](edge A, edge B){
        return A.w<B.w;
    });
    FOR(i, 1, n) r[i]=-1;
    ll ans=0;
    for(auto i: e) if(unite(i.u, i.v)) ans+=i.w;
    writeln(ans);
}