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
#define taskname "F"
const ll base=1000000007;
int n;
ll x[500002];
ll add(ll a, ll b){
    a+=b;
    while(a>=base) a-=base;
    return a;
}
class segment_tree{
public:
    using pointer=segment_tree*;
    int l, r, m;
    pointer left, right;
    ll a, b;
    segment_tree(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        if(l!=r){
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
            a=b=0;
        }
        else{
            a=b=0;
        }
    }
    void down(){
        left->a=add(left->a, a);
        left->b=add(left->b, b);
        right->a=add(right->a, a);
        right->b=add(right->b, b);
        a=b=0;
    }
    pair <ll, ll> get(int u){
        if(l==r) return mp(a, b);
        else{
            down();
            if(m>=u) return left->get(u);
            else return right->get(u);
        }
    }
    void update(int u, int v, ll aa, ll bb){
        if(l>v||r<u) return;
        if(u<=l&&v>=r){
            a=add(a, aa);
            b=add(b, bb);
        }
        else{
            down();
            left->update(u, v, aa, bb);
            right->update(u, v, aa, bb);
        }
    }
};
segment_tree::pointer tree;
vector <int> order;
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    x[0]=1e18;
    FOR(i, 1, n) read(x[i]);
    tree=new segment_tree(1, n);
    FOR(i, 1, n) order.pb(i);
    sort(order.begin(), order.end(), [](int a, int b){
        return x[a]>x[b];
    });
    for(int u: order){
        auto res=tree->get(u);
        tree->update(u, u, base-res.first, base-res.second);
        tree->update(u, n, base-u, ((ll)(n+1))*u);
        if(u>1) tree->update(1, u-1, n-u+1, 0);
    }
    ll ans=0;
    FOR(i, 1, n){
        auto res=tree->get(i);
        ll cnt=(res.first*i+res.second)%base;
        ans=(ans+cnt*x[i])%base;
    }
    if(ans<0) ans+=base;
    writeln(ans);
}