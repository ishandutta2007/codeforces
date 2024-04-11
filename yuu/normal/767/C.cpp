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
#include <vector>
#include <cstdlib>
using namespace std;
#define taskname "C"
int s=0;
int t[1000001];
int f[1000001];
int n, x, r;
bool done[1000001];
int d[1000001];
vector <int> adj[1000001];
void dfs(int u){
    done[u]=1;
    f[u]=t[u];
    for(int i=0; i<adj[u].size(); i++){
        if(!done[adj[u][i]]){
            dfs(adj[u][i]);
            f[u]+=f[
            adj[u][i]];
            if(d[adj[u][i]]){
                if(!d[u])
                    d[u]=d[adj[u][i]];
                else{
                    write(d[u]);
                    putchar(' ');
                    write(d[adj[u][i]]);
                    exit(0);
                }
            }
        }
    }
    if(!d[u]){
        if(f[u]==s&&u!=r)
            d[u]=u;
    }
    if((d[u])&&(d[u]!=u)){
        if(f[u]==s*2&&u!=r){
            write(u);
            putchar(' ');
            write(d[u]);
            exit(0);
        }
    }
}
int main(){
    #ifdef JohnTitor
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // JohnTitor
    read(n);
    FOR(i, 1, n){
        read(x);
        read(t[i]);
        if(x==0)
            r=i;
        else
            adj[x].push_back(i);
        s+=t[i];
    }
    if(s%3){
        write(-1);
        return 0;
    }
    s/=3;
    dfs(r);
    write(-1);
}