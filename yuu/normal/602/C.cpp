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
#define taskname "C"
#include <queue>
using namespace std;
int n, m;
int u, v;
bool c[401][401];
bool done[401];
int f[401];
vector <int> adj1[401], adj2[401];
queue <int> q;
void bfs1(){
    q.push(1);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=adj1[u].size()-1; i>=0; i--){
            int x=adj1[u][i];
            if(!done[x]){
                f[x]=f[u]+1;
                q.push(x);
                done[x]=1;
            }
        }
        if(done[n]) return;
    }
}
void bfs2(){
    q.push(1);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=adj2[u].size()-1; i>=0; i--){
            int x=adj2[u][i];
            if(!done[x]){
                f[x]=f[u]+1;
                q.push(x);
                done[x]=1;
            }
        }
        if(done[n]) return;
    }
}
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
        c[u][v]=c[v][u]=1;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    FOR(i, 1, n){
        FOR(j, 1, n){
            if(j==i) continue;
            if(!c[i][j])
                adj2[i].push_back(j);
        }
    }
    f[n]=-1;
    if(c[1][n])
        bfs2();
    else bfs1();
    write(f[n]);
}