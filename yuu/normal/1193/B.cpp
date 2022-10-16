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
#define taskname "B"
int n, m, k;
vector <int> g[100001];
int d[100001];
int w[100001];
class segment_tree{
public:
    using pointer=segment_tree*;
    int l, r, m;
    int real;
    ll value, lazy;
    pointer left, right;
    segment_tree(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        value=lazy=0;
        real=0;
        left=right=nullptr;
    }
    ~segment_tree(){
        if(left!=nullptr){
            delete left;
            delete right;
        }
    }
    void down(){
        if(left==nullptr){
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
        }
        left->value+=lazy;
        right->value+=lazy;
        left->lazy+=lazy;
        right->lazy+=lazy;
        lazy=0;
    }
    void up(){
        value=max(left->value, right->value);
        real=left->real+right->real;
    }
    void update(int u, int v, ll x){
        if(l>v||r<u) return;
        if(u<=l&&v>=r){
            value+=x;
            lazy+=x;
        }
        else{
            down();
            left->update(u, v, x);
            right->update(u, v, x);
            up();
        }
    }
    void set_max(int u, ll x){///max from u to next
        if(l==r){
            value=max(value, x);
            real=1;
        }
        else{
            down();
            if(m>=u) left->set_max(u, x);
            else right->set_max(u, x);
            up();
        }
    }
    ll get_max(int u, int v){
        if((l>v)||(r<u)||(!real)) return 0;
        if(u<=l&&v>=r) return value;
        else{
            down();
            return max(left->get_max(u, v), right->get_max(u, v));
        }
    }
    void get_pos(vector <pair <int, ll>> &v){
        if(!real) return;
        if(l==r){
            if((v.empty())||(v.back().second<value)) v.pb(mp(l, value));
        }
        else{
            down();
            left->get_pos(v);
            right->get_pos(v);
        }
    }
//    void update_tree(pointer tree){
//        if(!real) return;
//        if(l==r) tree->update(l, n, value);
//        else{
//            left->update_tree(tree);
//            right->update_tree(right);
//        }
//    }
};
segment_tree::pointer tree[100001];
//map <int, ll> *s[100001];
//void insert(map <int, ll> *s, pair <int, ll> p){
//    if((s->lower_bound(p.first))->second>=p.second) return;
//    (*s)[p.first]=p.second;
//    while(true){
//        auto temp=s->upper_bound(p.first);
//        if(temp==s->end()) return;
//        if(temp->second>p.second) return;
//        s->erase(temp);
//    }
//}
void dp(int u){
    if(g[u].empty()){
        tree[u]=new segment_tree(1, k);
        tree[u]->set_max(1, 0);
        tree[u]->set_max(d[u], w[u]);
    }
    else{
        for(int v: g[u]) dp(v);
        for(int v: g[u]) if(tree[u]==nullptr||tree[u]->real<tree[v]->real) tree[u]=tree[v];
//        bug(u);
        for(int v: g[u]) if(tree[u]!=tree[v]){
            vector <pair <int, ll>> a;
            vector <pair <int, ll>> b;
            tree[v]->get_pos(a);
            for(auto &x: a) b.pb(mp(x.first, x.second+tree[u]->get_max(1, x.first)));
//                x.second+=tree->get_max(1, x.first);
            a.pb(mp(k+1, 0));
            FFOR(i, 1, a.size()) tree[u]->update(a[i-1].first, a[i].first-1, a[i-1].second);
            for(auto &x: b) tree[u]->set_max(x.first, x.second);
//            bug(v);
//            for(auto &x: a) cerr<<x.first<<' '<<x.second<<'\n';
//            bug(tree[u]->get_max(1, 9));
//            bug(tree[u]->get_max(9, 9));
////            for(auto &x: *s[v]) insert(s[u], x);
            delete tree[v];
        }
        if(d[u]){
            auto best=tree[u]->get_max(1, d[u]);
//            bug(tree[u]->get_max(1, 9));
//            bug(best+w[u]);
            if(d[u]) tree[u]->set_max(d[u], best+w[u]);
        }
    }
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(m);
    read(k);
    {
        int p;
        FOR(i, 2, n){
            read(p);
            g[p].pb(i);
        }
    }
    {
        int v;
        FOR(i, 1, m){
            read(v);
            read(d[v]);
            read(w[v]);
        }
    }
    dp(1);
    writeln(tree[1]->value);
}