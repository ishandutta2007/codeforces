#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(ll i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(ll i=(j); i<(k); i++)
#define DFOR(i, j, k) for(ll i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
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
#define taskname "F"
ll n, k;
ll x[300001];
ll y[300001];
ll fx;
ll fy;
void apply(ll x, ll y){
    ll gx, gy;
    gx=gy=1e9;
    if(fx<=k){
        ///y first, y last
        if(x>=y-1){
            if(x<=(y-1)*k) gy=min(gy, 1LL);
        }
        else{
            gy=min(gy, y-x*k);
        }
        ///x first, y last
        if(x>=y){
            if(x>(y-1)*k){
                if((x-(k-fx))<=(y-1)*k){
                    gy=min(gy, 1LL);
                }
            }
        }
        ///y first, x last
        if(y>x){
            if(x*k>=y){
                gx=min(gx, 1LL);
            }
        }
        else{
            gx=min(gx, x-(y-1)*k);
        }
        ///x first, x last
        ///this can degenerate into y first in some cases, but it shouldn't effect the over all score
        if(y<=x) gx=min(gx, x-(k-fx)-(y-1)*k);
    }
    if(fy<=k){
        ///x first, x last
        if(y>=x-1){
            if(y<=(x-1)*k) gx=min(gx, 1LL);
        }
        else{
            gx=min(gx, x-y*k);
        }
        ///y first, x last
        if(y>=x){
            if(y>(x-1)*k){
                if((y-(k-fy))<=(x-1)*k){
                    gx=min(gx, 1LL);
                }
            }
        }
        ///x first, y last
        if(x>y){
            if(y*k>=x){
                gy=min(gy, 1LL);
            }
        }
        else{
            gy=min(gy, y-(x-1)*k);
        }
        ///y first, y last
        ///this can degenerate into x first in some cases, but it shouldn't effect the over all score
        if(x<=y) gy=min(gy, y-(k-fy)-(x-1)*k);
    }
    gx=max(gx, 1LL);
    gy=max(gy, 1LL);
    fx=gx;
    fy=gy;
    if(fx>k&&fy>k){
        puts("NO");
        exit(0);
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(k);
    FOR(i, 1, n) read(x[i]);
    FOR(i, 1, n) read(y[i]);
    FOR(i, 1, n) apply(x[i], y[i]);
    puts("YES");
}