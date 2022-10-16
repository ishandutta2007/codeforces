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
#define taskname "C"
int n;
ll a[300001];
ll b[300001];
ll sa[300001];
ll sb[300001];
ll rwa[300002];
ll rwb[300002];
ll wa[300002];
ll wb[300002];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n){
        read(a[i]);
        sa[i]=sa[i-1]+a[i];
    }
    FOR(i, 1, n){
        read(b[i]);
        sb[i]=sb[i-1]+b[i];
    }
    FOR(i, 1, n){
        wa[i]=wa[i-1]+a[i]*(i-1);
        wb[i]=wb[i-1]+b[i]*(i-1);
    }
    DFOR(i, n, 1){
        rwa[i]=rwa[i+1]+a[i]*(n-i);
        rwb[i]=rwb[i+1]+b[i]*(n-i);
    }
    ll ans=0;
    ll now=0;
    FOR(i, 0, n){
        now+=(a[i]+b[i])*(i-1)*2;
        now+=(i%2)?b[i]:a[i];
        if(i==n){
            ans=max(ans, now);
            break;
        }
        if(i%2){
            ll res=now;
            res+=rwa[i+1]+(sa[n]-sa[i])*(i+n);
            res+=(wb[n]-wb[i])+(sb[n]-sb[i])*i;
            ans=max(ans, res);
        }
        else{
            ll res=now;
            res+=rwb[i+1]+(sb[n]-sb[i])*(i+n);
            res+=(wa[n]-wa[i])+(sa[n]-sa[i])*i;
            ans=max(ans, res);
        }
    }
//    ans-=sa[n];
//    ans-=sb[n];
    writeln(ans);
}