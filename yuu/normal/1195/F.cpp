#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
#define __builtin_popcount __builtin_popcountll
using ll=long long; using ld=long double;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); const ld pi=acos(0)*2;
template <typename T> inline void read(T &x){char c; bool nega=0; while((!isdigit(c=getchar()))&&(c!='-')); if(c=='-'){nega=1; c=getchar();} x=c-48; while(isdigit(c=getchar())) x=x*10+c-48; if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10); putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){ putchar('-'); x=-x;} writep(x);}
template <typename T> inline void writeln(T x){write(x); putchar('\n');}
template <typename CT, typename T> inline void reset_container(CT &c, int sz, T v){c.resize(sz); for(auto &x: c) x=v;}
#define taskname "F"
int n;
class point{
public:
    ll x, y;
    void input(){
        read(x);
        read(y);
    }
};
class vec{
public:
    ll x, y;
    void fix(){
        ll d=__gcd(abs(x), abs(y));
        x/=d;
        y/=d;
//        cerr<<x<<' '<<y<<'\n';
    }
    vec(point A, point B){
        x=B.x-A.x;
        y=B.y-A.y;
        fix();
    }
    vec(){
    }
};
class cmp{
public:
    bool operator ()(vec A, vec B){
        return (A.x<B.x)||(A.x==B.x&&A.y<B.y);
    }
};
map <vec, int, cmp> M;
vector <vec> v;
vector <int> a;
int l[100001];
int r[100001];
int last[400001];
class query{
public:
    int id;
    int low, high;
    void input(int id){
        this->id=id;
        read(low);
        read(high);
        low=l[low];
        high=r[high];
//        cerr<<id<<' '<<low<<' '<<high<<'\n';
    }
};
int ft[400001];
void update(int u, int x){
    for(; u<=400000; u+=u&-u) ft[u]+=x;
}
int get(int u){
    int res=0;
    for(; u>0; u-=u&-u) res+=ft[u];
    return res;
}
vector <query> q;
#define next FuckingPouredCokeOnMyLaptop
int next[400001];
int ans[400001];
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    v.resize(1);
    FOR(i, 1, n){
        int k;
        read(k);
        vector <point> p;
        p.resize(k);
        l[i]=v.size();
        for(auto &x: p) x.input();
        FFOR(i, 0, k) v.pb(vec(p[i], p[(i+1)%k]));
        r[i]=v.size()-1;
    }
//    for(auto &x: v){
////        cerr<<x.x<<' '<<x.y<<'\n';
//    }
    FFOR(i, 1, v.size()) M[v[i]]=1;
    {
        int cnt=0;
        for(auto &x: M){
            cnt++;
            x.second=cnt;
//            cerr<<x.first.x<<' '<<x.first.y<<' '<<x.second<<'\n';
        }
    }
    FFOR(i, 0, v.size()) a.pb(M[v[i]]);
//    FOR(i, 0, v.size()) cerr<<a[i]<<" \n"[i+1==v.size()];
    int m;
//    cerr<<"OK\n";
    read(m);
    q.resize(m);
    FFOR(i, 0, m) q[i].input(i);
    sort(q.begin(), q.end(), [](query A, query B){
        return A.low<B.low;
    });
    FFOR(i, 1, a.size()){
        if(last[a[i]]){
            next[last[a[i]]]=i;
        }
        else{
            update(i, 1);
        }
        last[a[i]]=i;
    }
    int i=1;
    for(auto &x: q){
        while(i<x.low){
            update(i, -1);
            if(next[i]) update(next[i], 1);
            i++;
        }
        ans[x.id]=get(x.high);
    }
    FFOR(i, 0, m) writeln(ans[i]);
}