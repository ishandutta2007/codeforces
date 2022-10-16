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
#define taskname "F"
int n, m;
int a[16][10000];
int cost[16][16];
int cost2[16][16];
int f[16][mask(16)];
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(m);
    FFOR(i, 0, n) FFOR(j, 0, m) read(a[i][j]);
    FFOR(i, 0, n) FFOR(j, i+1, n){
        cost[i][j]=2e9;
        FFOR(k, 0, m) cost[i][j]=min(cost[i][j], abs(a[i][k]-a[j][k]));
        cost[j][i]=cost[i][j];
    }
    FFOR(i, 0, n) FFOR(j, 0, n){
        cost2[i][j]=2e9;
        FFOR(k, 1, m) cost2[i][j]=min(cost2[i][j], abs(a[j][k]-a[i][k-1]));
    }
    int ans=0;
    FFOR(i, 0, n){
        FFOR(j, 0, n) FFOR(k, 0, mask(n)) f[j][k]=0;
        f[i][mask(i)]=1e9;
        FFOR(k, 0, mask(n)) FFOR(j, 0, n) if(f[j][k]){
            FFOR(l, 0, n) if(bit(k, l)==0) f[l][k|mask(l)]=max(f[l][k|mask(l)], min(f[j][k], cost[j][l]));
        }
        FFOR(j, 0, n) ans=max(ans, min(f[j][mask(n)-1], cost2[j][i]));
    }
    writeln(ans);
}