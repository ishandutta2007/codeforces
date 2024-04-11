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
#include <set>
using namespace std;
int n;
vector <pair<int, int> > adj[100001];
set <int> s[100001];
int c[100001];
bool sc[100001];
bool done[100001];
bool done2[100001];
int vtcha[100001];
int cc;
void dfs(int u){
    done[u]=1;
    sc[u]=1;
    DFOR(i, adj[u].size()-1, 0){
        int v=adj[u][i].first;
        if(done[v])
            vtcha[u]=i;
        else{
            dfs(v);
            sc[u]=(sc[u]&&sc[v])&&(c[u]==c[v]);
            adj[u][i].second=sc[v];
        }
    }
}
bool tinh(int u){//Xem t u ln cha c to thnh cy p khng.
    if(u==1) return 1;
    if(!done2[u]){
        done2[u]=1;
        adj[u][vtcha[u]].second=1;
        int cha_u=adj[u][vtcha[u]].first;
        DFOR(j, adj[cha_u].size()-1, 0){
            if(j==vtcha[cha_u]) adj[u][vtcha[u]].second=(c[adj[cha_u][j].first]==c[cha_u])&&tinh(cha_u);
            else{
                if((adj[cha_u][j].first!=u))
                    adj[u][vtcha[u]].second=(c[adj[cha_u][j].first]==c[cha_u])&&adj[cha_u][j].second;
            }
            if(adj[u][vtcha[u]].second==0) return 0;
        }
    }
    return adj[u][vtcha[u]].second;
}
int main(){
//    freopen("C.INP", "r", stdin);
    read(n);
    FOR(i, 2, n){
        int u, v;
        read(u);
        read(v);
        adj[u].push_back(make_pair(v, 0));
        adj[v].push_back(make_pair(u, 0));
    }
    FOR(i, 1, n)
        read(c[i]);
    vtcha[1]=-1;
    dfs(1);
    FOR(u, 2, n)
        if(!done2[u]) tinh(u);
    FOR(u, 1, n){
        int cnt=0;
        DFOR(i, adj[u].size()-1, 0)
            cnt+=adj[u][i].second;
        if(cnt==adj[u].size()){
            puts("YES");
            write(u);
            return 0;
        }
    }
    puts("NO");
}