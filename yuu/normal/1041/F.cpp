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
#define taskname "F"
#define y0 Hidan
#define y1 Aria
int n, m;
ll y0, y1;
ll a[100001];
ll b[100001];
ll random(ll l, ll r){
    ll a=rand();
    a=a*rand();
    a=a*rand();
    a%=r-l+1;
    if(a<0) a+=r-l+1;
    return a+l;
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    srand(time(NULL));
    read(n);
    read(y0);
    FOR(i, 1, n) read(a[i]);
    read(m);
    read(y1);
    FOR(i, 1, m) read(b[i]);
    if(n==1&&m==1){
        writeln(2);
        return 0;
    }
    int ans=2;
    int lim=6;
    FOR(cnt, 1, lim){///random a and b
        ll pa=a[random(1, n)];
        ll pb=b[random(1, m)];
        while(pa==pb){
            pa=a[random(1, n)];
            pb=b[random(1, m)];
        }
        ll c=abs(pa-pb);
        int c2=0;
        while(c%2==0){
            c2++;
            c/=2;
        }
        ll x=1LL<<c2;
        ll x2=x*2;
        ll amx2=pa%x2;
        ll bmx2=pb%x2;
        ///check x
        if((pa%x2+x-pb)%(x2)==0){
            int res=0;
            FOR(i, 1, n) res+=(a[i]%x2)==amx2;
            FOR(i, 1, m) res+=(b[i]%x2)==bmx2;
            ans=max(ans, res);
        }
    }
    FOR(cnt, 1, lim){///random a and a
        if(n==1) break;
        if((n==2)&&((a[1]-a[2])%2)) break;
        ll pa0=a[random(1, n)];
        ll pa1=a[random(1, n)];
        while((pa0==pa1)||((pa0-pa1)%2)){
            pa0=a[random(1, n)];
            pa1=a[random(1, n)];
        }
        ll c=abs(pa0-pa1);
        int c2=0;
        while(c%2==0){
            c2++;
            c/=2;
        }
        c2--;
        ll x=1LL<<c2;
        ll x2=x*2;
        ll amx2=pa0%x2;
        ll bmx2=(pa0+x)%x2;
        ///check x
        int res=0;
        FOR(i, 1, n) res+=(a[i]%x2)==amx2;
        FOR(i, 1, m) res+=(b[i]%x2)==bmx2;
        ans=max(ans, res);
        x=x2;
    }
    FOR(cnt, 1, lim){///random b and b
        if(m==1) break;
        if((m==2)&&((b[1]-b[2])%2)) break;
        ll pb0=b[random(1, m)];
        ll pb1=b[random(1, m)];
        while((pb0==pb1)||((pb0-pb1)%2)){
            pb0=b[random(1, m)];
            pb1=b[random(1, m)];
        }
        ll c=abs(pb0-pb1);
        int c2=0;
        while(c%2==0){
            c2++;
            c/=2;
        }
        c2--;
        ll x=1LL<<c2;
        ll x2=x*2;
        ll bmx2=pb0%x2;
        ll amx2=(pb0+x)%x2;
        ///check x
        int res=0;
        FOR(i, 1, n) res+=(a[i]%x2)==amx2;
        FOR(i, 1, m) res+=(b[i]%x2)==bmx2;
        ans=max(ans, res);
        x=x2;
    }
    writeln(ans);
}