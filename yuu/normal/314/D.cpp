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
#define taskname "LINES"
int n, k;
struct point{
    ld x, y;
    bool operator <(point p){
        return x<p.x;
    }
} p[100001];
pair <ld, ld> R[100002];
pair <ld, ld> L[100002];
pair <ld, ld> best(pair <ld, ld> a, pair <ld, ld> b){
    a.first=min(a.first, b.first);
    a.second=max(a.second, b.second);
    return a;
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    FOR(i, 1, n){
        read(p[i].x);
        read(p[i].y);
        ld xx=p[i].x+p[i].y;
        ld yy=p[i].x-p[i].y;
        p[i].x=xx;
        p[i].y=yy;
    }
    sort(p+1, p+n+1);
    L[0]=mp(1e18, -1e18);
    R[n+1]=mp(1e18, -1e18);
    FOR(i, 1, n){
        L[i]=L[i-1];
        L[i].first=min(L[i].first, p[i].y);
        L[i].second=max(L[i].second, p[i].y);
    }
    DFOR(i, n, 1){
        R[i]=R[i+1];
        R[i].first=min(R[i].first, p[i].y);
        R[i].second=max(R[i].second, p[i].y);
    }
    ld l=0, r=1e18, m, ans=-1;
    while(r-l>1e-9){
        m=(l+r)/2;
        int j=1;
        bool good=0;
        FOR(i, 1, n){
            while(j<n&&p[j+1].x<=p[i].x+m*2) j++;
            pair <ld, ld> a=best(L[i-1], R[j+1]);
            if(a.second-a.first<=m*2){
                good=1;
                break;
            }
        }
        if(good){
            ans=m;
            r=m;
        }
        else l=m;
    }
    cout<<setprecision(9)<<fixed<<ans;
}