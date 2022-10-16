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
#define taskname "H"
int n;
int a[100001];
pair <int, ll> f[100002];
pair <int, ll> g[100002];
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    FOR(i, 1, n) read(a[i]);
    f[1]=mp(a[1], 0);
    FOR(i, 2, n){
        if(a[i]>f[i-1].first) f[i]=mp(a[i], f[i-1].second);
        else f[i]=mp(f[i-1].first+1, f[i-1].second+f[i-1].first+1-a[i]);
    }
    g[n]=mp(a[n], 0);
    DFOR(i, n-1, 1){
        if(a[i]>g[i+1].first) g[i]=mp(a[i], g[i+1].second);
        else g[i]=mp(g[i+1].first+1, g[i+1].second+g[i+1].first+1-a[i]);
    }
    ll ans=min(f[n].second, g[1].second);
    FFOR(i, 2, n) ans=min(ans, f[i-1].second+g[i+1].second+max(0, max(f[i-1].first, g[i+1].first)+1-a[i]));
    writeln(ans);
}