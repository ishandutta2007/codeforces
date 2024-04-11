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
using ll=long long;
using ld=long double;
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
int n, k;
int a[100001];
class segment_tree{
public:
    using pointer=segment_tree*;
    int l, r, m;
    ll value;
    pointer left, right;
    segment_tree(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        if(l==r) value=a[l];
        else{
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
            value=(left->value*right->value)%k;
        }
    }
    void update(int u){
        if(l==r) value=1;
        else{
            if(m>=u) left->update(u);
            else right->update(u);
            value=(left->value*right->value)%k;
        }
    }
    int get(ll x){
        if(l==r){
            if((value*x)%k) return l;
            else return l-1;
        }
        else{
            if((left->value*x)%k==0) return left->get(x);
            else return right->get((x*left->value)%k);
        }
    }
};
segment_tree::pointer tree;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(k);
    if(k==1){
        writeln((((ll)(n))*(n+1))/2);
        return 0;
    }
    FOR(i, 1, n) read(a[i]);
    tree=new segment_tree(1, n);
    ll ans=0;
    FOR(i, 1, n){
        ans+=n-tree->get(1);
        tree->update(i);
    }
    writeln(ans);
}