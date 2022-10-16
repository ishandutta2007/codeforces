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
#define taskname "D"
#define next Chinchinmaru
int of[100001];
vector <int> g[100001];
int p[100001];
int first[100001];
int last[100001];
int next[100001];
int f[100001];
int cnt;
int n, m, k, q, a, b, x, y;
void dfs(int u){
    cnt++;
    first[u]=last[u]=cnt;
    f[u]=1;
    for(int v: g[u]){
        dfs(v);
        last[u]=cnt;
        f[u]+=f[v];
    }
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(m);
    read(k);
    read(q);
    FOR(i, 1, k){
        read(a);
        read(b);
        if(of[b]==0){
            of[b]=a;
            next[b]=a;
        }
        else{
            g[next[b]].pb(a);
            p[a]=next[b];
            next[b]=a;
        }
    }
    FOR(i, 1, n){
        if(!first[i]){
            int u=i;
            while(p[u]) u=p[u];
            dfs(u);
        }
    }
    FOR(i, 1, q){
        read(x);
        read(y);
        if(of[y]==0) writeln(0);
        else{
            if(first[x]<=first[of[y]]&&first[of[y]]<=last[x])
                writeln(f[x]);
            else writeln(0);
        }
    }
}