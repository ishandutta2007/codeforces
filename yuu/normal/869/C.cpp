#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
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
#define taskname "C"
ll f[5001][5001];
const ll base=998244353;
int a, b, c, n;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(a);
    read(b);
    read(c);
    n=max(a, max(b, c));
    FOR(i, 1, n) f[1][i]=f[i][1]=i+1;
    FOR(i, 2, n) FOR(j, 2, n) f[i][j]=(f[i-1][j]+f[i-1][j-1]*j)%base;
    ll res1=f[a][b];
    ll res2=f[b][c];
    ll res3=f[c][a];
    ll ans=1;
    ans=(res1*res2)%base;
    ans=(ans*res3)%base;
    write(ans);
}