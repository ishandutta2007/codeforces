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
#define taskname "D"
int n;
int random(int l, int r){
    ll t=rand()*rand();
    t*=rand();
    t%=(r-l+1);
    if(t<0) t+=r-l+1;
    return l+t;
}
class point{
public:
    ll x, y;
    void input(){
        read(x);
        read(y);
    }
} p[100001];
class line{
public:
    ll a, b, c;
    ///ax+by=c
    line(point A, point B){
        a=B.y-A.y;
        b=A.x-B.x;
        c=A.x*a+A.y*b;
    }
    bool contain(point P){
        return P.x*a+P.y*b==c;
    }
};
vector <int> out;
void yes(){
    puts("YES");
    exit(0);
}
void check(int x, int y){
    line l(p[x], p[y]);
    out.clear();
    FOR(i, 1, n) if(!l.contain(p[i])) out.pb(i);
    if(out.size()<=2) yes();
    line d(p[out[0]], p[out[1]]);
    for(int i: out) if(!d.contain(p[i])) return;
    yes();
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    if(n<=4){
        puts("YES");
        return 0;
    }
    FOR(i, 1, n) p[i].input();
    srand(time(NULL));
    FOR(i, 1, 30){
        int x=random(1, n);
        int y=random(1, n);
        while(x==y){
            x=random(1, n);
            y=random(1, n);
        }
        check(x, y);
    }
    puts("NO");
}