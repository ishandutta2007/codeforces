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
#define sqr(x) ((x)*(x))
ll r, x0, y0, x1, y1;
ld ax, ay, ar;
ll dist2(ll x0, ll y0, ll x1, ll y1){
    return sqr(x0-x1)+sqr(y0-y1);
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(r);
    read(x0);
    read(y0);
    read(x1);
    read(y1);
    x1-=x0;
    y1-=y0;
    if(sqr(x1)+sqr(y1)>=sqr(r)){
        ax=ay=0;
        ar=r;
    }
    else if(x1==0){
        ax=0;
        if(y1>0){
            ay=(y1-r);
            ay/=2;
            ar=(y1+r);
            ar/=2;
        }
        else{
            ay=(r+y1);
            ay/=2;
            ar=(r-y1);
            ar/=2;
        }
    }
    else{
        ld x=((ld)r)/(sqrt(sqr(((ld)y1)/x1)+((ld)1)));
        if(x1>0) x=-x;
        ld y=(x*y1)/x1;
        ax=(x+x1)/2;
        ay=(y+y1)/2;
        ar=sqrt(sqr(x-x1)+sqr(y-y1))/2;
    }
    ax+=x0;
    ay+=y0;
    cout<<setprecision(10)<<fixed<<ax<<' '<<ay<<' '<<ar;
}