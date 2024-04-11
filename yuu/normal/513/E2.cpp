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
#define taskname "513E2"
#define update(u, x) (u=max(u, x))
int f[30002][202][2][2][2];
int a[30002];
int n, k;
int weight[2][3];
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    weight[0][0]=0;
    weight[1][1]=0;
    weight[0][1]=-2;
    weight[1][0]=2;
    read(n);
    read(k);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 0, n) FOR(j, 0, k) FOR(a, 0, 1) FOR(b, 0, 1) FOR(c, 0, 1) f[i][j][a][b][c]=-mask(30);
    f[0][0][0][0][0]=0;
    f[0][0][0][0][1]=0;
    FOR(i, 0, n){
        FOR(j, 0, k){
            ///end sequense
            FOR(b, 0, 1) FOR(c, 0, 1) update(f[i][j][0][b][c], f[i][j][1][b][c]);
            ///start new
            if(j==0){
                FOR(b, 0, 1) FOR(c, 0, 1) FOR(nc, 0, 1)
                    update(f[i+1][j+1][1][c][nc], f[i][j][0][b][c]+a[i+1]*(nc?(-1):1));
            }
            else if(j==k-1){
                FOR(b, 0, 1) FOR(c, 0, 1) FOR(nc, 0, 1)
                    update(f[i+1][j+1][1][c][nc], f[i][j][0][b][c]+a[i+1]*(c?1:(-1)));
            }
            else{
                FOR(b, 0, 1) FOR(c, 0, 1) FOR(nc, 0, 1)
                    update(f[i+1][j+1][1][c][nc], f[i][j][0][b][c]+a[i+1]*weight[c][nc]);

            }
            ///take more
            if(j==1){
                FOR(b, 0, 1) FOR(c, 0, 1) update(f[i+1][j][1][b][c], f[i][j][1][b][c]+a[i+1]*(c?(-1):1));
            }
            else if(j==k){
                FOR(b, 0, 1) FOR(c, 0, 1) update(f[i+1][j][1][b][c], f[i][j][1][b][c]+a[i+1]*(b?1:(-1)));
            }
            else{
                FOR(b, 0, 1) FOR(c, 0, 1) update(f[i+1][j][1][b][c], f[i][j][1][b][c]+a[i+1]*weight[b][c]);
            }
            ///don't take
            FOR(b, 0, 1) FOR(c, 0, 1) update(f[i+1][j][0][b][c], f[i][j][0][b][c]);
        }
    }
    int ans=-mask(30);
    FOR(i, 0, n) FOR(b, 0, 1) FOR(c, 0, 1) ans=max(ans, f[i][k][0][b][c]);
    write(ans);
}