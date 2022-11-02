#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
const int maxn = 2e5 + 5;

int a[maxn];

const int oo = 2e9 + 7;

struct node{
    int best;
    int min_digit[9];
    node(){
        best = oo;
        for(int i = 0;i < 9;i++){
            min_digit[i] = oo;
        }
    }
    int& operator [](int x){
        return min_digit[x];
    }
};

void upd(node &t, int val){
    int x = val;
    for(int i = 0; i < 9;i++){
        if(x % 10 != 0)
            t[i] = min(t[i], val);
        x /= 10;
    }
}

node minv[maxn << 2];

#define lson o*2,l,mid
#define rson o*2+1,mid+1,r

node pushup(node &a, node & b){
    node c;
    c.best = min(a.best, b.best);
    for(int i = 0;i < 9;i++){
        c[i] = min(a[i], b[i]);
        if(a[i] != oo and b[i] != oo){
            c.best = min(c.best, a[i] + b[i]);
        }
    } 
    return c;
}

void update(int o, int l, int r, int p, int v){
    if(l == r){
        minv[o] = node();
        upd(minv[o], v);
        return;
    }
    int mid = (l + r) / 2;
    if(p <= mid)
        update(lson, p, v);
    else
        update(rson, p, v);
    minv[o] = pushup(minv[o*2], minv[o*2+1]);
}

node query(int o, int l, int r, int ql, int qr){
    if(ql <= l and r <= qr){
        return minv[o];
    }
    int mid = (l + r) / 2;
    if(qr <= mid)
        return query(lson, ql, qr);
    if(ql > mid)
        return query(rson, ql, qr);
    node v1 = query(lson, ql, qr);
    node v2 = query(rson, ql, qr);
    return pushup(v1, v2);
}

void build(int o, int l, int r){
    if(l == r){
        minv[o] = node();
        upd(minv[o], a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(lson);
    build(rson);
    minv[o] = pushup(minv[o*2], minv[o*2+1]);
}

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    for(int i = 1;i <= m;i++){
        int type, l, r;
        scanf("%d%d%d", &type, &l, &r);
        if(type == 1){
            update(1, 1, n, l, r);
        }else{
            node ret = query(1, 1, n, l, r);
            if(ret.best == oo){
                puts("-1");
            }else{
                printf("%d\n", ret.best);
            }
        }
    }
    return 0;
}