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
#define taskname "CF342E"
#include <math.h>
#include <queue>
#define left lfet__
#define right right__
using namespace std;
int n, m, t;
vector <int> adj[100001];
vector <int> recent;
queue <int> q;
bool inqueue[100001];
int p[400001];
int left[100001];
int right[100001];
int psize;
int high[100001];
int rm[400001][24];
int best[100001];
int f[100001];
bool done[100001];
bool red[100001];
void dfs(int u){
    done[u]=1;
    p[++psize]=u;
    left[u]=psize;
    right[u]=psize;
    for(int v: adj[u]){
        if(!done[v]){
            high[v]=high[u]+1;
            dfs(v);
            p[++psize]=u;
            right[u]=psize;
        }
    }
}
void initrmq(){
    FOR(i, 1, psize)
        rm[i][0]=p[i];
    for(int j=1, temp=2; temp<=psize; temp<<=1, j++){
        for(int i=1; i+temp-1<=psize; i++)
            rm[i][j]=(high[rm[i][j-1]]<high[rm[i+(temp>>1)][j-1]])?rm[i][j-1]:rm[i+(temp>>1)][j-1];
    }
}
inline int lca(int u, int v){
    int l=min(left[u], left[v]);
    int r=max(right[u], right[v]);
    int i=floor(log(r-l+1)/log(2));
    if(high[rm[l][i]]<high[rm[r-(1<<i)+1][i]])
        return rm[l][i];
    else return rm[r-(1<<i)+1][i];
}
inline int dis(int u, int v){
    int r=lca(u, v);
    return high[u]-high[r]+high[v]-high[r];
}
void bfs(){
    FOR(i, 1, n)
        done[i]=0;
    for(int u: recent)
        f[u]=0;
    while(!q.empty()){
        int u=q.front();
        best[u]=min(best[u], f[u]);
        inqueue[u]=0;
        done[u]=1;
        q.pop();
        for(int v: adj[u]){
            if(!done[v])
                if(!inqueue[v]){
                    f[v]=f[u]+1;
                    q.push(v);
                    inqueue[v]=1;
                }
        }
    }
}
int main(){
    #ifdef JohnTitor
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // JohnTitor
    int u, v;
    read(n);
    read(m);
    t=sqrt(m);
    recent.push_back(1);
    q.push(1);
    red[1]=1;
    inqueue[1]=1;
    FOR(i, 1, n)
        best[i]=n;
    FOR(i, 2, n){
        read(u);
        read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    high[1]=1;
    dfs(1);
    initrmq();
    FOR(i, 1, m){
        int u, v;
        read(u);
        read(v);
        if(u==1){
            if(!red[v]){
                q.push(v);
                inqueue[v]=1;
                recent.push_back(v);
                red[v]=1;
                if(recent.size()>t){
                    bfs();
                    recent.clear();
                }
            }
        }
        else{
            for(int x: recent)
                best[v]=min(best[v], dis(x, v));
            writeln(best[v]);
        }
    }
}