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
#define taskname "C"
#define x first
#define v second
int n, t;
ll s;
vector <pair <ll, ll> > v[3];
pair <ll, ll> p;
ld l[1000001];
ld r[1000001];
struct segment_interval{
    static const int nmax=1000001;
    #define type ld
    #define cmp <
    struct line{
        type a, b;
        line (type _a, type _b){
            a=_a;
            b=_b;
        }
        line (){
            a=b=0;
        }
    } L[nmax*4];
    void init(type y){
        DFOR(i, nmax*4-1, 1){
            L[i].a=0;
            L[i].b=y;
        }
    }
    bool done[nmax*4];
    public: int n=1000000;
    void update(int i, int l, int r, int u, int v, line x){
        if(l>v||r<u) return;
        if(u<=l&&v>=r){
            bool b1=(L[i].a*l+L[i].b) cmp (x.a*l+x.b);
            bool b2=(L[i].a*r+L[i].b) cmp (x.a*r+x.b);
            if((b1||b2)==0){
                L[i]=x;
            }
            else if(b1^b2){
                int m=(l+r)/2;
                update(2*i, l, m, u, v, x);
                update(2*i+1, m+1, r, u, v, x);
            }
        }
        else{
            int m=(l+r)/2;
            update(2*i, l, m, u, v, x);
            update(2*i+1, m+1, r, u, v, x);
        }
    }
    type get(int i, int l, int r, int u){
        if(l==r) return L[i].a*u+L[i].b;
        else{
            int m=(l+r)/2;
            type res;
            if(u>m) res=get(2*i+1, m+1, r, u);
            else res=get(2*i, l, m, u);
            type res2=L[i].a*u+L[i].b;
            res=(res cmp res2)?res:res2;
            return res;
        }
    }
    void add(int l, int r, type a, type b){
        update(1, 1, n, l, r, line(a, b));
    }
    type get(int u){
        return get(1, 1, n, u);
    }
    #undef cmp
    #undef type
} SI, SII;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(s);
    FOR(i, 1, n){
        read(p.x);
        read(p.v);
        read(t);
        v[t].pb(p);
    }
    l[0]=1000000;
    ll minx=1000000;
    for(pair <ll, ll> p: v[1]) l[0]=min(l[0], (ld(p.x))/p.v);
    SI.init(l[0]);
    for(pair <ll, ll> p: v[1]){
        minx=min(minx, p.x);
        ll last=(s*p.x)/p.v;
        last=min(last, 1000000LL);
        SI.add(p.x, last, (ld(s))/((s-p.v)*(s+p.v)), -(ld(p.x*p.v))/((s-p.v)*(s+p.v)));
    }
    FOR(i, 1, 1000000){
        l[i]=l[0];
        l[i]=min(l[i], SI.get(i));
    }
    FFOR(i, 0, v[2].size()) v[2][i].x=1000000-v[2][i].x;
    minx=1000000;
    r[0]=1000000;
    for(pair <ll, ll> p: v[2]) r[0]=min(r[0], (ld(p.x))/p.v);
    SII.init(r[0]);
    for(pair <ll, ll> p: v[2]){
        minx=min(minx, p.x);
        ll last=(s*p.x)/p.v;
        last=min(last, 1000000LL);
        SII.add(p.x, last, (ld(s))/((s-p.v)*(s+p.v)), -(ld(p.x*p.v))/((s-p.v)*(s+p.v)));
    }
    FOR(i, 1, 1000000){
        r[i]=r[0];
        r[i]=min(r[i], SII.get(i));
    }
    reverse(r+1, r+1000000);
    ld ans=1000000;
    FOR(i, 1, 999999) ans=min(ans, max(l[i], r[i]));
    cout<<setprecision(15)<<fixed<<ans;
}