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
class point{
public:
    ll x, y;
    point(){}
    point(ll _x, ll _y){
        this->x=_x;
        this->y=_y;
    }
    void input(){
        read(x);
        read(y);
    }
};
class cmp{
public:
    bool operator()(point A, point B){
        return (A.x<B.x)||((A.x==B.x)&&(A.y<B.y));
    }
};
map <point, int, cmp> S;
ll ans=0;
class segment{
public:
    point A, B;
    ll a, b, c;
    ///ax+by+c=0
    void input(){
        A.input();
        B.input();
        if(A.x>B.x) swap(A, B);
        a=B.y-A.y;
        b=A.x-B.x;
        c=-(a*A.x+b*A.y);
        ll d=__gcd(abs(a), abs(b));
        d=__gcd(d, abs(c));
        a/=d;
        b/=d;
        c/=d;
        if(a<0){
            a=-a;
            b=-b;
            c=-c;
        }
        else if(a==0){
            if(b<0){
                b=-b;
                c=-c;
            }
        }
    }
    ll count_integer_points(){
        if(A.x==B.x) return abs(B.y-A.y)+1;
        if(B.y==A.y) return abs(A.x-B.x)+1;
        return __gcd(abs(B.x-A.x), abs(B.y-A.y))+1;
    }
    void intersect_with(segment s){
        if(a*s.b==b*s.a) return;///parallel
        if((b*s.c-s.b*c)%(s.a*b-a*s.b)) return;
        ll x=-(b*s.c-s.b*c)/(s.a*b-a*s.b);
        ll y;
        if(b) y=(-c-a*x)/b;
        else y=(-s.c-s.a*x)/s.b;
        if((a*x+b*y+c)||(s.a*x+s.b*y+s.c)) return;
        if((x<A.x)||(x>B.x)) return;
        if((y<min(A.y, B.y))||(y>max(A.y, B.y))) return;
        if((x<s.A.x)||(x>s.B.x)) return;
        if((y<min(s.A.y, s.B.y))||(y>max(s.A.y, s.B.y))) return;
        point P(x, y);
        S[P]++;
    }
} s[1001];
int n;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n) s[i].input();
    FOR(i, 1, n) ans+=s[i].count_integer_points();
    FOR(i, 1, n) FFOR(j, 1, i) s[i].intersect_with(s[j]);
    for(auto t: S){
        int x=t.second;
        int y=sqrt(x*2);
        while(y*(y-1)/2<x) y++;
//        bug(y);
//        cerr<<t.first.x<<' '<<t.first.y<<'\n';
        ans-=y-1;
    }
    writeln(ans);

}