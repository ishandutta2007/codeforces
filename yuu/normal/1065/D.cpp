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
using ll=long long;
using ld=long double;
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
int n;
int a[11][11];
pair <int, int> pos[101];
///0:rook
///1:bishop
///2:knight
vector <pair <int, int>> moves[3];
pair <int, int> f[3];
pair <int, int> dist[101][3];
int done[101][3];
class data{
public:
    int u, p;
    int x, y;
    pair <int, int> cost;
    data(int u, int p, pair <int, int> cost){
        x=pos[u].first;
        y=pos[u].second;
        this->u=u;
        this->p=p;
        this->cost=cost;
    }
};
class cmp{
public:
    bool operator ()(data A, data B){
        return A.cost>B.cost;
    }
};
priority_queue <data, vector <data>, cmp> q;
void find_mincost(int u){
    FOR(i, 1, n*n) FOR(j, 0, 2) done[i][j]=0;
    while(!q.empty()) q.pop();
    FOR(p, 0, 2) FOR(i, 1, n*n) dist[i][p]=mp(1e9, 1e9);
    FOR(i, 0, 2){
        dist[u][i]=f[i];
        q.push(data(u, i, dist[u][i]));
    };
    while(!q.empty()){
        data d=q.top();
        q.pop();
        if(done[d.u][d.p]) continue;
        done[d.u][d.p]=1;
        FOR(p, 0, 2) if(p!=d.p){
            if(done[d.u][p]) continue;
            dist[d.u][p]=min(dist[d.u][p], mp(dist[d.u][d.p].first+1, dist[d.u][d.p].second+1));
            q.push(data(d.u, p, dist[d.u][p]));
        }
        for(pair <int, int> m: moves[d.p]){
            int ii=d.x+m.first;
            int jj=d.y+m.second;
            if(ii<1||ii>n) continue;
            if(jj<1||jj>n) continue;
            if(done[a[ii][jj]][d.p]) continue;
            dist[a[ii][jj]][d.p]=min(dist[a[ii][jj]][d.p], mp(dist[d.u][d.p].first+1, dist[d.u][d.p].second));
            q.push(data(a[ii][jj], d.p, dist[a[ii][jj]][d.p]));
        }
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n) FOR(j, 1, n){
        read(a[i][j]);
        pos[a[i][j]]=mp(i, j);
    }
    FOR(i, -(n-1), n-1){
        moves[0].pb(mp(0, i));
        moves[0].pb(mp(i, 0));
    }
    FOR(i, -(n-1), n-1){
        moves[1].pb(mp(i, i));
        moves[1].pb(mp(i, -i));
    }
    FOR(i, -2, 2) FOR(j, -2, 2) if(i*i+j*j==5) moves[2].pb(mp(i, j));
    FFOR(i, 1, n*n){
        find_mincost(i);
        FOR(j, 0, 2) f[j]=dist[i+1][j];
    }
    FOR(i, 1, 2) f[0]=min(f[0], f[i]);
    write(f[0].first);
    putchar(' ');
    writeln(f[0].second);
}