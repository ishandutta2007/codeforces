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
#define taskname "A"
ll n, m, cl, ce, v;
vector <ll> pl;
vector <ll> pe;
ll first_greater_or_equal(vector <ll> &x, ll p){
    int l=0, r=x.size()-1, m, res;
    while(l<=r){
        m=(l+r)/2;
        if(x[m]>=p){
            res=m;
            r=m-1;
        }
        else l=m+1;
    }
    return x[res];
}
ll last_smaller_or_equal(vector <ll> &x, ll p){
    int l=0, r=x.size()-1, m, res;
    while(l<=r){
        m=(l+r)/2;
        if(x[m]<=p){
            res=m;
            l=m+1;
        }
        else r=m-1;
    }
    return x[res];
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(m);
    read(cl);
    read(ce);
    read(v);
    pl.resize(cl);
    for(ll &x: pl) read(x);
    pe.resize(ce);
    for(ll &x: pe) read(x);
    sort(pl.begin(), pl.end());
    sort(pe.begin(), pe.end());
    pl.erase(unique(pl.begin(), pl.end()), pl.end());
    pe.erase(unique(pe.begin(), pe.end()), pe.end());
    {
        int q;
        read(q);
        ll x0, y0, x1, y1, a;
        FOR(i, 1, q){
            read(x0);
            read(y0);
            read(x1);
            read(y1);
            if(x0>x1){
                swap(x0, x1);
                swap(y0, y1);
            }
            x1-=x0;
            x0=0;
            if(x1==0){
                writeln(abs(y0-y1));
                continue;
            }
            ///go from (0, y0) to (x1, y1)
            ll res=mask(60);
            if((!pl.empty())&&(pl.back()>=y0)){
                a=first_greater_or_equal(pl, y0);
                res=min(res, abs(a-y0)+abs(a-y1)+x1);
            }
            if((!pl.empty())&&(pl[0]<=y0)){
                a=last_smaller_or_equal(pl, y0);
                res=min(res, abs(a-y0)+abs(a-y1)+x1);
            }
            if((!pe.empty())&&(pe.back()>=y0)){
                a=first_greater_or_equal(pe, y0);
                res=min(res, abs(a-y0)+abs(a-y1)+((x1-1)/v+1));
            }
            if((!pe.empty())&&(pe[0]<=y0)){
                a=last_smaller_or_equal(pe, y0);
                res=min(res, abs(a-y0)+abs(a-y1)+((x1-1)/v+1));
            }
            writeln(res);
        }
    }
}