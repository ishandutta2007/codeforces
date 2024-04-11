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
#define taskname "B"
int n;
ll x0, x1;
ll c[300001];
int p[300001];
int f[300001];
int g[300001];
int good(ll x, int k){
    int l=1, r=n, m, res=0;
    while(l<=r){
        m=(l+r)/2;
        if(c[m]*k>=x){
            res=m;
            l=m+1;
        }
        else r=m-1;
    }
    return res;
}
int mf[300001];
int mg[300001];
vector <int> vx0;
vector <int> vx1;
void make(int a, int b){
    int c0=f[a];
    int c1=g[b];
    if(c0>c1){
        FOR(i, 1, n){
            if(vx1.size()<b){
                vx1.pb(p[i]);
            }
            else if(vx0.size()<a){
                vx0.pb(p[i]);
            }
        }
    }
    else{
        FOR(i, 1, n){
            if(vx0.size()<a){
                vx0.pb(p[i]);
            }
            else if(vx1.size()<b){
                vx1.pb(p[i]);
            }
        }
    }
    puts("Yes");
    write(vx0.size());
    putchar(' ');
    writeln(vx1.size());
    for(int k: vx0) write(k), putchar(' ');
    putchar('\n');
    for(int k: vx1) write(k), putchar(' ');
    exit(0);
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(x0);
    read(x1);
    FOR(i, 1, n) read(c[i]);
    FOR(i, 1, n) p[i]=i;
    sort(p+1, p+n+1, [](int a, int b){
        return c[a]>c[b];
    });
    sort(c+1, c+n+1, greater<ll>());

    FOR(i, 1, n){
        mf[i]=1e9;
        f[i]=good(x0, i);
    }
    FOR(i, 1, n){
        mg[i]=1e9;
        g[i]=good(x1, i);
    }
    FOR(i, 1, n) if(i<=f[i]) mf[f[i]]=min(mf[f[i]], i);
    FOR(i, 1, n) if(i<=g[i]) mg[g[i]]=min(mg[g[i]], i);
    int min_x0=1e9;
    int min_x1=1e9;
    FOR(i, 1, n){
        min_x0=min(min_x0, mf[i]);
        min_x1=min(min_x1, mg[i]);
        if(min_x0+mg[i]<=i) make(min_x0, mg[i]);
        if(min_x1+mf[i]<=i) make(mf[i], min_x1);
    }
    puts("No");
}