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
#define taskname "B2"
int n;
vector <int> g[100001];
int root;
int done[100001];
queue <int> q;
void bfs(){
    q.push(1);
    done[1]=1;
    int u;
    while(!q.empty()){
        u=q.front();
        root=u;
        q.pop();
        for(int v: g[u]) if(!done[v]){
            q.push(v);
            done[v]=1;
        }
    }
}
int p[100001];
int first[100001];
int vertex[100001];
int last[100001];
int h[100001];
int cnt;
void dfs(int u){
    done[u]=1;
    cnt++;
    first[u]=cnt;
    vertex[cnt]=u;
    FFOR(i, 0, g[u].size()) if(done[g[u][i]]){
        p[u]=g[u][i];
        swap(g[u][i], g[u].back());
        g[u].pop_back();
    }
    for(int v: g[u]){
        h[v]=h[u]+1;
        dfs(v);
    }
    last[u]=cnt;
}
int ans[100001];
bool chosen[100001];
class segment_tree{
public:
    typedef segment_tree* iterator;
    int key, value, lazy;
    int l, r, m;
    iterator left, right;
    void up(){
        if((left->value)>(right->value)){
            value=left->value;
            key=left->key;
        }
        else{
            value=right->value;
            key=right->key;
        }
    }
    void down(){
        left->value+=lazy;
        left->lazy+=lazy;
        right->value+=lazy;
        right->lazy+=lazy;
        lazy=0;
    }
    segment_tree(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        lazy=0;
        if(l==r){
            key=vertex[l];
            value=h[key];
        }
        else{
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
            up();
        }
    }
    void update(int u, int v, int x){
        if(l>v||r<u) return;
        if(u<=l&&v>=r){
            lazy+=x;
            value+=x;
        }
        else{
            down();
            left->update(u, v, x);
            right->update(u, v, x);
            up();
        }
    }
};
segment_tree::iterator tree;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    {
        int u, v;
        FFOR(i, 1, n){
            read(u);
            read(v);
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    bfs();
    ans[1]=1;
    FOR(i, 1, n) done[i]=0;
    dfs(root);
    tree=new segment_tree(1, n);
    chosen[root]=1;
    FOR(i, 2, n){
        if(ans[i-1]==n){
            ans[i]=n;
            continue;
        }
        ans[i]=ans[i-1]+tree->value;
        int u=tree->key;
        while(!chosen[u]){
            chosen[u]=1;
            tree->update(first[u], last[u], -1);
            u=p[u];
        }
    }
    FOR(i, 1, n){
        write(ans[i]);
        putchar(" \n"[i==n]);
    }
}