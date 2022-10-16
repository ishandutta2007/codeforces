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
ll ans[300001];
const ll inf=mask(62);
int deleted_at[300001];
ll a[300001];
map <ll, int> M;
class query{
public:
    int t, id;
    vector <ll> data;
    void input(int id){
        this->id=id;
        read(t);
        data.resize(1+(t==1));
        for(ll &x: data) read(x);
        if(t==1) deleted_at[id]=n+1;
        else if(t==2) deleted_at[data[0]]=id;
        else if(t==3){
            ans[id]=-inf;
            M[data[0]]=0;
        }
    }
} q[300001];
class line{
public:
    ll a, b;
    line(ll a, ll b){
        this->a=a;
        this->b=b;
    }
    line(){
        a=0;
        b=-inf;
    }
    ll at(ll x){
        return a*x+b;
    }
};
class linear_segment_tree{
public:
    using pointer=linear_segment_tree*;
    line L;
    int l, r, m;
    pointer left, right;
    linear_segment_tree(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        L=line();
        left=right=nullptr;
    }
    void update(line A){
        bool gl=A.at(a[l])>=L.at(a[l]);
        bool gr=A.at(a[r])>=L.at(a[r]);
        if(gl&&gr){
            L=A;
            return;
        }
        else if(l!=r){
            if(!gl&&!gr) return;
            if(left==nullptr){
                left=new linear_segment_tree(l, m);
                right=new linear_segment_tree(m+1, r);
            }
            left->update(A);
            right->update(A);
        }
    }
    ll get(int u){
        ll res=L.at(a[u]);
        if(l!=r){
            if(left!=nullptr){
                if(m>=u) res=max(res, left->get(u));
                else res=max(res, right->get(u));
            }
        }
        return res;
    }
};
class segment_tree{
public:
    using pointer=segment_tree*;
    linear_segment_tree::pointer tree;
    int l, r, m;
    pointer left, right;
    segment_tree(int l, int r){
        tree=new linear_segment_tree(1, M.size());
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        if(l!=r){
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
        }
        else left=right=nullptr;
    }
    void update(line L, int u, int v){
        if(l>v||r<u) return;
        if(u<=l&&v>=r) tree->update(L);
        else{
            left->update(L, u, v);
            right->update(L, u, v);
        }
    }
    ll get(int u, int i){
        if(l==r) return tree->get(i);
        else if(m>=u) return max(tree->get(i), left->get(u, i));
        else return max(tree->get(i), right->get(u, i));
    }
};
segment_tree::pointer tree;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n) q[i].input(i);
    {
        int cnt=0;
        for(auto &t: M){
            cnt++;
            t.second=cnt;
            a[cnt]=t.first;
        }
    }
    tree=new segment_tree(1, n);
    FOR(i, 1, n){
        if(q[i].t==1){
            tree->update(line(q[i].data[0], q[i].data[1]), i, deleted_at[i]-1);
        }
    }
    FOR(i, 1, n) if(q[i].t==3){
        ll res=tree->get(i, M[q[i].data[0]]);
        if(res==-inf) puts("EMPTY SET");
        else writeln(res);
    }
}