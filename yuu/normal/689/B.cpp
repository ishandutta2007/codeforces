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
#define taskname "B"
int n;
int a;
queue <int> q;
vector <int> g[200001];
bool done[200001];
int f[200001];
void bfs(){
    q.push(1);
    done[1]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v: g[u]){
            if(done[v]) continue;
            f[v]=f[u]+1;
            done[v]=1;
            q.push(v);
        }
    }
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    FOR(i, 1, n){
        read(a);
        g[i].pb(a);
    }
    FOR(i, 2, n)
        g[i].pb(i-1);
    DFOR(i, n-1, 1)
        g[i].pb(i+1);
    bfs();
    FOR(i, 1, n){
        write(f[i]);
        putchar(' ');
    }
}