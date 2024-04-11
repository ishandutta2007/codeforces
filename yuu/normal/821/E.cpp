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
#define taskname "E"
const ll base=1000000007;
class matrix{
public:
    ll a[16][16];
    matrix operator * (matrix A){
        matrix res;
        FOR(i, 0, 15) FOR(j, 0, 15){
            res.a[i][j]=0;
            FOR(k, 0, 15) res.a[i][j]=(res.a[i][j]+a[i][k]*A.a[k][j])%base;
        }
        return res;
    }
} core[16], res;
matrix power(matrix a, ll x){
    int i=__lg(x)+1;
    while(i>=0){
        if(bit(x, i)) break;
        i--;
    }
    i--;
    matrix res=a, temp;
    while(i>=0){
        temp=res*res;
        if(bit(x, i)) res=temp*a;
        else res=temp;
        i--;
    }
    return res;
}
ll ans[16];
ll nans[16];
int n;
ll k;
ll a[101];
ll b[101];
int c[101];
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    FOR(i, 0, 15){
        FOR(j, 0, 15) FOR(k, 0, 15) core[i].a[j][k]=0;
        FOR(j, 0, i) core[i].a[j][j]++;
        FOR(j, 1, i) core[i].a[j][j-1]++;
        FFOR(j, 0, i) core[i].a[j][j+1]++;
    }
    read(n);
    read(k);
    FOR(i, 1, n){
        read(a[i]);
        read(b[i]);
        read(c[i]);
    }
    if(b[n]>k) b[n]=k;
    ans[0]=1;
    FOR(i, 1, n){
        if(a[i]==k) break;
        FOR(j, c[i]+1, 15) ans[j]=0;
        res=power(core[c[i]], b[i]-a[i]);
        FOR(i, 0, 15) nans[i]=0;
        FOR(i, 0, 15) FOR(j, 0, 15) nans[i]=(nans[i]+ans[j]*res.a[j][i])%base;
        FOR(i, 0, 15) ans[i]=nans[i];
    }
    writeln(ans[0]);
}