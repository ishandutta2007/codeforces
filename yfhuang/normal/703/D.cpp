//
//  main.cpp
//  D
//
//  Created by  on 8/6/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 1e6 + 5;

int a[maxn];
int n;

typedef long long ll;

ll Xor[maxn];
int cnt[maxn];

ll xorv[maxn << 2];

void update(int o,int l,int r,int p,int v){
    if(l == r)xorv[o] = (ll)v;
    else{
        int mid = (l + r) / 2;
        if(p <= mid) update(o * 2, l, mid, p, v);
        else update(o * 2 + 1, mid + 1, r, p, v);
        xorv[o] = xorv[o * 2] ^ xorv[o * 2 + 1];
    }
}

ll query(int o,int l,int r,int ql,int qr){
    ll ans = 0;
    int m = (l + r) / 2;
    if(ql <= l && r <= qr) return xorv[o];
    if(ql <= m) ans = ans ^ query(o * 2,l,m,ql,qr);
    if(qr > m) ans = ans ^ query(o * 2 + 1,m + 1,r,ql,qr);
    return ans;
}

map<int,int> Last;

struct q{
    int l,r;
    int id;
    bool operator < (const q & rhs) const{
        return r < rhs.r || (r == rhs.r && l < rhs.l);
    }
}Q[maxn];

int m;

ll ans[maxn];

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 1;i <= n;i++) scanf("%d",a + i);
    Xor[0] = 0;
    for(int i = 1;i <= n;i++){
        Xor[i] = Xor[i - 1] ^ (ll)a[i];
    }
    cin >> m;
    for(int i = 1;i <= m;i++){
        scanf("%d%d",&Q[i].l,&Q[i].r);
        Q[i].id = i;
    }
    sort(Q + 1,Q + 1 + m);
    int front = 1;
    memset(cnt,0,sizeof(cnt));
    memset(xorv,0,sizeof(xorv));
    Last.clear();
    //cout << Last[0];
    for(int i = 1;i <= n;i++){
        cnt[Last[a[i]]] = 0;
        if(Last[a[i]] > 0) update(1, 1, n, Last[a[i]], 0);
        cnt[i] = a[i];
        update(1, 1, n, i, a[i]);
        Last[a[i]] = i;
        while(front <= m && i == Q[front].r){
            ans[Q[front].id] = query(1,1,n,Q[front].l,Q[front].r) ^ (Xor[Q[front].r] ^ Xor[Q[front].l - 1]);
            front++;
        }
    }
    for(int i = 1;i <= m;i++){
        printf("%I64d\n",ans[i]);
    }
    return 0;
}