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
int a[300001];
int b[300001];
class segment_tree{
public:
    using pointer=segment_tree*;
    pointer left, right;
    int l, r, m;
    int mi;
    segment_tree(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        if(l==r){
            mi=a[l];
        }
        else{
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
            mi=min(left->mi, right->mi);
        }
    }
    void update(int u){
        if(l==r) mi=1e9;
        else{
            if(m>=u) left->update(u);
            else right->update(u);
            mi=min(left->mi, right->mi);
        }
    }
    int get(int u, int v){
        if(l>v||r<u) return 1e9;
        if(u<=l&&v>=r) return mi;
        else return min(left->get(u, v), right->get(u, v));
    }
};
segment_tree::pointer tree;
deque <int> pos[300001];
int n;
void solve(){
    read(n);
    FOR(i, 1, n) pos[i].clear();
    FOR(i, 1, n){
        read(a[i]);
        pos[a[i]].pb(i);
    }
    FOR(i, 1, n) read(b[i]);
    tree=new segment_tree(1, n);
    FOR(i, 1, n){
        if(pos[b[i]].empty()){
            puts("NO");
            return;
        }
        int j=pos[b[i]].front();
        pos[b[i]].pop_front();
        if(tree->get(1, j)<b[i]){
            puts("NO");
            return;
        }
        tree->update(j);
    }
    puts("YES");
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    int t;
    read(t);
    while(t--) solve();
}