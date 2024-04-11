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
#define taskname "E"
int n;
int p[200001];
int pos[200001];
class segment_tree{
public:
    using pointer=segment_tree*;
    int l, r, m;
    pointer left, right;
    int best;
    segment_tree(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        if(l!=r){
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
            if(p[left->best]>p[right->best]) best=left->best;
            else best=right->best;
        }
        else{
            best=l;
        }
    }
    int get(int u, int v){
        if(l>v||r<u) return 0;
        else if(u<=l&&v>=r) return best;
        else{
            int res1=left->get(u, v);
            int res2=right->get(u, v);
            if(p[res1]>p[res2]) return res1;
            else return res2;
        }
    }
};
segment_tree::pointer tree;
int ans=0;
void make(int l, int r){
    if(l==r) return;
    int m=tree->get(l, r);
    if(m-l<r-m){
        FFOR(i, l, m) if((pos[p[m]-p[i]]<=r)&&(pos[p[m]-p[i]]>m)) ans++;
    }
    else{
        FOR(i, m+1, r) if((pos[p[m]-p[i]]>=l)&&(pos[p[m]-p[i]]<m)) ans++;
    }
    if(l!=m) make(l, m-1);
    if(m!=r) make(m+1, r);
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    FOR(i, 1, n){
        read(p[i]);
        pos[p[i]]=i;
    }
    tree=new segment_tree(1, n);
    make(1, n);
    writeln(ans);
}