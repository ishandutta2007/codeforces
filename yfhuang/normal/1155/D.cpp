#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 3e5 + 5;

#define lson o*2,l,mid
#define rson o*2+1,mid+1,r

typedef long long LL;

LL n, x;
LL a[maxn];
LL pre[maxn], suf[maxn];
LL sum[maxn];
LL maxv[maxn << 2], addv[maxn << 2];
void pushup(int o){
    maxv[o] = max(maxv[o*2], maxv[o*2 + 1]);
}

void pushdown(int o){
    if(addv[o]){
        maxv[o*2] += addv[o];
        addv[o*2] += addv[o];
        maxv[o*2+1] += addv[o];
        addv[o*2+1] += addv[o];
        addv[o] = 0;
    }
}

void build(int o, int l, int r){
    maxv[o] = 0;
    addv[o] = 0;
    if(l == r){
        return;
    }
    int mid = (l + r)/2;
    build(lson);
    build(rson);
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

LL query(int o,int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return maxv[o];
    }
    LL ret = -1e18;
    int mid = (l + r) / 2;
    pushdown(o);
    if(ql <= mid)
        ret = max(ret, query(lson, ql, qr));
    if(qr > mid)
        ret = max(ret, query(rson, ql, qr));
    return ret;
}

int main(){
    while(cin >> n >> x){
        for(int i = 1;i <= n;i++){
            scanf("%lld", &a[i]);
        }
        pre[0] = 0;
        sum[0] = 0;
        for(int i = 1;i <= n;i++){
            pre[i] = max(0LL, a[i] + pre[i - 1]);
            sum[i] = sum[i - 1] + a[i];
        }
        suf[n + 1] = 0;
        for(int i = n;i >= 1;i--){
            suf[i] = max(0LL, a[i] + suf[i + 1]);
        }
        LL ans = pre[n];
        build(1, 1, n);
        for(int i = n;i >= 1;i--){
            update(1, 1, n, i, i, suf[i + 1]);
            update(1, 1, n, i, n, 1LL * x * a[i]);
            ans = max(ans, pre[i - 1] + query(1, 1, n, i, n));
        }
        cout << ans << endl;
    }
    return 0;
}