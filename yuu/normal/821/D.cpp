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
int cx[]={1, -1, 0, 0};
int cy[]={0, 0, 1, -1};
int n, m, k;
int r[10001];
int c[10001];
map <pair <int, int>, int> M;
vector <pair <int, int> > g[50001];
deque <int> q;
int f[50001];
void bfs(int u){
    FOR(i, 1, 50000) f[i]=1e9;
    f[u]=0;
    q.pb(u);
    while(!q.empty()){
        u=q.front();
        q.pop_front();
        for(pair <int, int> v: g[u]){
            if(f[v.first]>f[u]+v.second){
                f[v.first]=f[u]+v.second;
                if(v.second) q.pb(v.first);
                else q.push_front(v.first);
            }
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
    read(k);
    FOR(i, 1, k){
        read(r[i]);
        read(c[i]);
        M[mp(r[i], c[i])]=i;
    }
    int sz=k;
    if(M.find(mp(n, m))==M.end()) k++;
    FOR(i, 1, sz){
        g[i].pb(mp(15000+r[i], 1));
        g[15000+r[i]].pb(mp(i, 0));
        if(r[i]>1){
            g[i].pb(mp(15000+r[i]-1, 1));
            g[15000+r[i]-1].pb(mp(i, 0));
        }
        if(r[i]<n){
            g[i].pb(mp(15000+r[i]+1, 1));
            g[15000+r[i]+1].pb(mp(i, 0));
        }

        g[i].pb(mp(30000+c[i], 1));
        g[30000+c[i]].pb(mp(i, 0));
        if(c[i]>1){
            g[i].pb(mp(30000+c[i]-1, 1));
            g[30000+c[i]-1].pb(mp(i, 0));
        }
        if(c[i]<m){
            g[i].pb(mp(30000+c[i]+1, 1));
            g[30000+c[i]+1].pb(mp(i, 0));
        }
        FFOR(l, 0, 4){
            int x=r[i]+cx[l];
            int y=c[i]+cy[l];
            if(M.find(mp(x, y))!=M.end()) g[i].pb(mp(M[mp(x, y)], 0));
        }
    }
    if(k>sz){
        M[mp(n, m)]=k;
        g[15000+n].pb(mp(k, 0));
        g[30000+m].pb(mp(k, 0));
    }
    bfs(M[mp(1, 1)]);
    if(f[M[mp(n, m)]]==1e9) f[M[mp(n, m)]]=-1;
    write(f[M[mp(n, m)]]);
}