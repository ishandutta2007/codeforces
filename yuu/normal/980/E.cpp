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
#define taskname "E"
int n, k;
vector <int> g[1000001];
bool done[1000001];
int f[1000001][21];
int h[1000001];
bool chosen[1000001];
void dfs(int u){
    done[u]=1;
    for(int i=0; f[f[u][i]][i]; i++) f[u][i+1]=f[f[u][i]][i];
    for(int v: g[u]) if(!done[v]){
        h[v]=h[u]+1;
        f[v][0]=u;
        dfs(v);
    }
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(k);
    {
        int a, b;
        FFOR(i, 1, n){
            read(a);
            read(b);
            g[a].pb(b);
            g[b].pb(a);
        }
    }
    h[n]=1;
    dfs(n);
    chosen[n]=1;
    chosen[0]=1;
    int remain=n-k-1;
    DFOR(i, n-1, 1){
        if(chosen[i]) continue;
        int u=i;
        DFOR(l, __lg(h[u]), 0) if(!chosen[f[u][l]]) u=f[u][l];
        u=f[u][0];
        if(h[i]-h[u]>remain) continue;
        remain-=h[i]-h[u];
        int v=i;
        while(v!=u){
            chosen[v]=1;
            v=f[v][0];
        }
        if(remain==0) break;
    }
    FOR(i, 1, n) if(!chosen[i]) write(i), putchar(' ');
}