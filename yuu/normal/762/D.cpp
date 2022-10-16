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
#define taskname "Maximum_path"
int n;
ll a[3][100001];
ll s[100001];
ll f[100001][3];
const ll inf=mask(60);
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    FFOR(i, 0, 3) FOR(j, 1, n){
        read(a[i][j]);
        s[j]+=a[i][j];
    }
    FOR(i, 1, n) FFOR(j, 0, 3) f[i][j]=-inf;
    f[1][0]=a[0][1];
    f[1][1]=f[1][0]+a[1][1];
    f[1][2]=f[1][1]+a[2][1];
    FOR(i, 1, n) s[i]+=s[i-1];
    FOR(i, 2, n){
        FFOR(j, 0, 3){
            f[i][j]=max(f[i][j], f[i-1][j]+a[j][i]);
            if(j>=1) f[i][j]=max(f[i][j], f[i-1][j-1]+a[j][i]+a[j-1][i]);
            if(j<=1) f[i][j]=max(f[i][j], f[i-1][j+1]+a[j][i]+a[j+1][i]);
        }
        for(int j=1; j<=2; j++){
            f[i][0]=max(f[i][0], f[i-j][2]+s[i]-s[i-j]);
            f[i][2]=max(f[i][2], f[i-j][0]+s[i]-s[i-j]);
        }
    }
    writeln(f[n][2]);
}