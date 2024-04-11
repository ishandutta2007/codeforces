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
#define taskname "340B"
struct point{
    ll x, y;
    point(){x=y=0;}
    point(ll _x, ll _y){
        x=_x;
        y=_y;
    }
};
vector <point> p;
struct line{
    ll a, b, c;
    line (point A, point B){
        ///a*A.x+b*A.y+c=0
        ///a*B.x+b*B.y+c=0
        ///a*A.x+b*A.y=a*B.x+b*B.y
        a=B.y-A.y;
        b=A.x-B.x;
        c=-(a*A.x+b*A.y);
    }
    ll at(point P){
        return a*P.x+b*P.y+c;
    }
};
int n;
ll S_tri(point A, point B, point C){
    return abs((B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y));
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    {
        ll x, y;
        FOR(i, 1, n){
            read(x);
            read(y);
            p.pb(point(x, y));
        }
    }
    ll ans=0;
    FFOR(i, 0, n) FFOR(j, i+1, n){
        line l(p[i], p[j]);
        ll up=-1e9, down=-1e9;
        FFOR(k, 0, i) if(l.at(p[k])<0) down=max(down, S_tri(p[i], p[j], p[k]));
        else up=max(up, S_tri(p[i], p[j], p[k]));
        FFOR(k, i+1, j) if(l.at(p[k])<0) down=max(down, S_tri(p[i], p[j], p[k]));
        else up=max(up, S_tri(p[i], p[j], p[k]));
        FFOR(k, j+1, n) if(l.at(p[k])<0) down=max(down, S_tri(p[i], p[j], p[k]));
        else up=max(up, S_tri(p[i], p[j], p[k]));
        ans=max(ans, up+down);
    }
    write(ans/2);
    if(ans%2) puts(".5");
}