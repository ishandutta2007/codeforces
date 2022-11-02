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
#include <random>
#include <chrono>
using namespace std;

const int maxn = 3e5 + 5;
const int INF = 1e9 + 7;
int n;
int p[maxn], q[maxn], pos[maxn];
int ans[maxn];

int maxv[maxn << 2];
int addv[maxn << 2];
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

void update(int o, int l, int r, int ql, int qr, int v){
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

int querymax(int o, int l, int r, int ql, int qr){
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

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &p[i]);
        pos[p[i]] = i;
    }
    for(int i = 1;i <= n;i++){
        scanf("%d", &q[i]);
    }
    build(1, 1, n);
    update(1, 1, n, 1, pos[n], 1);
    int mx = n;
    for(int i = 1;i <= n;i++){
        printf("%d%c", mx, i == n ? '\n' : ' ');
        update(1, 1, n, 1, q[i], -1);
        while(i < n and maxv[1] <= 0){
            mx--;
            update(1, 1, n, 1, pos[mx], 1);
        }
    }
    return 0;
}