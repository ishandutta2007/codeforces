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
#define taskname "D"
int n, m;
vector <int> g[1000001];
vector <int> a[1000001];
vector <ll> s[1000001];
int p[1000001];
ll c[1000001];
ll h[1000001];
void dfs(int u){
    for(int v: g[u]){
        p[v]=u;
        h[v]=h[u]+c[v];
        dfs(v);
    }
    if(g[u].size()==1) a[u]=a[g[u][0]];
    else if(g[u].size()==2){
        a[u].resize(a[g[u][0]].size()+a[g[u][1]].size());
        merge(a[g[u][0]].begin(), a[g[u][0]].end(), a[g[u][1]].begin(), a[g[u][1]].end(), a[u].begin());
    }
    a[u].insert(a[u].begin(), h[u]);
    s[u].pb(a[u][0]);
    FFOR(i, 1, a[u].size()) s[u].pb(s[u].back()+a[u][i]);
}
ll u, l;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(m);
    FFOR(i, 1, n) read(c[i+1]);
    FOR(i, 1, n){
        if(i*2<=n) g[i].pb(i*2);
        if(i*2+1<=n) g[i].pb(i*2+1);
    }
    dfs(1);
    while(m--){
        read(u);
        read(l);
        int ch=h[u];
        ll ans=0;
        int old=0;
        while(u&&(ch-h[u]<=l)){
            ans+=l-(ch-h[u]);
            for(int v: g[u]) if(v!=old){
                ll cmax=l+h[u]*2-ch;
                int i;
                if(a[v].back()<=cmax) i=a[v].size();
                else i=upper_bound(a[v].begin(), a[v].end(), cmax)-a[v].begin();
                i--;
                if(i>=0) ans+=cmax*(i+1)-s[v][i];
            }
            old=u;
            u=p[u];
        }
        writeln(ans);
    }
}