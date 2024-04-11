#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
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
#define taskname "B"
int n, m, q;
vector <int> g[200001];
struct edge{
    int u, v;
    ll c;
} e[400001];
bool done[200001];
int l[200001];
int r[200001];
int cnt;
void dfs(int u){
    done[u]=1;
    l[u]=r[u]=++cnt;
    for(int v: g[u]) dfs(v);
    r[u]=cnt;
}
const ll inf=1LL<<55;
struct segment_tree{
    ll t[800001];
    ll lz[800001];
    void update(int i, int l, int r, int u, int v, ll x){
        if(l>v||r<u) return;
        if(u<=l&&v>=r){
            t[i]+=x;
            lz[i]+=x;
        }
        else{
            int m=(l+r)/2;
            t[2*i]+=lz[i];
            t[2*i+1]+=lz[i];
            lz[2*i]+=lz[i];
            lz[2*i+1]+=lz[i];
            lz[i]=0;
            update(2*i, l, m, u, v, x);
            update(2*i+1, m+1, r, u, v, x);
            t[i]=min(t[2*i], t[2*i+1]);
        }
    }
    ll get(int i, int l, int r, int u, int v){
        if(l>v||r<u) return inf;
        if(u<=l&&v>=r) return t[i];
        else{
            int m=(l+r)/2;
            t[2*i]+=lz[i];
            t[2*i+1]+=lz[i];
            lz[2*i]+=lz[i];
            lz[2*i+1]+=lz[i];
            lz[i]=0;
            return min(get(2*i, l, m, u, v), get(2*i+1, m+1, r, u, v));
        }
    }
    ll getelement(int i, int l, int r, int u){
        if(l==r) return t[i];
        else{
            int m=(l+r)/2;
            t[2*i]+=lz[i];
            t[2*i+1]+=lz[i];
            lz[2*i]+=lz[i];
            lz[2*i+1]+=lz[i];
            lz[i]=0;
            if(m>=u) return getelement(2*i, l, m, u);
            else return getelement(2*i+1, m+1, r, u);
        }
    }
} dist, toroot;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(q);
    m=2*n-2;
    FOR(i, 1, m){
        read(e[i].u);
        read(e[i].v);
        read(e[i].c);
    }
    FFOR(i, 1, n) g[e[i].u].pb(e[i].v);
    dfs(1);
    FFOR(i, 1, n){
        dist.update(1, 1, n, l[e[i].v], r[e[i].v], e[i].c);
        toroot.update(1, 1, n, l[e[i].v], r[e[i].v], e[i].c);
    }
    FOR(i, n, m) toroot.update(1, 1, n, l[e[i].u], l[e[i].u], e[i].c);
    int o, u, v;
    ll c;
    FOR(i, 1, q){
        read(o);
        read(u);
        if(o==1){
            read(c);
            if(u<n){
                dist.update(1, 1, n, l[e[u].v], r[e[u].v], c-e[u].c);
                toroot.update(1, 1, n, l[e[u].v], r[e[u].v], c-e[u].c);
            }
            else toroot.update(1, 1, n,  l[e[u].u], l[e[u].u], c-e[u].c);
            e[u].c=c;
        }
        else{
            read(v);
            if(l[u]<=l[v]&&r[u]>=l[v]) writeln(dist.getelement(1, 1, n, l[v])-dist.getelement(1, 1, n, l[u]));
            else writeln(toroot.get(1, 1, n, l[u], r[u])-dist.getelement(1, 1, n, l[u])+dist.getelement(1, 1, n, l[v]));
        }
    }
}