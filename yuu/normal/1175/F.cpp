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
int n;
int a[300001];
int last[300001];
int first[300001];
class segment_tree{
public:
    using pointer=segment_tree*;
    int l, r, m;
    pointer left, right;
    int value;
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
            value=0;
        }
    }
    segment_tree(pointer p){
        this->l=p->l;
        this->r=p->r;
        this->m=p->m;
        this->value=p->value;
        this->left=p->left;
        this->right=p->right;
    }
    pointer update(int u){
        pointer res=new segment_tree(this);
        res->value++;
        if(res->l!=res->r){
            if(m>=u) res->left=res->left->update(u);
            else res->right=res->right->update(u);
        }
        return res;
    }
    int get(int u, int v){
        if(l>v||r<u) return 0;
        else if(u<=l&&v>=r) return value;
        else return left->get(u, v)+right->get(u, v);
    }
};
segment_tree::pointer tree[300002];
vector <int> from[300001];
#define left Kafuu
#define right Chino
int left[300001];
int right[300001];
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    tree[n+1]=new segment_tree(1, n);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n){
        first[i]=first[i-1];
        first[i]=max(first[i], last[a[i]]+1);
        from[i-first[i]+1].pb(i);
        last[a[i]]=i;
    }
    DFOR(i, n, 1){
        tree[i]=tree[i+1];
        for(auto x: from[i]) tree[i]=tree[i]->update(x);
    }
    {
        deque <int> q;
        FOR(i, 1, n){
            while((!q.empty())&&(a[i]>a[q.back()])) q.pop_back();
            if(q.empty()) left[i]=1;
            else left[i]=q.back()+1;
            q.pb(i);
        }
    }
    {
        deque <int> q;
        DFOR(i, n, 1){
            while((!q.empty())&&(a[i]>a[q.back()])) q.pop_back();
            if(q.empty()) right[i]=n;
            else right[i]=q.back()-1;
            q.pb(i);
        }
    }
    ll ans=0;
    FOR(i, 1, n){
        int low=max(i, left[i]+a[i]-1);
        int high=min(right[i], i+a[i]-1);
        if(low>high) continue;
        ans+=tree[a[i]]->get(low, high);
    }
    writeln(ans);

}