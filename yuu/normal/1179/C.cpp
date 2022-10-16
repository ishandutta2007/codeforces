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
int n, m, k;
vector <pair <int, int>> pa;
class query{
public:
    int t, i, x;
    void input(){
        read(t);
        read(i);
        read(x);
    }
} q[300001];
int a[300001];
int b[300001];
int pos[300001];
int new_pos[300001];
class segment_tree{
public:
    using pointer=segment_tree*;
    int l, r, m;
    int value, lazy;
    ///value=number of student with enough money - number of meal with greater cost
    /// the first value<0 from the right is unbought

    int real;
    pointer left, right;
    segment_tree(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        value=lazy=0;
        real=0;
        if(l!=r){
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
        }
        else left=right=nullptr;
    }
    void up(){
        if(left->real){
            real=left->real;
            if(right->real==0) value=left->value;
            else{
                value=min(left->value, right->value);
                real+=right->real;
            }
        }
        else{
            if(right->real==0) real=0;
            else{
                value=right->value;
                real=right->real;
            }
        }
    }
    void down(){
        left->lazy+=lazy;
        left->value+=lazy;
        right->lazy+=lazy;
        right->value+=lazy;
        lazy=0;
    }
    void remove(int u){
        if(l==r){
            real=0;
        }
        else{
            down();
            if(m>=u) left->remove(u);
            else right->remove(u);
            up();
        }
    }
    void insert(int u){
        if(l==r){
            real=1;
        }
        else{
            down();
            if(m>=u) left->insert(u);
            else right->insert(u);
            up();
        }
    }
    void update(int u, int v, int x){
        if(u>v) return;
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
    int search(){///find the maximum place that is real and less than 0
        if(l==r){
            if(real==0) return -1;
            else if(value>=0) return -1;
            else return l;
        }
        else{
            down();
            if(right->real==0) return left->search();
            else{
                if(right->value<0) return right->search();
                else return left->search();
            }
        }
    }
//    int count_greater(int u){
//        if(r<=u) return 0;
//        else if(l>u) return real;
//        else return left->count_greater(u)+right->count_greater(u);
//    }
};
segment_tree::pointer tree;
int find(int money){
    int l=0, r=pa.size()-1, m, res=-1;
    while(l<=r){
        m=(l+r)/2;
        if(pa[m].first<=money){
            res=m;
            l=m+1;
        }
        else r=m-1;
    }
    return res;
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(m);
    FOR(i, 1, n){
        read(a[i]);
        pa.pb(mp(a[i], -i));
    }
    FOR(i, 1, m) read(b[i]);
    read(k);
    FOR(i, 1, k){
        q[i].input();
        if(q[i].t==1) pa.pb(mp(q[i].x, i));
    }
    sort(pa.begin(), pa.end());
    tree=new segment_tree(0, pa.size()-1);
//    bug(pa.size());
    FFOR(i, 0, pa.size()){
        if(pa[i].second>0) new_pos[pa[i].second]=i;
        else{
            pos[-pa[i].second]=i;
            tree->insert(i);
            tree->update(0, i, -1);
        }
    }
    FOR(i, 1, m) tree->update(0, find(b[i]), 1);
    FOR(i, 1, k){
//        cerr<<tree->real<<' '<<tree->value<<' '<<tree->lazy<<'\n';
        if(q[i].t==1){
            tree->update(0, pos[q[i].i], 1);
            tree->remove(pos[q[i].i]);
            pos[q[i].i]=new_pos[i];
            tree->insert(pos[q[i].i]);
            tree->update(0, pos[q[i].i], -1);
        }
        else{
            tree->update(0, find(b[q[i].i]), -1);
            b[q[i].i]=q[i].x;
            tree->update(0, find(b[q[i].i]), 1);
        }
//        cerr<<tree->real<<' '<<tree->value<<' '<<tree->lazy<<'\n';
        int res=tree->search();
        if(res!=-1) res=pa[res].first;
        writeln(res);
    }
}