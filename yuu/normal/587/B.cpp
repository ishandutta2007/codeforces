#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
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
ll l;
int n, k, m;
int a[1000000];
pair <int, int> f[1000000];
int sum[1000000];
const int base=1000000007;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    read(l);
    read(k);
    FOR(i, 0, n-1) read(a[i]);
    m=(n*k);
    FOR(i, 0, m-1) f[i]=mp(a[i%n], i);
    sort(f, f+m);
    ll ans=0;
    FOR(i, 0, m-1){
        int k=f[i].second/n;
        ll p;
        if(f[i].second<n) p=1;
        else p=sum[k-1];
        sum[k]=(sum[k]+p)%base;
        if(f[i].second<l){
            ll r=(l-f[i].second-1)/n+1;
            r%=base;
            ans=(ans+r*p%base)%base;
        }
    }
    writeln(ans);
}