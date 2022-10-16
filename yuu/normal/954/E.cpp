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
#define a first
#define t second
int n;
ld r;
class tap{
public:
    ld a, t;
} t[200001];
ld scale[200001];
bool check(ld m){
    ld atop=0, abot=0;
    ld btop=0, bbot=0;
    ld a, b;
    ld remain=m;
    FOR(i, 1, n){
        atop+=min(remain, t[i].a)*t[i].t;
        abot+=min(remain, t[i].a);
        remain-=min(remain, t[i].a);
    }
    if(remain>0) return 0;
    a=atop/abot;
    remain=m;
    DFOR(i, n, 1){
        btop+=min(remain, t[i].a)*t[i].t;
        bbot+=min(remain, t[i].a);
        remain-=min(remain, t[i].a);
    }
    if(remain>0) return 0;
    b=btop/bbot;
    if(a>b) swap(a, b);
    return (a-1e-9<=r)&&(b+1e-9>=r);
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(r);
    FOR(i, 1, n) read(t[i].a);
    FOR(i, 1, n) read(t[i].t);
    sort(t+1, t+n+1, [](tap A, tap B){
        return A.t<B.t;
    });
    ld ans=0, l=0, r=25e10, m;
    while(r-l>1e-7){
        m=(l+r)/2;
        if(check(m)){
            ans=m;
            l=m;
        }
        else r=m;
    }
    cout<<setprecision(7)<<fixed<<ans;
}