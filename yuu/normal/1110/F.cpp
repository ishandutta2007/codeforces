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
#define taskname "1110F"
#define left Kafuu
#define right Chino
int n, q;
vector <int> g[500001];
int w[500001];
ll d[500001];
ll f[500001];
int h[500001];
int first[500001];
int last[500001];
int base[1000001];
int cnt;
int acs[500001][20];
vector <int> leaves;
void dfs(int u){
    cnt++;
    base[cnt]=u;
    first[u]=cnt;
    f[u]=g[u].empty()?0:1e18;
    if(g[u].empty()) leaves.pb(u);
    for(int i=0; acs[acs[u][i]][i]; i++) acs[u][i+1]=acs[acs[u][i]][i];
    for(int v: g[u]){
        d[v]=d[u]+w[v];
        h[v]=h[u]+1;
        acs[v][0]=u;
        dfs(v);
        f[u]=min(f[u], f[v]+w[v]);
        cnt++;
        base[cnt]=u;
    }
    last[u]=cnt;
}
int lca(int u, int v){
    if(h[u]<h[v]) swap(u, v);
    DFOR(i, __lg(h[u]), 0) if(h[acs[u][i]]>=h[v]) u=acs[u][i];
    if(u==v) return u;
    DFOR(i, __lg(h[u]), 0) if(acs[u][i]!=acs[v][i]) u=acs[u][i];
    return acs[u][0];
}
ll ans[500001];
ll dist(int u, int v){
    return d[u]+d[v]-d[lca(u, v)]*2;
}
bool is_child(int u, int p){
    return (first[p]<=first[u])&&(last[p]>=last[u]);
}
class query{
public:
    int v, id;
    pair <int, int> p;
    query(int v, pair <int, int> p, int id){
        this->v=v;
        this->p=p;
        this->id=id;
    }
};
vector <query> left, right;
class segment_tree{
public:
    using pointer=segment_tree*;
    int l, r, m;
    ll value, lazy;
    pointer left, right;
    segment_tree(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        lazy=0;
        if(l==r){
            if(g[base[l]].empty()) value=d[base[l]];
            else value=1e18;
        }
        else{
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
            value=min(left->value, right->value);
        }
    }
    void down(){
        left->value+=lazy;
        right->value+=lazy;
        left->lazy+=lazy;
        right->lazy+=lazy;
        lazy=0;
    }
    void update(int u, int v, ll x){
        if(l>v||r<u) return;
        else if(u<=l&&v>=r){
            lazy+=x;
            value+=x;
        }
        else{
            down();
            left->update(u, v, x);
            right->update(u, v, x);
            value=min(left->value, right->value);
        }
    }
    ll get(int u, int v){
        if(l>v||r<u) return 1e18;
        else if(u<=l&&v>=r) return value;
        else{
            down();
            return min(left->get(u, v), right->get(u, v));
        }
    }
};
segment_tree::pointer tree;
void process_left(){
    sort(left.begin(), left.end(), [](query A, query B){
        return first[A.v]<first[B.v];
    });
    tree=new segment_tree(1, cnt);
    deque <int> x;
    int i=1;
    for(query q: left){
        while(i<=first[q.v]){
            while((!x.empty())&&(d[base[x.back()]]>d[base[i]])){
                int start=(x.size()>1)?(x[x.size()-2]+1):1;
                tree->update(start, x.back(), +d[base[x.back()]]*2);
                x.pop_back();
            }
            int start=(x.empty())?(1):(x.back()+1);
            tree->update(start, i, -d[base[i]]*2);
            x.pb(i);
//            bug(start);
//            bug(i);
//            bug(d[base[i]]);
            i++;
        }
        ans[q.id]=min(ans[q.id], tree->get(first[q.p.first], min(first[q.v], first[q.p.second]))+d[q.v]);
    }
}
void process_right(){
    sort(right.begin(), right.end(), [](query A, query B){
        return first[A.v]>first[B.v];
    });
    tree=new segment_tree(1, cnt);
//    FOR(i, 1, cnt) cerr<<tree->get(i, i)<<" \n"[i==cnt];
    deque <int> x;
    int i=cnt;
    for(query q: right){
        while(i>=first[q.v]){
            while((!x.empty())&&(h[base[x.back()]]>h[base[i]])){
                int finish=(x.size()>1)?(x[x.size()-2]-1):cnt;
                tree->update(x.back(), finish, +d[base[x.back()]]*2);
                x.pop_back();
            }
            int finish=(x.empty())?(cnt):(x.back()-1);
            tree->update(i, finish, -d[base[i]]*2);
            x.pb(i);
//            bug(x.size());
//            bug(finish);
//            bug(i);
//            bug(d[base[i]]);
//            FOR(i, 1, cnt) cerr<<tree->get(i, i)<<" \n"[i==cnt];
            i--;
        }
//        bug(q.id);
//        FOR(i, 1, cnt) cerr<<tree->get(i, i)<<" \n"[i==cnt];
        ans[q.id]=min(ans[q.id], tree->get(max(first[q.p.first], first[q.v]), last[q.p.second])+d[q.v]);
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(q);
    {
        int p;
        FOR(i, 2, n){
            read(p);
            read(w[i]);
            g[p].pb(i);
        }
    }
    h[1]=1;
    dfs(1);
    {
        int v, l, r;
        int a, b, root;
        FOR(i, 1, q){
            ans[i]=1e18;
            read(v);
            read(l);
            read(r);
            a=lower_bound(leaves.begin(), leaves.end(), l)-leaves.begin();
            b=lower_bound(leaves.begin(), leaves.end(), r)-leaves.begin();
            while(leaves[b]>r) b--;
            root=lca(leaves[a], leaves[b]);
//            bug(leaves[a]);
//            bug(leaves[b]);
//            bug(first[leaves[a]]);
//            bug(first[v]);
//            if((last[v]>=first[leaves[a]])&&(first[v]<=first[leaves[b]])){
                left.pb(query(v, mp(leaves[a], leaves[b]), i));
                right.pb(query(v, mp(leaves[a], leaves[b]), i));
//            }
//            else{
//                bug(i);
//                ans[i]=dist(v, root)+f[root];
//            }
        }
    }
    process_left();
//    FOR(i, 1, q) writeln(ans[i]);
    process_right();
    FOR(i, 1, q) writeln(ans[i]);
}