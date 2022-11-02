#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 5e5 + 5;
int n, q;
typedef long long LL;
LL minv[maxn << 2];
LL addv[maxn << 2];
const LL oo = (1LL << 60);
vector<pair<int, LL> > G[maxn];
vector<pair<int, pair<int, int> > > query[maxn];
LL d[maxn];
int en[maxn];
LL ans[maxn];
void pushdown(int o){
    minv[o * 2] += addv[o];
    minv[o * 2 + 1] += addv[o];
    addv[o * 2] += addv[o];
    addv[o * 2 + 1] += addv[o];
    addv[o] = 0;
}

void pushup(int o){
    minv[o] = min(minv[o * 2], minv[o * 2 + 1]);
}

#define lson o*2,l,mid
#define rson o*2+1,mid+1,r

void update(int o, int l, int r, int ql,int qr, LL d){
    if(l >= ql && r <= qr){
        addv[o] += d;
        minv[o] += d;
        return;
    }
    int mid = (l + r) / 2;
    pushdown(o);
    if(ql <= mid) update(lson, ql, qr, d);
    if(qr > mid) update(rson, ql, qr, d);
    pushup(o);
}

LL getmin(int o, int l,int r, int ql,int qr){
    if(ql <= l && r <= qr){
        return minv[o];
    }
    LL ret = oo;
    int mid = (l + r) / 2;
    pushdown(o);
    if(ql <= mid) ret = min(ret, getmin(lson, ql, qr));
    if(qr > mid) ret = min(ret, getmin(rson, ql, qr));
    return ret; 
}

void dfs(int x){
    en[x] = x;
    for(auto i:G[x]){
        d[i.first] = d[x] + i.second;
        dfs(i.first);
        en[x] = en[i.first];
    }
}

void solve(int x, int f){
    LL tmp = 2 * (d[f] - d[x]);
    update(1, 1, n, x, en[x], tmp);
    for(auto i: query[x]){
        int id = i.first;
        int l = i.second.first;
        int r = i.second.second;
        ans[id] = getmin(1, 1, n, l, r) + d[x];
    }
    for(auto i: G[x]) solve(i.first, x);
    update(1, 1, n, x, en[x], -tmp);
}

int main(){
    cin >> n >> q;
    for(int i = 2;i <= n;i++){
        int x, w;
        scanf("%d%d", &x, &w);
        G[x].push_back(make_pair(i, w));
    }
    for(int i = 1;i <= q;i++){
        int l, r, v;
        scanf("%d%d%d", &v, &l, &r);
        query[v].push_back(make_pair(i, make_pair(l, r)));
    }
    memset(addv, 0, sizeof(addv));
    memset(minv, 0, sizeof(minv));
    d[1] = 0;
    dfs(1);
    for(int i = 1;i <= n;i++){
        if(G[i].empty()) update(1, 1, n, i, i, d[i]);
        else update(1, 1, n, i, i, oo);
    }
    solve(1, 0);
    for(int i = 1;i <= q;i++){
        printf("%lld\n", ans[i]);
    }
    return 0;
}