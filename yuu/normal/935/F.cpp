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
#define taskname "F"
class segment_tree{
public:
    static const int SUM=0;
    static const int MIN=1;
    static const int MAX=2;
    static inline ll sum(ll a, ll b){
        return a+b;
    }
    static inline ll min(ll a, ll b){
        return (a<b)?a:b;
    }
    static inline ll max(ll a, ll b){
        return (a>b)?a:b;
    }
    typedef segment_tree* iterator;
    int l, r, m;
    ll value, lazy;
    iterator left, right;
    ll (*func)(ll, ll);
    segment_tree(ll *a, int l, int r, int type){
        if(type==SUM) func=sum;
        else if(type==MIN) func=min;
        else func=max;
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        lazy=0;
        value=(type==MIN)?1e18:0;
        left=right=nullptr;
        if(l==r) value=a[l];
        else{
            left=new segment_tree(a, l, m, type);
            right=new segment_tree(a, m+1, r, type);
            value=func(left->value, right->value);
        }
    }
    void down(){
        left->value+=lazy;
        left->lazy+=lazy;
        right->value+=lazy;
        right->lazy+=lazy;
        lazy=0;
    }
    void add(int u, int v, ll x){
        if(l>v||r<u) return;
        if(u<=l&&v>=r){
            value+=x;
            lazy+=x;
        }
        else{
            down();
            left->add(u, v, x);
            right->add(u, v, x);
            value=func(left->value, right->value);
        }
    }
    void set(int u, ll x){
        if(l==r) value=x;
        else{
            down();
            if(m>=u) left->set(u, x);
            else right->set(u, x);
            value=func(left->value, right->value);
        }
    }
    ll get(int u, int v){
        if(l>v||r<u) return (func==min)?1e18:0;
        if(u<=l&&v>=r) return value;
        down();
        return min(left->get(u, v), right->get(u, v));
    }
    ll get(int u){
        if(l==r) return value;
        down();
        if(m>=u) return left->get(u);
        else return right->get(u);
    }
};
segment_tree::iterator tree_a, tree_f, tree_s;
int n, q;
ll a[100001];
ll s[100001];
ll f[100001];
void up(int i){
    if(i>1&&i<n) tree_s->set(i, max(tree_a->get(i-1), tree_a->get(i+1))-tree_a->get(i));
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    FOR(i, 1, n) read(a[i]);
    FFOR(i, 1, n) f[i]=abs(a[i]-a[i+1]);
    FFOR(i, 2, n) s[i]=max(a[i-1], a[i+1])-a[i];
    tree_a=new segment_tree(a, 1, n, segment_tree::MIN);
    tree_f=new segment_tree(f, 1, n-1, segment_tree::SUM);
    tree_s=new segment_tree(s, 2, n-1, segment_tree::MIN);
    read(q);
{
    int t, l, r, L, R, m, p;
    ll ans, x, al, ar, temp, ta, am;
    FOR(i, 1, q){
        read(t);
        read(l);
        read(r);
        read(x);
        if(t==1){
            ans=0;
            if(l==1){
                al=tree_a->get(l, l);
                temp=tree_a->get(l+1, l+1);
                ans=max(ans, tree_f->get(1, n-1)-abs(al-temp)+abs(al+x-temp));
                l=2;
            }
            if(r==n){
                ar=tree_a->get(r, r);
                temp=tree_a->get(r-1, r-1);
                ans=max(ans, tree_f->get(1, n-1)-abs(ar-temp)+abs(ar+x-temp));
                r=n-1;
            }
            if(l>r) goto line0;
            if(l==r){
                ta=tree_f->get(1, n-1);
                al=tree_a->get(l);
                if(l>1){
                    temp=tree_a->get(l-1);
                    ta=ta-abs(al-temp)+abs(al+x-temp);
                }
                if(r<n){
                    temp=tree_a->get(r+1);
                    ta=ta-abs(al-temp)+abs(al+x-temp);
                }
                ans=max(ans, ta);
            }
            else{
                temp=tree_s->get(l, r);
                if(temp<=0) ans=tree_f->get(1, n-1)+x*2;
                else{
                    L=l;
                    R=r;
                    am=tree_a->get(l, r);
                    while(L<=R){
                        m=(L+R)/2;
                        if(tree_a->get(l, m)==am){
                            p=m;
                            R=m-1;
                        }
                        else L=m+1;
                    }
                    ta=tree_f->get(1, n-1);
                    al=tree_a->get(p);
                    temp=tree_a->get(p-1);
                    ta=ta-abs(al-temp)+abs(al+x-temp);
                    temp=tree_a->get(p+1);
                    ta=ta-abs(al-temp)+abs(al+x-temp);
                    ans=max(ans, ta);
                    if(p>l){
                        temp=tree_s->get(l, p-1);
                        ans=max(ans, tree_f->get(1, n-1)+x-abs(temp)+abs(temp-x));
                    }
                    if(p<r){
                        temp=tree_s->get(p+1, r);
                        ans=max(ans, tree_f->get(1, n-1)+x-abs(temp)+abs(temp-x));
                    }
                }
            }
            line0:;
            writeln(ans);
        }
        else{
            tree_a->add(l, r, x);
            up(l);
            up(r);
            up(l-1);
            up(r+1);
            if(l>1) tree_f->set(l-1, abs(tree_a->get(l)-tree_a->get(l-1)));
            if(r<n) tree_f->set(r, abs(tree_a->get(r)-tree_a->get(r+1)));
        }
    }
}
}