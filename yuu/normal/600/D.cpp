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
#define taskname "D"
#define sqr(x) ((x)*(x))
const ld pi=acosl(0)*2;
class point{
public:
    ld x, y;
    void input(){
        read(x);
        read(y);
    }
    void operator -=(point P){
        x-=P.x;
        y-=P.y;
    }
    void fix(){
        x=abs(x);
        y=abs(y);
    }
    ld dist(point P){
        return sqrt(sqr(P.x-x)+sqr(P.y-y));
    }
    ld weight(){
        return sqrt(sqr(x)+sqr(y));
    }
};
class circle{
public:
    point O;
    ld r;
    void input(){
        O.input();
        read(r);
    }
    ld area(){
        return pi*sqr(r);
    }
    ld lune_area(ld angle){
        return (angle/2)*sqr(r)-sqr(r)*sinl(angle)/2;
    }
} c0, c1;
const ld eps=1e-9;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    cout<<setprecision(16)<<fixed;
    c0.input();
    c1.input();
    if(c0.r<c1.r) swap(c0, c1);
    c1.O-=c0.O;
    c0.O-=c0.O;
    c1.O.fix();
    if(c1.O.weight()+c1.r<=c0.r+eps) cout<<c1.area();
    else if(c1.O.weight()-c1.r>=c0.r+eps) cout<<((ld)0);
    else{
        c1.O.x=c1.O.weight();
        c1.O.y=0;
        ///solve triangle (c0.r, c1.r, c1.O.weight())
        ld AB=c0.r;
        ld AC=c1.r;
        ld BC=c1.O.weight();
        ld thetaB=acosl(-(sqr(AC)-sqr(AB)-sqr(BC))/(AB*BC*2));
        ld thetaC=acosl(-(sqr(AB)-sqr(AC)-sqr(BC))/(AC*BC*2));
        cout<<c0.lune_area(thetaB*2)+c1.lune_area(thetaC*2);
    }
}