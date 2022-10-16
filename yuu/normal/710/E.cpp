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
#define taskname "E"
int n;
ll f[10000001];
ll x, y;
deque <pair <ll, int> > d;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(x);
    read(y);
    FOR(i, 1, n) f[i]=1e18;
    FOR(i, 1, n){
        f[i]=min(f[i], f[i-1]+x);
        while((!d.empty())&&(d.front().second<=i)) d.pop_front();
        if(!d.empty()) f[i]=min(f[i], d.front().first-x*i);
        if(i*2<=n){
            f[i*2]=min(f[i*2], f[i]+y);
            while((!d.empty())&&(f[i*2]+x*i*2<=d.back().first)) d.pop_back();
            d.pb(mp(f[i*2]+x*i*2, i*2));
        }
        else{
            f[n]=min(f[n], x*(i*2-n)+f[i]+y);
        }
    }
    writeln(f[n]);
}