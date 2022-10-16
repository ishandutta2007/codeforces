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
#define taskname "C"
int q;
map <pair <int, int>, int> M;
vector <pair <int, int>> backr;
vector <pair <int, int>> backw;
int r[600001];
int w[600001];
int root(int u){
    while(r[u]>0) u=r[u];
    return u;
}
ll ans[300001];
ll now;
void change(int u, ll s){
//    cerr<<r[u]<<' '<<w[u]<<'\n';
    now+=s*(-r[u]-w[u])*(w[u]);
}
void unite(int u, int v){
    u=root(u);
    v=root(v);
    if(u==v) return;
    if(r[u]>r[v]) swap(u, v);
    backr.pb(mp(v, r[v]));
    backw.pb(mp(u, w[u]));
    backr.pb(mp(u, r[u]));
    change(u, -1);
    change(v, -1);
    r[u]+=r[v];
    w[u]+=w[v];
    r[v]=u;
    change(u, 1);
}
void roll_back(){
    while(backr.back().first!=-1){
        change(backr.back().first, -1);
        r[backr.back().first]=backr.back().second;
        w[backw.back().first]=backw.back().second;
        change(backr.back().first, 1);
        backr.pop_back();
        backw.pop_back();
        r[backr.back().first]=backr.back().second;
        change(backr.back().first, 1);
        backr.pop_back();
    }
    backr.pop_back();
    backw.pop_back();
}
class segment_tree{
public:
    using pointer=segment_tree*;
    pointer left, right;
    int l, r, m;
    vector <pair <int, int>> q;
    segment_tree(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        q.clear();
        if(l!=r){
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
        }
        else left=right=nullptr;
    }
    void update(int u, int v, pair <int, int> p){
        if(l>v||r<u) return;
        if(u<=l&&v>=r){
            q.pb(p);
        }
        else{
            left->update(u, v, p);
            right->update(u, v, p);
        }
    }
    void query(){
//        cerr<<l<<' '<<r<<' '<<now<<'\n';
        backr.pb(mp(-1, 0));
        backw.pb(mp(-1, 0));
        for(auto p: q) unite(p.first, p.second);
        if(l!=r){
            left->query();
            right->query();
        }
        else ans[l]=now;
        roll_back();
//        cerr<<l<<' '<<r<<' '<<now<<'\n';
    }
};
segment_tree::pointer tree;
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(q);
    FOR(i, 1, 600000) r[i]=-1;
    FOR(i, 1, 300000) w[i]=1;
    tree=new segment_tree(1, q);
    FOR(i, 1, q){
        pair <int, int> p;
        read(p.first);
        read(p.second);
        p.second+=300000;
        if(M.find(p)!=M.end()){
            tree->update(M[p], i-1, p);
            M.erase(p);
        }
        else M[p]=i;
    }
    for(auto p: M) tree->update(p.second, q, p.first);
    tree->query();
    FOR(i, 1, q) write(ans[i]), putchar(" \n"[i==q]);
}