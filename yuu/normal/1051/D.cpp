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
const ll base=998244353;
ll f[1001][2003][2];
int n, k;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(k);
    f[1][2][0]=2;
    f[1][1][1]=2;
    FFOR(i, 1, n) FOR(j, 1, k) FFOR(s, 0, 2) if(f[i][j][s]){
        f[i][j][s]%=base;
        if(s){
            f[i+1][j][1]+=f[i][j][s];
            f[i+1][j+1][1]+=f[i][j][s];
            f[i+1][j+1][0]+=f[i][j][s]*2;
        }
        else{
            f[i+1][j][1]+=f[i][j][s]*2;
            f[i+1][j][0]+=f[i][j][s];
            f[i+1][j+2][0]+=f[i][j][s];
        }
    }
    writeln((f[n][k][0]+f[n][k][1])%base);
}