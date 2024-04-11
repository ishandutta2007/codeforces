/*program by mangoyang*/
#include <bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
    int ch = 0, f = 0; x = 0;
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    if(f) x = -x;
}
const int N = 400005;
char s[N]; int n, ans;
namespace Seg{
    #define mid ((l + r) >> 1)
    int lc[N*19], rc[N*19], sz[N*19], size;
    inline void ins(int &u, int l, int r, int pos){
        if(!u) u = ++size;
        if(l == r) return (void) (sz[u]++);
        if(pos <= mid) ins(lc[u], l, mid, pos);
        else ins(rc[u], mid + 1, r, pos); 
        sz[u] = sz[lc[u]] + sz[rc[u]];
    }
    inline int merge(int x, int y, int l, int r){
        if(!x || !y) return x + y;
        int o = ++size;
        if(l == r) sz[o] = sz[x] + sz[y];
        else{
            lc[o] = merge(lc[x], lc[y], l, mid);
            rc[o] = merge(rc[x], rc[y], mid + 1, r);
            sz[o] = sz[lc[o]] + sz[rc[o]];
        }
        return o;
    }
    inline int query(int u, int l, int r, int L, int R){
        if(l >= L && r <= R) return sz[u];
        int res = 0;
        if(L <= mid) res += query(lc[u], l, mid, L, R);
        if(mid < R) res += query(rc[u], mid + 1, r, L, R);
        return res;
    }
    #undef mid
}
namespace SAM{
    vector<int> g[N];
    int ch[N][26], id[N], len[N], fa[N], dp[N], rt[N], pos[N], tail = 1, size = 1;
    inline int newnode(int x){ return len[++size] = x, size; }
    inline void ins(int c, int x){
        int p = tail, np = newnode(len[p] + 1); pos[np] = x;
        Seg::ins(rt[np], 1, n, pos[np]);
        for(; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
        if(!p) return (void) (fa[np] = 1, tail = np);
        int q = ch[p][c];
        if(len[q] == len[p] + 1) fa[np] = q;
        else{
            int nq = newnode(len[p] + 1); pos[nq] = x;
            fa[nq] = fa[q], fa[q] = fa[np] = nq;
            for(int i = 0; i < 26; i++) ch[nq][i] = ch[q][i];
            for(; p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
        }tail = np;
    }
    inline void addedge(){
        for(int i = 2; i <= size; i++) g[fa[i]].push_back(i);
    }
    inline void dfs(int u){
        for(int i = 0; i < (int) g[u].size(); i++)
            dfs(g[u][i]), rt[u] = Seg::merge(rt[u], rt[g[u][i]], 1, n);
    }
    inline void dfs2(int u){
        if(u > 1){
            if(fa[u] == 1) id[u] = u, dp[u] = 1;
            else{
                int tmp = Seg::query(rt[id[fa[u]]], 1, n, pos[u] - len[u] + len[id[fa[u]]], pos[u] - 1);
                if(tmp) dp[u] = dp[fa[u]] + 1, id[u] = u; else dp[u] = dp[fa[u]], id[u] = id[fa[u]];            
            }
        }
        ans = max(ans, dp[u]);
        for(int i = 0; i < (int) g[u].size(); i++) dfs2(g[u][i]);
    }
}
int main(){
    read(n), scanf("%s", s + 1);
    for(int i = 1; i <= n; i++)
        SAM::ins(s[i] - 'a', i);
    SAM::addedge(), SAM::dfs(1), SAM::dfs2(1);
    cout << ans << endl;
    return 0;
}