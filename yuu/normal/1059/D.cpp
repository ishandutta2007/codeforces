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
int n;
ld miny=1e9, maxy=-1e9;
class point{
public:
    ld x, y;
    void input(){
        read(x);
        read(y);
        miny=min(miny, y);
        maxy=max(maxy, y);
    }
} p[100000];
ld min_dist(ld x){
    ld res=0;
    FFOR(i, 0, n) res=max(res, (sqr(p[i].y)+sqr(x-p[i].x))/(p[i].y*2));
    return res;
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    cout<<setprecision(8)<<fixed;
    read(n);
    FFOR(i, 0, n) p[i].input();
    if(miny<0&&maxy>0){
        puts("-1");
        return 0;
    }
    FOR(i, 0, n) p[i].y=abs(p[i].y);
    ld low=-1e8, high=1e8, llh, lhh;
    FOR(cnt, 1, 200){
        llh=(low+low+high)/3;
        lhh=(low+high+high)/3;
        if(min_dist(llh)<min_dist(lhh)) high=lhh;
        else low=llh;
    }
    cout<<min_dist(low);
}