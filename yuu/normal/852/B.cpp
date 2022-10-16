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
#define taskname "B"
#define bit(s, i) (((s)>>(i))&1)
const ll base=1000000007;
typedef ll matrix[101][101];
matrix core;
matrix ans;
ll n, l, m;
ll e[1000001];
ll c[1000001];
ll o[1000001];
ll f[101];
ll d[101];
#define multi(a, b, c){\
    FFOR(i, 0, m) FFOR(j, 0, m){\
        c[i][j]=0;\
        FFOR(k, 0, m) c[i][j]=(c[i][j]+a[i][k]*b[k][j])%base;\
    }\
}
void power(const matrix &a, int x, matrix &res){
    matrix t;
    FFOR(i, 0, m) FFOR(j, 0, m) res[i][j]=a[i][j];
    int i=31;
    while(i>=0){
        if(bit(x, i)) break;
        i--;
    }
    i--;
    while(i>=0){
        multi(res, res, t);
        if(bit(x, i)){
            multi(t, a, res);
        }
        else FFOR(i, 0, m) FFOR(j, 0, m) res[i][j]=t[i][j];
        i--;
    }
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(l);
    read(m);
    FOR(i, 1, n) read(e[i]);
    FOR(i, 1, n) read(c[i]);
    FOR(i, 1, n) read(o[i]);
    FOR(i, 1, n) f[e[i]]++;
    FOR(i, 1, n) core[0][c[i]]++;
    FFOR(i, 1, m) FFOR(j, 0, m) core[i][(j+i)%m]=core[0][j];
    if(l==2){
        FFOR(i, 0, m) d[i]=f[i];
    }
    else{
        power(core, l-2, ans);
        FFOR(j, 0, m){
            FFOR(k, 0, m){
                d[j]=(d[j]+f[k]*ans[k][j])%base;
            }
        }
    }
    ll res=0;
    FOR(i, 1, n) res=(res+d[((m*10-c[i]-o[i])%m+m)%m])%base;
    writeln(res);
}