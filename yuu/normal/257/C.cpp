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
const ld pi=acos(0)*2;
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
#define taskname "257C"
int n;
struct point{
    ld x, y;
    ld a;
    bool operator <(point X){
        return a<X.a;
    }
    ld gap(point X){
        if(X.a>a) return X.a-a;
        return pi*2+X.a-a;
    }
    void make(){
        if(y==0){
            if(x>0) a=0;
            else a=pi;
        }
        else if(y>0){
            if(x==0) a=(pi/2);
            else if(x>0) a=atan(y/x);
            else a=(pi/2)+atan((-x)/y);
        }
        else{
            if(x==0) a=((pi*3)/2);
            else if(x>0) a=((pi*3)/2)+atan(-x/y);
            else a=pi+atan(y/x);
        }
    }
} p[100000];
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    FFOR(i, 0, n){
        read(p[i].x);
        read(p[i].y);
        p[i].make();
    }
    sort(p, p+n);
    ld ans=pi*2;
    FFOR(i, 0, n) ans=min(ans, p[(i+1)%n].gap(p[i]));
    if(abs(ans-pi*2)<=1e-7) ans=0;
    cout<<setprecision(10)<<fixed<<ans*180/pi;
}