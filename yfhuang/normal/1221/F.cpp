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

typedef long long LL;

const int maxn = 1e6 + 5;
LL maxv[maxn << 2];
LL addv[maxn << 2];
int maxid[maxn << 2];
#define lson o*2,l,mid
#define rson o*2+1,mid+1,r
 
void pushup(int o){
    maxv[o] = max(maxv[o*2],maxv[o*2+1]);
    if(maxv[o*2] > maxv[o*2+1]){
        maxid[o] = maxid[o*2];
    }else{
        maxid[o] = maxid[o*2+1];
    }
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
    if(l == r){
        maxid[o] = l;
        return;
    }
    int mid = (l + r) / 2;
    build(lson);
    build(rson);
    pushup(o);
}
 
void update(int o, int l, int r, int ql, int qr, LL v){
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
 
pair<LL, int>  querymax(int o, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return make_pair(maxv[o], maxid[o]);
    }
    int mid = (l + r) / 2;
    pushdown(o);
    if(qr <= mid)
        return querymax(lson, ql, qr);
    if(ql > mid)
        return querymax(rson, ql, qr);
    return max(querymax(lson, ql, qr), querymax(rson, ql, qr));
}

int n;
LL x[maxn], y[maxn], c[maxn];

int xx[maxn];
int tot1;

vector<int> ID[maxn];

int main(){
    cin >> n;
    tot1 = 0;
    for(int i = 1;i <= n;i++){
        scanf("%lld%lld%lld", &x[i], &y[i], &c[i]);
        if(x[i] > y[i]){
            swap(x[i], y[i]);
        }
        xx[++tot1] = x[i];
        xx[++tot1] = y[i];
    }
    xx[++tot1] = 1e9 + 1;
    sort(xx + 1, xx + 1 + tot1);
    tot1 = unique(xx + 1, xx + 1 + tot1) - xx - 1;
    for(int i = 1;i <= n;i++){
        x[i] = lower_bound(xx + 1, xx + 1 + tot1, x[i]) - xx;
        y[i] = lower_bound(xx + 1, xx + 1 + tot1, y[i]) - xx;
        ID[x[i]].push_back(i);
    }
    build(1, 1, tot1);
    for(int i = 1;i <= n;i++){
        update(1, 1, tot1, y[i], tot1, c[i]); 
    }
    for(int i = 1;i <= tot1;i++){
        update(1, 1, tot1, i, i, -xx[i]); 
    }
    LL ans = -1;
    LL l = 0, r = 0;
    for(int i = 1;i <= tot1;i++){
        pair<LL, int> ret = querymax(1, 1, tot1, i, tot1);
        if(ret.first + xx[i] > ans){
            ans = ret.first + xx[i];
            l = xx[i], r = xx[ret.second];
        }
        for(auto id : ID[i]){
            update(1, 1, tot1, y[id], tot1, -c[id]);
        }
    }
    cout << ans << endl;
    cout << l << " " << l << " " << r << " " << r << endl;
    return 0;
}