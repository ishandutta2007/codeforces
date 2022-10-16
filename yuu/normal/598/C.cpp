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
#define taskname "C"
#define sqr(x) ((x)*(x))
int n;
class point{
public:
    ll x, y;
    int id;
    void input(int id){
        read(x);
        read(y);
        this->id=id;
    }
    void operator -=(point P){
        x-=P.x;
        y-=P.y;
    }
    ll dist2(point P){
        return sqr(x-P.x)+sqr(y-P.y);
    }
} p[100000];
point O;
bool ccw(point O, point A, point B){
    A-=O;
    B-=O;
    return ((A.x*B.y)-(B.x*A.y))>0;
}
const ld pi=acosl(0)*2;
class num: vector <ll>{
public:
    static const ll base=10000;
    num(ll x){
        clear();
        while(x>0){
            pb(x%base);
            x/=base;
        }
        if(empty()) pb(0);
    }
    num(){
        clear();
        pb(0);
    }
    void fix(){
        FFOR(i, 0, size()) if((*this)[i]>=base){
            if(i+1==size()) pb(0);
            (*this)[i+1]+=(*this)[i]/base;
            (*this)[i]%=base;
        }
        while((size()>1)&&(back()==0)) pop_back();
    }
    num operator *(num y){
        num res;
        while(res.size()<size()+y.size()) res.pb(0);
        FFOR(i, 0, size()) FFOR(j, 0, y.size()) res[i+j]+=(*this)[i]*y[j];
        res.fix();
        return res;
    }
    bool operator <(num x){
        if(size()!=x.size()) return size()<x.size();
        DFOR(i, size()-1, 0) if((*this)[i]!=x[i]) return (*this)[i]<x[i];
        return 0;
    }
};
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    if(n==2){
        puts("1 2");
        return 0;
    }


    FFOR(i, 0, n) p[i].input(i);
    sort(p, p+n, [](point A, point B){
        if(A.y*B.y<0) return A.y>B.y;
        return ccw(O, A, B);
    });
    int best=0;
    num restop=0, resbot=1;
    ld res=pi*2;
    if(n==3){
        const ld eps=1e-12;
        FFOR(i, 0, n){
            if(ccw(O, p[i], p[(i+1)%n])){
                ld now=acosl((((ld)(p[i].x*p[(i+1)%n].x+p[i].y*p[(i+1)%n].y)))/sqrtl(O.dist2(p[i])*O.dist2(p[(i+1)%n])));
                if(res>now+eps){
                    res=now;
                    best=i;
                }
            }
        }
    }
    else{
        FFOR(i, 0, n){
            if(ccw(O, p[i], p[(i+1)%n])){
                if(p[i].x*p[(i+1)%n].x+p[i].y*p[(i+1)%n].y<0) continue;
                num top=sqr(p[i].x*p[(i+1)%n].x+p[i].y*p[(i+1)%n].y);
                num bot=O.dist2(p[i])*O.dist2(p[(i+1)%n]);
                ///cos=p[i].x*p[(i+1)%n].x+p[i].y*p[(i+1)%n].y
                if(restop*bot<top*resbot){
                    restop=top;
                    resbot=bot;
                    best=i;
                }
            }
        }
    }
    write(p[best].id+1);
    putchar(' ');
    writeln(p[(best+1)%n].id+1);
}