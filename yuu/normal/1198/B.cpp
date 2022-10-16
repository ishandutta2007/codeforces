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
int n;
int a[200001];
class segment_tree{
public:
    using pointer=segment_tree*;
    int l, r, m;
    int value=0;
    pointer left, right;
    segment_tree(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        if(l!=r){
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
            value=0;
        }
        else{
            left=right=nullptr;
            value=a[l];
        }
    }
    void update(int x){
        value=max(value, x);
    }
    void down(){
        left->value=max(left->value, value);
        right->value=max(right->value, value);
        value=0;
    }
    int set(int u, int x){
        if(l==r){
            value=x;
        }
        else{
            down();
            if(m>=u) left->set(u, x);
            else right->set(u, x);
        }
    }
    void out(){
        if(l==r){
            write(value);
            putchar(" \n"[r==n]);
        }
        else{
            down();
            left->out();
            right->out();
        }
    }
};
segment_tree::pointer tree;
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    FOR(i, 1, n) read(a[i]);
    tree=new segment_tree(1, n);
    int q;
    read(q);
    int o, p, x;
    FOR(i, 1, q){
        read(o);
        if(o==1){
            read(p);
            read(x);
            tree->set(p, x);
        }
        else{
            read(x);
            tree->update(x);
        }
    }
    tree->out();
}