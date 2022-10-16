#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
typedef long long ll;
typedef long double ld;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "E"
int n;
int s1, s2;
int ps1, ps2;
int x[100001];
int pos[100001];
int l[100004];
int r[100004];
int value[100004];
map <int, int> m;
int sz;
class segment_tree{
public:
    typedef segment_tree* iterator;
    int l, r, m, value, lazy;
    iterator left, right;
    segment_tree(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        value=0;
        lazy=-1;
        if(l==r) left=right=nullptr;
        else{
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
        }
    }
    void reset(){
        value=0;
        lazy=-1;
        if(l!=r){
            left->reset();
            right->reset();
        }
    }
    void down(){
        if(lazy!=-1){
            left->value=(m-l+1)*lazy;
            left->lazy=lazy;
            right->value=(r-m)*lazy;
            right->lazy=lazy;
            lazy=-1;
        }
    }
    void set(int u, int v, int x){
        if(l>v||r<u) return;
        if(l>=u&&r<=v){
            value=(x*(r-l+1));
            lazy=x;
        }
        else{
            down();
            left->set(u, v, x);
            right->set(u, v, x);
            value=left->value+right->value;
        }
    }
    bool get(int u, int v){
        if(l>v||r<u) return 0;
        if(l>=u&&r<=v) return value;
        else{
            down();
            if(left->get(u, v)) return 1;
            return right->get(u, v);
        }
    }
};
segment_tree::iterator tree;
bool check(int x){
    int nl=1, nr=1;
    FOR(i, 1, sz){
        while(value[i]-value[nl]>x) nl++;
        while((nr<sz)&&(value[nr+1]-value[i]<=x)) nr++;
        l[i]=nl;
        r[i]=nr;
    }
    tree->reset();
    tree->set(ps1, ps1, 1);
    tree->set(ps2, ps2, 1);
    if(r[pos[1]]<sz) tree->set(r[pos[1]]+1, sz, 0);
    if(l[pos[1]]>1) tree->set(1, l[pos[1]]-1, 0);
    if(tree->value==0) return 0;
    FOR(i, 2, n){
        ///move from pos[i-1] to pos[i]
        if(r[pos[i]]<sz) tree->set(r[pos[i]]+1, sz, 0);
        if(l[pos[i]]>1) tree->set(1, l[pos[i]]-1, 0);
        ///stay at pos[i-1]
        if((r[pos[i]]>=pos[i-1])&&(l[pos[i]]<=pos[i-1])) tree->set(pos[i-1], pos[i-1], 1);
        if(tree->value==0) return 0;
    }
    return 1;
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(s1);
    read(s2);
    m[s1]=m[s2]=1;
    FOR(i, 1, n){
        read(x[i]);
        m[x[i]]=1;
    }
    int d=0;
    for(pair <const int, int> &p: m){
        p.second=++d;
        value[d]=p.first;
    }
    ps1=m[s1];
    ps2=m[s2];
    FOR(i, 1, n) pos[i]=m[x[i]];
    sz=m.size();
    tree=new segment_tree(1, sz);
    int low=abs(s1-s2), high=1e9, mid, ans=1e9;
    while(low<=high){
        mid=(low+high)/2;
        if(check(mid)){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    writeln(ans);
}