#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
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
#define taskname "A"
#define sqr(x) ((x)*(x))
struct point{
    ld x, y;
} a, b, t, p[100001];
ld d[100001];
ld td;
int n;
ld dist(point A, point B){
    return sqrt(sqr(A.x-B.x)+sqr(A.y-B.y));
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(a.x);
    read(a.y);
    read(b.x);
    read(b.y);
    read(t.x);
    read(t.y);
    read(n);
    FOR(i, 1, n){
        read(p[i].x);
        read(p[i].y);
        d[i]=dist(p[i], t);
        td+=d[i];
    }
    td*=2;
    ld ans=1e18;
    ld best=0;
    FOR(i, 1, n){
        ans=min(ans, td-d[i]+dist(p[i], a)-best);
        best=max(best, d[i]-dist(p[i], b));
    }
    best=0;
    FOR(i, 1, n){
        ans=min(ans, td-d[i]+dist(p[i], b)-best);
        best=max(best, d[i]-dist(p[i], a));
    }
    cout<<setprecision(15)<<fixed<<ans;
}