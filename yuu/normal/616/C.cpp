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
#define taskname "C"
int n, m;
char c[1002][1002];
int p[1001][1001];
int r[1000001];
int root(int u){
    if(r[u]<0) return u;
    return r[u]=root(r[u]);
}
void uni(int u, int v){
    u=root(u); v=root(v);
    if(u==v) return;
    if(r[u]>r[v]) swap(u, v);
    r[u]+=r[v];
    r[v]=u;
}
const int cx[]={1, 0, -1, 0};
const int cy[]={0, 1, 0, -1};
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    {
        int cnt=0;
        FOR(i, 1, n) FOR(j, 1, m){
            while(c[i][j]=getchar()){
                if(c[i][j]=='.') break;
                if(c[i][j]=='*') break;
            }
            p[i][j]=++cnt;
        }
        FOR(i, 1, cnt) r[i]=-1;
    }
    FOR(i, 1, n) FOR(j, 1, m) if(c[i][j]=='.') FFOR(k, 0, 4){
        int x=i+cx[k];
        int y=j+cy[k];
        if(c[x][y]!='.') continue;
        uni(p[i][j], p[x][y]);
    }
    FOR(i, 1, n) FOR(j, 1, m) if(c[i][j]=='*'){
        set <int> s;
        FFOR(k, 0, 4){
            int x=i+cx[k];
            int y=j+cy[k];
            if(c[x][y]!='.') continue;
            s.insert(root(p[x][y]));
        }
        int res=0;
        for(int u: s) res-=r[u];
        res++;
        c[i][j]=res%10+48;
    }
    FOR(i, 1, n){
        FOR(j, 1, m) putchar(c[i][j]);
        putchar('\n');
    }
}