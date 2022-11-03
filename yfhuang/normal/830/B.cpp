#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 100005;
int n;
int a[maxn * 2];

int b[maxn << 3];
int sum[maxn * 2];

void add(int x,int d){
    for(int i = x;i < maxn * 2;i += i & -i){
        sum[i] += d;
    }
}

int Sum(int x){
    int ret = 0;
    for(int i = x;i > 0;i -= i & -i){
        ret += sum[i];
    }
    return ret;
}

void pushup(int o){
    if(a[b[o * 2]] <= a[b[o * 2 + 1]]){
        b[o] = b[o * 2];
    }else b[o] = b[o * 2 + 1];
}

void build(int o,int l,int r){
    if(l == r) {b[o] = l;return;}
    int mid = (l + r) / 2;
    build(o * 2,l,mid);
    build(o * 2 + 1,mid + 1,r);
    pushup(o);
}

int query(int o,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return b[o];
    int mid = (l + r) / 2;
    if(qr <= mid) return query(o * 2,l,mid,ql,qr);
    if(ql > mid) return query(o * 2 + 1,mid + 1,r,ql,qr);
    int p1 = query(o * 2,l,mid,ql,qr);
    int p2 = query(o * 2 + 1,mid + 1,r,ql,qr);
    if(a[p1] <= a[p2]) return p1;
    else return p2;
}

void update(int o,int l,int r,int p){
    if(l == r){
        a[l] = 1000000;
        return;
    }
    int mid = (l + r) / 2;
    if(p <= mid) update(o * 2,l,mid,p);
    if(p > mid) update(o * 2 + 1,mid + 1,r,p);
    pushup(o);
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",a + i);
        a[i + n] = a[i];
        add(i,1);add(i + n,1);
    }
    build(1,1,2 * n);
    int pre = 0;
    long long ans = 0;
    for(int i = 1;i <= n;i++){
        int p = query(1,1,2 * n,pre + 1,pre + n);
        //cout << p << endl;
        
        ans += Sum(p) - Sum(pre);
        int p1;
        if(p > n) p1 = p - n;
        else p1 = p + n;
        update(1,1,2 * n,p);
        update(1,1,2 * n,p1);
        add(p,-1);
        add(p1,-1);
        if(p > n) p = p - n;
        pre = p;
    }
    cout << ans << endl;
    return 0;
}