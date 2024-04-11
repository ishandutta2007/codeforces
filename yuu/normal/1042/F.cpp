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
#define taskname "F"
int n, k;
int ans;
int f[1000001];
bool done[1000001];
vector <int> g[1000001];
void dfs(int u){
    done[u]=1;
    for(int &v: g[u]) if(done[v]){
        swap(v, g[u].back());
        g[u].pop_back();
        break;
    }
    for(int v: g[u]) dfs(v);
    sort(g[u].begin(), g[u].end(), [](int x, int y){
       return f[x]<f[y];
    });
    while((g[u].size()>=2)&&(f[g[u].back()]+f[g[u][g[u].size()-2]]+2>k)){
        ans++;
        g[u].pop_back();
    }
    if(g[u].empty()) return;
    else if(f[g[u].back()]>k){
        ans++;
        f[u]=-1e9;
    }
    else f[u]=f[g[u].back()]+1;
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(k);
    {
        int u, v;
        FFOR(i, 1, n){
            read(u);
            read(v);
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    int root=1;
    FOR(i, 1, n) if(g[i].size()>1){
        root=i;
        break;
    }
    dfs(root);
    if(f[root]>=0) ans++;
    writeln(ans);
}