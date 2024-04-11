#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
#define __builtin_popcount __builtin_popcountll
using ll=long long; using ld=long double;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); const ld pi=acos(0)*2;
template <typename T> inline void read(T &x){char c; bool nega=0; while((!isdigit(c=getchar()))&&(c!='-')); if(c=='-'){nega=1; c=getchar();} x=c-48; while(isdigit(c=getchar())) x=x*10+c-48; if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10); putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){ putchar('-'); x=-x;} writep(x);}
template <typename T> inline void writeln(T x){write(x); putchar('\n');}
#define taskname "E"
#define up Kafuu
#define down Chino
#define left Gochi
#define right Usa
int n, m;
char c[1002][1002];
int up[1002][1002];
int down[1002][1002];
int left[1002][1002];
int right[1002][1002];
int f[1002][1002];
int g[1002][1002];
class star{
public:
    int x, y, s;
    star(int x, int y, int s){
        this->x=x;
        this->y=y;
        this->s=s;
    }
    void output(){
        write(x);
        putchar(' ');
        write(y);
        putchar(' ');
        writeln(s);
    }
};
vector <star> ans;
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(m);
    FOR(i, 1, n) FOR(j, 1, m){
        while(true){
            c[i][j]=getchar();
            if(c[i][j]=='.'||c[i][j]=='*') break;
        }
    }
    FOR(i, 1, n) FOR(j, 1, m) if(c[i][j]=='*') up[i][j]=up[i-1][j]+1; else up[i][j]=0;
    DFOR(i, n, 1) FOR(j, 1, m) if(c[i][j]=='*') down[i][j]=down[i+1][j]+1; else down[i][j]=0;
    FOR(i, 1, n) FOR(j, 1, m) if(c[i][j]=='*') left[i][j]=left[i][j-1]+1; else left[i][j]=0;
    FOR(i, 1, n) DFOR(j, m, 1) if(c[i][j]=='*') right[i][j]=right[i][j+1]+1; else right[i][j]=0;
    FOR(i, 1, n) FOR(j, 1, m){
        int x=min(min(up[i][j], down[i][j]), min(left[i][j], right[i][j]))-1;
        if(x<=0) continue;
        ans.pb(star(i, j, x));
        f[i][j-x]++;
        f[i][j+x+1]--;
        g[i-x][j]++;
        g[i+x+1][j]--;
    }
    FOR(i, 1, n) FOR(j, 1, m){
        f[i][j]+=f[i][j-1];
        g[i][j]+=g[i-1][j];
        if(((f[i][j]+g[i][j])==0)!=(c[i][j]=='.')){
            puts("-1");
            return 0;
        }
    }
    writeln(ans.size());
    for(auto x: ans) x.output();
}