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
#define taskname "446C"
const ll base=1000000009;
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
const ll root5=383008016;
const ll inverse_root5=inverse(root5);
const ll phi=((root5+1)*inverse(2))%base;
const ll nphi=((base+1-root5)*inverse(2))%base;
class power_segment_tree{
public:
    ///a[i]=(x^i)*i;
    ll x;
    ll px[300001];
    ll ipx[300001];
    class segment_tree{
    public:
        using pointer=segment_tree*;
        pointer left, right;
        int l, r, m;
        ll a, p, atp;
        segment_tree(int l, int r, ll *px){
            this->l=l;
            this->r=r;
            m=(l+r)/2;
            a=atp=0;
            if(l==r){
                p=px[l];
            }
            else{
                left=new segment_tree(l, m, px);
                right=new segment_tree(m+1, r, px);
                p=(left->p+right->p)%base;
            }
        }
        void down(){
            left->atp=(left->atp+a*left->p)%base;
            right->atp=(right->atp+a*right->p)%base;
            left->a=(left->a+a)%base;
            right->a=(right->a+a)%base;
            a=0;
        }
        void update(int u, int v, ll x){
            if(l>v||r<u) return;
            else if(u<=l&&v>=r){
                atp=(atp+p*x)%base;
                a=(a+x)%base;
            }
            else{
                down();
                left->update(u, v, x);
                right->update(u, v, x);
                atp=left->atp+right->atp;
            }
        }
        ll get(int u, int v){
            if(l>v||r<u) return 0;
            else if(u<=l&&v>=r) return atp;
            else{
                down();
                return left->get(u, v)+right->get(u, v);
            }
        }
    };
    segment_tree::pointer tree;
    power_segment_tree(ll x, int length){
        this->x=x;
        px[0]=1;
        FOR(i, 1, length) px[i]=(px[i-1]*x)%base;
        ipx[length]=inverse(px[length]);
        DFOR(i, length, 1) ipx[i-1]=(ipx[i]*x)%base;
        tree=new segment_tree(1, length, px);
    }
    void update(int l, int r){
        tree->update(l, r, ipx[l-1]);
    }
    ll get(ll l, ll r){
        return tree->get(l, r)%base;
    }
};
int n, m;
ll a[300001];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n) a[i]=(a[i-1]+a[i])%base;
    power_segment_tree phi_tree(phi, n);
    power_segment_tree nphi_tree(nphi, n);
    {
        int o, l, r;
        FOR(i, 1, m){
            read(o);
            read(l);
            read(r);
            if(o==1){
                phi_tree.update(l, r);
                nphi_tree.update(l, r);
            }
            else{
                ll res=(phi_tree.get(l, r)-nphi_tree.get(l, r))%base;
                res=(res*inverse_root5)%base;
                writeln((res+a[r]+base*2-a[l-1])%base);
            }
        }
    }
}