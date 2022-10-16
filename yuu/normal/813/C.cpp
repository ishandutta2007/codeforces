#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
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
#define taskname "C"
int n, x;
vector <int> g[200001];
bool done[200001];
int f[200001];
int h[200001][20];
void dfs(int u){
    done[u]=1;
    for(int i=0; h[h[u][i]][i]; i++)
        h[u][i+1]=h[h[u][i]][i];
    for(int v: g[u]){
        if(!done[v]){
            h[v][0]=u;
            f[v]=f[u]+1;
            dfs(v);
        }
    }
}
int lca(int u, int v){
    if(f[u]<f[v]) swap(u, v);
    int i=19;
    while(i>=0){
        if(f[h[u][i]]>=f[v]) u=h[u][i];
        i--;
    }
    if(u==v) return u;
    i=19;
    while(i>=0){
        if(h[u][i]!=h[v][i]){
            u=h[u][i];
            v=h[v][i];
        }
        i--;
    }
    return h[u][0];
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    read(x);
    FOR(i, 2, n){
        int u, v;
        read(u);
        read(v);
        g[u].pb(v);
        g[v].pb(u);
    }
    f[1]=1;
    dfs(1);
    int ans=0;
    FOR(u, 1, n){
        int q=lca(u, x);
        if(f[x]-f[q]>=f[q]-1) continue;
        ans=max(ans, f[u]-1);
    }
    writeln(ans*2);
}