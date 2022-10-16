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
#define taskname "D"
ll n, k;
ll C(ll n, ll k){
    ///=n!/(k!*(n-k)!)
    ll res=1;
    FOR(i, n-k+1, n) res*=i;
    FOR(i, 1, k) res/=i;
    return res;
}
ll f[5];
ll count(ll n, ll x){
    return C(n, x)*f[x];
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    FOR(i, 1, 4){
        int a[5];
        FOR(j, 1, i) a[j]=j;
        do{
            bool good=1;
            FOR(j, 1, i) if(a[j]==j) good=0;
            f[i]+=good;
        } while(next_permutation(a+1, a+i+1));
    }
    read(n);
    read(k);
    ll ans=1;
    FOR(i, 1, k) ans+=count(n, i);
    writeln(ans);

}