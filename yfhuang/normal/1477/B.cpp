#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 2e5 + 5;
int sumv[maxn << 2];
int setv[maxn << 2];
#define lson o*2,l,mid
#define rson o*2+1,mid+1,r

string s, f;
int l[maxn], r[maxn];

void pushup(int o){
    sumv[o] = sumv[o*2] + sumv[o*2+1];
}

void pushdown(int o, int l, int r){
    if(setv[o] != -1){
        int mid = (l + r) / 2;
        setv[o*2] = setv[o];
        setv[o*2+1] = setv[o];
        sumv[o*2] = setv[o] * (mid - l + 1);
        sumv[o*2+1] = setv[o] * (r - mid);
        setv[o] = -1;
    }
}

void build(int o, int l, int r){
    setv[o] = -1;
    if(l == r){
        sumv[o] = f[l - 1] - '0';
        return;
    }
    int mid = (l + r) / 2;
    build(lson);
    build(rson);
    pushup(o);
}

void update(int o, int l, int r, int ql, int qr, int v){
    if(ql <= l && r <= qr){
        sumv[o] = (r - l + 1) * v;
        setv[o] = v;
        return;
    }
    int mid = (l + r) / 2;
    pushdown(o, l, r);
    if(ql <= mid)
        update(lson, ql, qr, v);
    if(qr > mid)
        update(rson, ql, qr, v);
    pushup(o);
}

int query(int o, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return sumv[o];
    }
    int mid = (l + r) / 2;
    pushdown(o, l, r);
    if(qr <= mid)
        return query(lson, ql, qr);
    if(ql > mid)
        return query(rson, ql, qr);
    return query(lson, ql, qr) + query(rson, ql, qr);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    int n, q;
    while(t--){
        cin >> n >> q;
        cin >> s;
        cin >> f;
        for(int i = 1;i <= q;i++){
            cin >> l[i] >> r[i];
        }
        build(1, 1, n);
        bool flag = true;
        for(int i = q;i >= 1;i--){
            int num = query(1, 1, n, l[i], r[i]);
            int len = (r[i] - l[i] + 1);
            if(num < 1.0 * len / 2){
                update(1, 1, n, l[i], r[i], 0);
            }else if(len - num < 1.0 * len / 2){
                update(1, 1, n, l[i], r[i], 1);
            }else{
                flag = false;
            } 
        }
        if(flag){
            for(int i = 1;i <= n;i++){
                if(query(1, 1, n, i, i) != s[i - 1] - '0')
                    flag = false;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}