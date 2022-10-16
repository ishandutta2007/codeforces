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
#define taskname "594D"
int n, m;
int a[200001];
const ll base=1000000007;
class query{
public:
    int l, r, id;
    void input(int id){
        read(l);
        read(r);
        this->id=id;
    }
} q[200001];
ll ans[200001];
int p[1000001];
int last[1000001];
void sieve(){
    FOR(i, 2, 1000000) if(p[i]==0) for(int j=i; j<=1000000; j+=i) if(!p[j]) p[j]=i;
}
class segment_tree{
public:
    using pointer=segment_tree*;
    pointer left, right;
    int l, r, m;
    ll value;
    segment_tree(int l, int r){
        value=1;
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        if(l!=r){
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
        }
        else left=right=nullptr;
    }
    void down(){
        left->value=(left->value*value)%base;
        right->value=(right->value*value)%base;
        value=1;
    }
    void update(int u, int v, ll x){
        if(l>v||r<u) return;
        else if(u<=l&&v>=r){
            value=(value*x)%base;
        }
        else{
            down();
            left->update(u, v, x);
            right->update(u, v, x);
        }
    }
    ll get(int u){
        if(l==r) return value;
        else{
            down();
            if(m>=u) return left->get(u);
            else return right->get(u);
        }
    }
};
segment_tree::pointer tree;
ll power(ll a, ll b){
    if(b==0) return 1;
    ll t=power(a, b/2);
    t=(t*t)%base;
    if(b%2) t=(t*a)%base;
    return t;
}
ll inverse(ll x){
    return power(x, base-2);
}
bool done[1000001];
void process(){
    sieve();
    tree=new segment_tree(1, n);
    FOR(i, 1, n){
        int x=a[i];
        while(x>1){
            int y=p[x];
            int ap=1;
            while(x%y==0){
                x/=y;
                ap*=y;
            }
        }
    }
    sort(q+1, q+m+1, [](query A, query B){
        return A.l>B.l;
    });
    int j=n;
    FOR(i, 1, m){
        while(j>=q[i].l){
            int x=a[j];
            while(x>1){
                int y=p[x];
                int ap=1;
                while(x%y==0){
                    x/=y;
                    ap*=y;
                }
                if(last[y]){
                    tree->update(last[y], n, (inverse(y-1)*(y))%base);
                }
                last[y]=j;
                tree->update(j, n, (ap-ap/y)%base);
            }
            j--;
        }
        ans[q[i].id]=tree->get(q[i].r);
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n) read(a[i]);
    read(m);
    FOR(i, 1, m) q[i].input(i);
    process();
    FOR(i, 1, m) writeln(ans[i]);
}