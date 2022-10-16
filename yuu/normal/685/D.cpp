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
#define taskname "685D"
int n, k;
class point{
public:
    ll x, y;
    void input(){
        read(x);
        read(y);
    }
};
vector <point> p;
ll ans[100001];
vector <ll> v;
class event{///key change
public:
    int x, y, c;
    event(int x, int y, int c){
        this->x=x;
        this->y=y;
        this->c=c;
    }
};
vector <event> e;
class segment{
public:
    ll l, r;
    segment(ll l, ll r){
        this->l=l;
        this->r=r;
    }
};
vector <segment> s;
class segment_tree{
public:
    using pointer=segment_tree*;
    int l, r, m;
    int key;
    int value;
    ll weight;
    pointer left, right;
    segment_tree(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        key=0;
        value=0;
        if(l!=r){
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
        }
        else{
            weight=s[l].r-s[l].l+1;
//            cerr<<l<<' '<<s[l].l<<' '<<s[l].r<<' '<<weight<<'\n';
        }
    }
    void update(ll u, ll v, int x){
        if(l>v||r<u) return;
        if(l==r){
            ans[key]+=weight*value;
            key+=x;
            value=0;
        }
        else{
            left->value+=value;
            right->value+=value;
            value=0;
            left->update(u, v, x);
            right->update(u, v, x);
        }
    }
};
segment_tree::pointer tree;
map <ll, int> m;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(k);
    p.resize(n);
    for(auto &a: p) a.input();
    for(auto &a: p) v.pb(a.y);
    for(auto &a: p) v.pb(a.y-k+1);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    FFOR(i, 0, v.size()){
        m[v[i]]=s.size();
        s.pb(segment(v[i], v[i]));
        if((i+1<v.size())&&(v[i+1]-v[i]>1)) s.pb(segment(v[i]+1, v[i+1]-1));
    }
    tree=new segment_tree(0, s.size()-1);
    for(auto &a: p) e.pb(event(a.x, a.y, 1));
    for(auto &a: p) e.pb(event(a.x+k, a.y, -1));
    sort(e.begin(), e.end(), [](event A, event B){
        return A.x<B.x;
    });
    int oldx=e[0].x;
    for(auto &a: e){
        tree->value+=a.x-oldx;
        oldx=a.x;
        tree->update(m[a.y-k+1], m[a.y], a.c);
    }
    FOR(i, 1, n){
        write(ans[i]);
        putchar(" \n"[i==n]);
    }
}