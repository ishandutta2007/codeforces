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
ll n, x, k;
ll a[100001];
int count(ll x){
    if(a[1]>x) return 0;
    int l=1, r=n, m, res;
    while(l<=r){
        m=(l+r)/2;
        if(a[m]<=x){
            res=m;
            l=m+1;
        }
        else r=m-1;
    }
    return res;
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(x);
    read(k);
    FOR(i, 1, n) read(a[i]);
    sort(a+1, a+n+1);
    ll ans=0;
    FOR(i, 1, n){
        ll low, high;
        low=a[i]-a[i]%x-x*k+1;
        high=min(a[i], low+x-1);
        ans+=count(high)-count(low-1);
    }
    write(ans);
}