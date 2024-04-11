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
#define taskname "F"
int n;
ll a[200001];
ll sum[200001];
ll wsum[200001];
ll ans=0;
class line{
public:
    ll a, b;
    line(){a=b=0;};
    line(ll a, ll b){
        this->a=a;
        this->b=b;
    }
    void operator+=(line L){
        a+=L.a;
        b+=L.b;
    }
    line operator +(line X){
        X+=(*this);
        return X;
    }
//    ll at(ll x){
//        return a*x+b;
//    }
};
class linear_segment_tree{
public:
    using pointer=linear_segment_tree*;
    int l, r, m;
    line L;
    pointer left, right;
    linear_segment_tree(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        L=line();
        left=right=nullptr;
    }
    void update(line A, int u){
        if(l>u) return;
        bool bl=A.a*l+A.b<=L.a*l+L.b;
        bool br=A.a*r+A.b<=L.a*r+L.b;
        if(bl&&br) L=A;
        else{
            if(!bl&&!br) return;
            if(l!=r){
                if(left==nullptr){
                    left=new linear_segment_tree(l, m);
                    right=new linear_segment_tree(m+1, r);
                }
                left->update(A, u);
                right->update(A, u);
            }
        }
    }
    ll get(int u){
        ll res=L.a*u+L.b;
        if(l!=r){
            if(left!=nullptr){
                if(m>=u) res=min(res, left->get(u));
                else res=min(res, right->get(u));
            }
        }
        return res;
    }
};
linear_segment_tree::pointer tree;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n) sum[i]=sum[i-1]+a[i];
    FOR(i, 1, n) wsum[i]=wsum[i-1]+a[i]*i;
    tree=new linear_segment_tree(1, n);
    line now(0, 0);
    DFOR(i, n, 1){
        ///start from i
        ans=max(ans, (wsum[n]-wsum[i-1])-(sum[n]-sum[i-1])*(i-1)-tree->get(i));
        now+=line(-a[i], a[i]*(i+1));
        tree->update(now, i);
    }
    writeln(ans);

}