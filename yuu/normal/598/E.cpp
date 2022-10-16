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
#define taskname "E"
int t;
bool done[31][31][51];
ll f[31][31][51];
ll F(int n, int m, int k){
    if(done[n][m][k]) return f[n][m][k];
    done[n][m][k]=1;
    if((k==0)||(k==m*n)) return f[n][m][k]=0;
    if(k>m*n) return f[n][m][k]=1e18;
    f[n][m][k]=1e18;
    FFOR(i, 1, m) FOR(l, 0, k) f[n][m][k]=min(f[n][m][k], F(n, i, l)+F(n, m-i, k-l)+n*n);
    FFOR(i, 1, n) FOR(l, 0, k) f[n][m][k]=min(f[n][m][k], F(i, m, l)+F(n-i, m, k-l)+m*m);
    return f[n][m][k];
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    int t, n, m, k;
    read(t);
    while(t--){
        read(n);
        read(m);
        read(k);
        writeln(F(n, m, k));
    }
}