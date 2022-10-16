#include <stdio.h>
#include <locale>
template <typename T> inline void read(T &x){
    char c;
    while(!isdigit(c=getchar()));
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
}
template <typename T> inline void write(T x){
    if(x>9) write(x/10);
    putchar(x%10+48);
}
#include <vector>
using namespace std;
vector <int> adj[1001];
vector <int> temp;
int c[1001];
bool a[1001][1001];
bool d[1001];
int ans=0;
void dfs(int u){
    d[u]=1;
    temp.push_back(u);
    for(int i=0; i<adj[u].size(); i++){
        if(!d[adj[u][i]]){
            dfs(adj[u][i]);
        }
    }
}
int n, m, k, u, v, best;
int main(){
//    freopen("C.INP", "r", stdin);
    read(n);
    read(m);
    read(k);
    for(int i=1; i<=k; i++)
        read(c[i]);
    for(int i=1; i<=m; i++){
        read(u);
        read(v);
        a[u][v]=a[v][u]=1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=k; i++){
        temp.clear();
        dfs(c[i]);
        ans+=temp.size()*(temp.size()-1)/2;
        for(int i=0; i<temp.size(); i++){
            for(int j=i+1; j<temp.size(); j++){
                ans-=a[temp[i]][temp[j]];
            }
        }
        best=max(best, (int)temp.size());
    }
    temp.clear();
    for(int i=1; i<=n; i++){
        if(!d[i])
            temp.push_back(i);
    }
    ans+=temp.size()*best+temp.size()*(temp.size()-1)/2;
    for(int i=0; i<temp.size(); i++){
        for(int j=i+1; j<temp.size(); j++){
            ans-=a[temp[i]][temp[j]];
        }
    }
    write(ans);
}