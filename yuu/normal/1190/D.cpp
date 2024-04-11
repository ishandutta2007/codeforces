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
#define taskname "D"
map <int, int> My;
class point{
public:
    int x, y;
    void input(){
        read(x);
        read(y);
        My[y]=1;
    }
    void fix(){
        y=My[y];
    }
};
int n;
point p[200001];
ll ft2[200002];
void update2(int u, ll x){
    for(; u>0; u-=u&-u) ft2[u]+=x;
}
ll get2(int u){
    ll res=0;
    for(; u<=200000; u+=u&-u) res+=ft2[u];
    return res;
}
ll ft[200001];
void update(int u, ll x){
    for(; u<=200000; u+=u&-u) ft[u]+=x;
}
ll get(int u){
    ll res=0;
    for(; u>0; u-=u&-u) res+=ft[u];
    return res;
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    FOR(i, 1, n) p[i].input();
    {
        int k=0;
        for(auto &y: My){
            k++;
            y.second=k;
        }
    }
    FOR(i, 1, n) p[i].fix();
    sort(p+1, p+n+1, [](point A, point B){
        return (A.x<B.x)||(A.x==B.x&&A.y<B.y);
    });
    ll ans=0;
    FOR(i, 1, n){
        int j=i;
        while((j<n)&&(p[j+1].x==p[i].x)) j++;
        update2(p[j].y, 1);
        FOR(k, i, j) update(p[k].y, -(get(p[k].y)-get(p[k].y-1)));
        FOR(k, i, j) update(p[k].y, get2(p[k].y));
        ans+=get(p[j].y);
        i=j;
    }
    writeln(ans);
}