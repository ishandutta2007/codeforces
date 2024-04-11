#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
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
#define taskname "D"
///(s[r]-s[l-1])*x+br[r+1]+bl[l-1]
int n, x;
ll a[300001];
ll br[300002];
ll bl[300002];
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(x);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n) bl[i]=max(0LL, bl[i-1]+a[i]);
    DFOR(i, n, 1) br[i]=max(0LL, br[i+1]+a[i]);
    ll ans=0;
    ans=max(ans, *max_element(bl+1, bl+n+1));
    ans=max(ans, *max_element(br+1, br+n+1));
    ll best=0;
    FOR(r, 1, n){
        a[r]+=a[r-1];
        ans=max(ans, a[r]*x+br[r+1]+best);
        best=max(best, bl[r]-a[r]*x);
    }
    writeln(ans);
}