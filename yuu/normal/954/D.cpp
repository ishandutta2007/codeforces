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
#define taskname "D"
int n, m, s, t;
bool done[1001];
int c[1001][1001];
int d[1001][1001];
vector <int> g[1001];
queue <int> q;
void bfs(int a){
    FOR(i, 1, n) done[i]=0;
    d[a][a]=0;
    done[a]=1;
    q.push(a);
    int u;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int v: g[u]) if(!done[v]){
            done[v]=1;
            d[a][v]=d[a][u]+1;
            q.push(v);
        }
    }
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(m);
    read(s);
    read(t);
    {
        int u, v;
        FOR(i, 1, m){
            read(u);
            read(v);
            c[u][v]=c[v][u]=1;
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    bfs(s);
    bfs(t);
    int ans=0;
    FOR(i, 1, n) FOR(j, i+1, n) if(!c[i][j]){
        if(min(d[s][i]+d[t][j]+1, d[s][j]+d[t][i]+1)>=d[s][t]) ans++;
    }
    writeln(ans);
}