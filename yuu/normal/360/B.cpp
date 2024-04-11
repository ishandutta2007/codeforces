#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
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
#define taskname "B"
int n, k;
ll a[2001];
int f[2001];
bool check(ll x){
    FOR(i, 1, n){
        ll low=a[i];
        ll high=a[i];
        f[i]=i-1;
        DFOR(j, i-1, 1){
            low-=x;
            high+=x;
            if(a[j]<=high&&a[j]>=low) f[i]=min(f[i], f[j]+(i-j-1));
        }
        f[i]=min(f[i], i-1);
        if(f[i]+(n-i)<=k) return 1;
    }
    return 0;
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(k);
    FOR(i, 1, n) read(a[i]);
    check(1);
    ll l=0, r=2e9, m, res=2e9;
    while(l<=r){
        m=(l+r)/2;
        if(check(m)){
            res=m;
            r=m-1;
        }
        else l=m+1;
    }
    writeln(res);
}