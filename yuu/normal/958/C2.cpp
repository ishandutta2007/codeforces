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
#define taskname "C2"
int n, k, p, a;
int f[51][101][2];
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(k);
    read(p);
    int now=0, nex=1;
    FOR(j, 0, k) FFOR(l, 0, p) f[j][l][now]=-1;
    f[0][0][now]=0;
    FOR(i, 1, n){
        FOR(j, 0, k) FFOR(l, 0, p) f[j][l][nex]=-1;
        read(a);
        a%=p;
        FFOR(x, 0, k) FFOR(y, 0, p) if(f[x][y][now]>=0){
            f[x][(y+a)%p][nex]=max(f[x][(y+a)%p][nex], f[x][y][now]);
            f[x+1][a][nex]=max(f[x+1][a][nex], f[x][y][now]+y);
        }
        swap(now, nex);
    }
    int ans=0;
    FFOR(i, 0, p) if(f[k-1][i][now]) ans=max(ans, f[k-1][i][now]+i);
    writeln(ans);
}