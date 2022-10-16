#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
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
#define taskname "G"
vector <pair <int, int> > g[300001];
int a[300001];
int w[300001];
ll f[300001];
ll sp[300001][20];
ll up[300001];
int acs[300001][20];
int h[300001];
bool done[300001];
int n, q;
void dfs(int u){
    done[u]=1;
    for(pair <int, int> &v: g[u]) if(done[v.first]){
        w[u]=v.second;
        swap(v, g[u].back());
        g[u].pop_back();
        break;
    }
    f[u]=a[u];
    for(pair <int, int> v: g[u]){
        acs[v.first][0]=u;
        dfs(v.first);
        f[u]+=max(0LL, f[v.first]-v.second*2);
    }
    for(pair <int, int> v: g[u]) sp[v.first][0]=f[u]-max(0LL, f[v.first]-v.second*2);
}
void prepare(int u){
    sp[u][0]+=-w[u];
    for(int i=0; acs[acs[u][i]][i]; i++){
        acs[u][i+1]=acs[acs[u][i]][i];
        sp[u][i+1]=sp[u][i]+sp[acs[u][i]][i];
    }
    for(pair <int, int> v: g[u]){
        up[v.first]=up[u]+sp[v.first][0]-w[v.first]*2;
        up[v.first]=max(up[v.first], 0LL);
        h[v.first]=h[u]+1;
        prepare(v.first);
    }
}
ll query(int u, int v){
    if(u==v){
        return f[u]+up[u];
    }
    if(h[u]<h[v]) swap(u, v);
    ll ans=f[u];
    DFOR(i, __lg(h[u]), 0){
        if(h[acs[u][i]]>=h[v]){
            ans+=sp[u][i];
            u=acs[u][i];
        }
    }
    if(u==v){
        ans+=up[u];
        return ans;
    }
    else{
        ans+=f[v];
        DFOR(i, __lg(h[u]), 0){
            if(acs[u][i]!=acs[v][i]){
                ans+=sp[u][i];
                ans+=sp[v][i];
                u=acs[u][i];
                v=acs[v][i];
            }
        }
        ans+=f[acs[u][0]]-max(0LL, f[v]-w[v]*2)-max(0LL, f[u]-w[u]*2);
        ans+=-w[u]-w[v];
        ans+=up[acs[u][0]];
        return ans;
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(q);
    FOR(i, 1, n) read(a[i]);
    {
        int u, v, w;
        FFOR(i, 1, n){
            read(u);
            read(v);
            read(w);
            g[u].pb(mp(v, w));
            g[v].pb(mp(u, w));
        }
    }
    dfs(1);
    h[1]=1;
    prepare(1);
//    FOR(i, 1, n) cerr<<f[i]<<" \n"[i==n];
//    FOR(i, 1, n) cerr<<sp[i][0]<<" \n"[i==n];
//    FOR(i, 1, n) cerr<<up[i]<<" \n"[i==n];
    {
        int u, v;
        FOR(i, 1, q){
            read(u);
            read(v);
            writeln(query(u, v));
        }
    }
}