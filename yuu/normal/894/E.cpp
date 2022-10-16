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
#define taskname "E"
int n, m, s;
struct edge{
    int x, y;
    ll w;
} e[1000001];
vector <int> g[1000001];
vector <int> v;
int num[1000001];
int low[1000001];
int done[1000001];
int cnt;
int c[1000001];
ll d[1000001];
int cc;
void dfs(int u){
    done[u]=1;
    cnt++;
    num[u]=low[u]=cnt;
    v.pb(u);
    for(int v: g[u]) if(!done[v]){
        dfs(v);
        low[u]=min(low[u], low[v]);
    }
    else if(done[v]!=2) low[u]=min(low[u], num[v]);
    if(num[u]==low[u]){
        cc++;
        while(v.back()!=u){
            c[v.back()]=cc;
            done[v.back()]=2;
            v.pop_back();
        }
        c[v.back()]=cc;
        done[v.back()]=2;
        v.pop_back();
    }
}
ll cost(ll w){
    ll l=0, r=w, res, m;
    while(l<=r){
        m=(l+r)/2;
        if(m*(m+1)/2<=w){
            res=m;
            l=m+1;
        }
        else r=m-1;
    }
    return w*(res+1)-(res*(res+1)*(res+2))/6;
}
vector <pair <int, ll> > h[1000001];
bool df[1000001];
ll f[1000001];
ll F(int u){
    if(df[u]) return f[u];
    df[u]=1;
    f[u]=-1e18;
    for(pair <int, ll> p: h[u]) f[u]=max(f[u], p.second+F(p.first));
    f[u]+=d[u];
    return f[u];
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(m);
    FOR(i, 1, m){
        read(e[i].x);
        read(e[i].y);
        read(e[i].w);
        g[e[i].x].pb(e[i].y);
    }
    read(s);
    dfs(s);
    FOR(i, 1, m){
        if(c[e[i].x]==0||c[e[i].y]==0) continue;
        if(c[e[i].x]==c[e[i].y]) d[c[e[i].x]]+=cost(e[i].w);
        else h[c[e[i].y]].pb(mp(c[e[i].x], e[i].w));
    }
    df[c[s]]=1;
    f[c[s]]=d[c[s]];
    ll ans=-1e18;
    FOR(i, 1, cc) ans=max(ans, F(i));
    writeln(ans);
}