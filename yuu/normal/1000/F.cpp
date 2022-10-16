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
int n, m;
int a[500001];
class query{
public:
    int l, r;
    int id;
    void input(int id){
        this->id=id;
        read(l);
        read(r);
    }
};
vector <query> q;
class segment_tree{
public:
    using pointer=segment_tree*;
    int l, r, m;
    pointer left, right;
    int value, pos;
    segment_tree(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        value=n+1;
        pos=l;
        if(l!=r){
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
        }
        else left=right=nullptr;
    }
    void update(int u, int x){
        if(l!=r){
            if(m>=u) left->update(u, x);
            else right->update(u, x);
            value=min(left->value, right->value);
            if(value==left->value) pos=left->pos;
            else pos=right->pos;
        }
        else value=x;
    }
    pair <int, int> get(int u, int v){
        if((l>v)||(r<u)) return mp(n+1, 0);
        if((u<=l)&&(v>=r)) return mp(value, pos);
        else{
            return min(left->get(u, v), right->get(u, v));
        }
    }
};
segment_tree::pointer tree;
#define left Niku
int last[500001];
int left[500001];
int ans[500001];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n) read(a[i]);
    read(m);
    q.resize(m);
    FFOR(i, 0, m) q[i].input(i);
    sort(q.begin(), q.end(), [](query A, query B){
        return A.r<B.r;
    });
    tree=new segment_tree(1, n);
    int r=0;
    FOR(i, 1, n){
        left[i]=last[a[i]];
        last[a[i]]=i;
    }
    for(auto t: q){
        while((r+1)<=t.r){
            r++;
            if(left[r]) tree->update(left[r], n+1);
            tree->update(r, left[r]);
        }
        pair <int, int> res=tree->get(t.l, t.r);
        if(res.first>=t.l) ans[t.id]=0;
        else ans[t.id]=a[res.second];
    }
    FFOR(i, 0, m) writeln(ans[i]);
}