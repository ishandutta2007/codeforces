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
#define taskname "B"
bool s[200001];
int f[200001];
int p[200001];
bool done[200001];
int n, k;
vector <int> g[200001];
void dfs2(int u){
    done[u]=1;
    for(int v: g[u]) if(!done[v]){
        f[v]=f[u]+1;
        dfs2(v);
    }
}
void ans(int u){
    FOR(i, 1, n) done[i]=f[i]=0;
    dfs2(u);
    ll res=0;
    FOR(i, 1, n) if(s[i]) res+=f[i];
    write(res);
    exit(0);
}
void dfs(int u){
    done[u]=1;
    for(int v: g[u]) if(!done[v]){
        dfs(v);
        f[u]+=f[v];
    }
    else p[u]=v;
    f[u]+=s[u];
    if(f[u]<k) return;
    for(int v: g[u]) if(p[u]!=v) if(f[v]>k) return;
    ans(u);
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    read(k);
    FOR(i, 1, k){
        int u;
        read(u); s[u]=1;
        read(u); s[u]=1;
    }
    FOR(i, 2, n){
        int x, y;
        read(x);
        read(y);
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1);
}