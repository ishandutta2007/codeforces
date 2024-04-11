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
#define taskname "D"
int n;
int a[200001];
class segment_tree{
public:
    typedef segment_tree* iterator;
    int l, r, m, value;
    iterator left, right;
    segment_tree(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        value=0;
        if(l==r) left=right=nullptr;
        else{
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
        }
    }
    void reset(){
        value=0;
        if(l!=r){
            left->reset();
            right->reset();
        }
    }
    void set(int u, int x){
        if(l==r){
            value=x;
        }
        else{
            if(m>=u) left->set(u, x);
            else right->set(u, x);
            value=left->value|right->value;
        }
    }
    int get(int a){
        if(l==r){
            if((value|a)==a) return l;
            else return l-1;
        }
        else{
            if((left->value|a)!=a) return left->get(a);
            return right->get(a);
        }
    }
};
segment_tree::iterator tree;
map <int, int> m;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    tree=new segment_tree(1, n);
    FOR(i, 1, n) read(a[i]);
    ll ans=0;
    DFOR(i, n, 1){
        tree->set(i, a[i]);
        m[a[i]]=i;
        int value=a[i];
        int r;
        int s=i;
        while(true){
            r=tree->get(value);
            if(m.find(value)==m.end()) ans+=r-s;
            else ans+=max(0, min(r, m[value]-1)-s);
            if(r==n) break;
            value|=a[r+1];
            s=r;
        }
    }
    writeln(ans);

}