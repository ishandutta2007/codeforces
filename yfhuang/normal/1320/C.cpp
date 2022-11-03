#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n, m, p;

const int maxn = 2e5 + 5;
typedef long long LL;
LL maxv[maxn << 2];
LL addv[maxn << 2];
#define lson o*2,l,mid
#define rson o*2+1,mid+1,r

void pushup(int o){
    maxv[o] = max(maxv[o*2],maxv[o*2+1]);
}

void pushdown(int o){
    if(addv[o]){
        addv[o*2] += addv[o];
        addv[o*2+1] += addv[o];
        maxv[o*2] += addv[o];
        maxv[o*2+1] += addv[o];
        addv[o] = 0;
    }
}

void build(int o, int l, int r){
    maxv[o] = 0;
    addv[o] = 0;
    if(l == r)
        return;
    int mid = (l + r) / 2;
    build(lson);
    build(rson);
}

void update(int o, int l, int r, int ql, int qr, LL v){
    if(ql > qr)
        return;
    if(ql <= l && r <= qr){
        maxv[o] += v;
        addv[o] += v;
        return;
    }
    int mid = (l + r) / 2;
    pushdown(o);
    if(ql <= mid)
        update(lson, ql, qr, v);
    if(qr > mid)
        update(rson, ql, qr, v);
    pushup(o);
}

LL querymax(int o, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return maxv[o];
    }
    int mid = (l + r) / 2;
    pushdown(o);
    if(qr <= mid)
        return querymax(lson, ql, qr);
    if(ql > mid)
        return querymax(rson, ql, qr);
    return max(querymax(lson, ql, qr), querymax(rson, ql, qr));
}

typedef pair<int, int> pii;

pii a[maxn], b[maxn];

pair<int, pii> c[maxn];

int id[maxn];

int main(){
    cin >> n >> m >> p;
    for(int i = 1;i <= n;i++){
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    for(int i = 1;i <= m;i++){
        scanf("%d%d", &b[i].first, &b[i].second);
    }
    for(int i = 1;i <= p;i++){
        scanf("%d%d%d", &c[i].first, &c[i].second.first, &c[i].second.second);
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    sort(c + 1, c + 1 + p);
    int cur = 1;
    build(1, 1, m);
    for(int i = 1;i <= m;i++){
        id[i] = b[i].first;
    }
    for(int i = 1;i <= m;i++){
        update(1, 1, m, i, i, -b[i].second);
    }
    LL ans = -1e18;
    for(int i = 1;i <= n;i++){
        while(cur <= p and c[cur].first < a[i].first){
            int x = upper_bound(id + 1, id + 1 + m, c[cur].second.first) - id;
            int val = c[cur].second.second;
            if(x <= m)
                update(1, 1, m, x, m, val);
            cur++;
        }
        ans = max(ans, querymax(1, 1, m, 1, m) - a[i].second);
    }
    cout << ans << endl;
    return 0;
}