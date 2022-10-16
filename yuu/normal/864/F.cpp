#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
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
#define taskname "F"
int n, m, q;
vector <int> g[3001];
vector <int> h[3001];
vector <int> f[3001];
vector <pair <pair <int, int>, int> > d[3001];
int r[3001][20];
bool done[3001];
int high[3001];
int ans[500001];
int x, y, s, t, k;
void visit(int u){
    done[u]=1;
    for(int x: h[u]) if(!done[x]) visit(x);
}
void dfs(int u){
    done[u]=1;
    for(int i=0; r[r[u][i]][i]; i++) r[u][i+1]=r[r[u][i]][i];
    for(int v: f[u]){
        if(!done[v]){
            high[v]=high[u]+1;
            r[v][0]=u;
            dfs(v);
        }
    }
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(m);
    read(q);
    FOR(i, 1, m){
        read(x);
        read(y);
        g[x].pb(y);
        h[y].pb(x);
    }
    FOR(i, 1, n) sort(g[i].begin(), g[i].end());
    FOR(i, 1, q){
        read(s);
        read(t);
        read(k);
        d[t].pb(mp(mp(s, k), i));
    }
    FOR(i, 1, n){
        if(d[i].empty()) continue;
        FOR(j, 1, n) done[j]=0;
        visit(i);
        FOR(j, 1, n) if(done[j]) f[j].clear();
        FFOR(j, 1, i) if(done[j]){
            for(int x: g[j]) if(done[x]){
                f[x].pb(j);
                break;
            }
        }
        FOR(j, i+1, n) if(done[j]){
            for(int x: g[j]) if(done[x]){
                f[x].pb(j);
                break;
            }
        }
        FOR(j, 1, n){
            if(done[j]){
                FOR(l, 0, 1000){
                    if(!r[j][l]) break;
                    r[j][l]=0;
                }
                done[j]=0;
            }
        }
        high[i]=1;
        dfs(i);
        FFOR(j, 0, d[i].size()){
            s=d[i][j].first.first;
            k=d[i][j].first.second;
            if((!done[s])||(high[s]<k)) ans[d[i][j].second]=-1;
            else{
                k=high[s]-k+1;
                DFOR(l, __lg(max(high[s]-k, 1)), 0) if(high[r[s][l]]>=k) s=r[s][l];
                ans[d[i][j].second]=s;
            }
        }
    }
    FOR(i, 1, q){
        if(i>1) putchar('\n');
        write(ans[i]);
    }
}