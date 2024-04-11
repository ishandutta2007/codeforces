#include <stdio.h>
#include <locale>
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
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
#include <algorithm>
#include <vector>
using namespace std;
long long deg[100001];
vector <int> adj[100001];
bool done[100001];
long long f[100001];
long long F(int u){
    if(done[u]) return f[u];
    done[u]=1;
    f[u]=1;
    for(int v: adj[u])
        f[u]=max(f[u], F(v)+1);
    return f[u];
}
int n, m, u, v;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    read(m);
    FOR(i, 1, m){
        read(u);
        read(v);
        if(u>v)
            adj[u].push_back(v);
        else adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    long long ans=0;
    FOR(i, 1, n)
        ans=max(ans, F(i)*deg[i]);
    writeln(ans);
}