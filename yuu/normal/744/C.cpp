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
#define taskname "744C"
int n;
char c[16];
int r[16];
int b[16];
int f[mask(16)][16*15/2+1];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    int req_red=0;
    int req_blue=0;
    FFOR(i, 0, n){
        while((!isalpha(c[i]=getchar())));
        read(r[i]);
        req_red+=r[i];
        read(b[i]);
        req_blue+=b[i];
    }
    int max_save=n*(n-1)/2;
    FFOR(i, 0, mask(n)) FOR(j, 0, max_save) f[i][j]=-1;
    f[0][0]=0;
    FFOR(i, 0, mask(n)){
        int have_red=0;
        int have_blue=0;
        FFOR(j, 0, n) if(bit(i, j)){
            if(c[j]=='R') have_red++;
            else have_blue++;
        }
        FOR(j, 0, max_save) if(f[i][j]>=0){
            FFOR(k, 0, n) if(bit(i, k)==0){
                f[i|mask(k)][j+min(have_red, r[k])]=max(f[i|mask(k)][j+min(have_red, r[k])], f[i][j]+min(have_blue, b[k]));
            }
        }
    }
    int ans=1e9;
    FOR(i, 0, max_save) if(f[mask(n)-1][i]>=0) ans=min(ans, max(req_red-i, req_blue-f[mask(n)-1][i]));
    writeln(ans+n);
}