#include <stdio.h>
#include <locale>
template <typename T> inline void read(T &x){
    char c;
    while((!isdigit(c=getchar()))&&(c!='-'));
    bool nega=0;
    if(c=='-'){
        c=getchar();
        nega=1;
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
}
template <typename T> inline void write(T x){
    if(x>9) write(x/10);
    putchar(x%10+48);
}
#include <vector>
#include <algorithm>
using namespace std;
vector <int> adj[200001];
long long trace[200001];
long long f[200001];//Tng  vui v
long long h[200001];//C s vui v cao nht trong cc nhnh con
long long g[200001];//Kt qu tnh c
long long a[200001];// vui v ban u
const long long inf=1999999999999999999;
int n;
void dfs(int u){
    f[u]=a[u];
    h[u]=-inf;
    g[u]=-inf;
    vector <long long> temp;
    for(int i=0; i<adj[u].size(); i++){
        if(trace[u]!=adj[u][i]){
            trace[adj[u][i]]=u;
            dfs(adj[u][i]);
            h[u]=max(h[u], h[adj[u][i]]);
            g[u]=max(g[u], g[adj[u][i]]);
            temp.push_back(h[adj[u][i]]);
            f[u]+=f[adj[u][i]];
        }
    }
    h[u]=max(h[u], f[u]);
    sort(temp.begin(), temp.end());
    if(temp.size()>1)
        g[u]=max(g[u], temp[temp.size()-1]+temp[temp.size()-2]);
}
int main(){
//    freopen("D.INP", "r", stdin);
    read(n);
    int u, v;
    for(int i=1; i<=n; i++)
        read(a[i]);
    for(int i=1; i<n; i++){
        read(u);
        read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    if(g[1]==-inf)
        printf("Impossible");
    else
        printf("%I64d", g[1]);
}