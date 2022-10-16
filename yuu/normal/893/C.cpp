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
#define taskname "C"
int n, m;
int c[100001];
bool done[100001];
vector <int> g[100001];
int x, y;
int cost;
void dfs(int u){
    done[u]=1;
    cost=min(cost, c[u]);
    for(int v: g[u]) if(!done[v]) dfs(v);
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(m);
    FOR(i, 1, n) read(c[i]);
    FOR(i, 1, m){
        read(x);
        read(y);
        g[x].pb(y);
        g[y].pb(x);
    }
    ll ans=0;
    FOR(i, 1, n) if(!done[i]){
        cost=c[i];
        dfs(i);
        ans+=cost;
    }
    write(ans);
}