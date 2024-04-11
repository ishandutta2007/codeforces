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
ll s, a, b;
ll l[200002];
ll r[200002];
int n, q;
class point{
public:
    ll x, y;
    point(){x=y=0;}
    point(ll _x, ll _y){
        x=_x;
        y=_y;
    }
    operator -=(point X){
        x-=X.x;
        y-=X.y;
    }
    void input(){
        read(x);
        read(y);
    }
};
class line{
public:
    ll a, b, c;
    point A, B;
    line(){a=b=c=0;}
    line(point A, point B){
        this->A=A;
        this->B=B;
        a=B.y-A.y;
        b=A.x-B.x;
        c=A.x*a+A.y*b;
    }
    ld x_at_y(ll y){
        return ((ld)(c-y*b))/a;
    }
};
point A, B, P;
bool ccw(point O, point A, point B){
    A-=O;
    B-=O;
    return (A.x*B.y-B.x*A.y)>=0;
}
int first_right_of(line L){
    int low=1, high=n, res=n+1, mid;
    while(low<=high){
        mid=(low+high)/2;
        if(ccw(L.B, point(l[mid], 0), L.A)){
            res=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return res;
}
int last_left_of(line L){
    int low=1, high=n, res=0, mid;
    while(low<=high){
        mid=(low+high)/2;
        if(ccw(L.A, point(r[mid], 0), L.B)){
            res=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return res;
}
ll sum[200001];
ld solve(){
    P.input();
    line PA(P, A);
    line PB(P, B);
    ld x0=PA.x_at_y(0);
    ld x1=PB.x_at_y(0);
    int i=last_left_of(PA);
    int j=first_right_of(PB);
//    bug(x0);
//    bug(x1);
    i++;
    j--;
//    bug(i);
//    bug(j);
    if(i>j) return 0;
    ld cover=0;
    x0=max(x0, (ld)l[i]);
    x1=min(x1, (ld)r[j]);
    if(i==j) cover=x1-x0;
    else cover=((ld)(sum[j-1]-sum[i]))+r[i]-x0+x1-l[j];
    return cover*(((ld)(P.y-A.y))/P.y);
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(s);
    read(a);
    read(b);
    A=point(a, s);
    B=point(b, s);
    read(n);
    FOR(i, 1, n){
        read(l[i]);
        read(r[i]);
        sum[i]=sum[i-1]+r[i]-l[i];
    }
    r[0]=-1e10;
    l[n+1]=1e10;
    read(q);
    while(q--) cout<<setprecision(16)<<fixed<<solve()<<'\n';
}