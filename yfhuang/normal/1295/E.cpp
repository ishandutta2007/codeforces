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

const int maxn = 2e5 + 5;

int n;
int a[maxn];
typedef long long LL;

int p[maxn];
int pos[maxn];

LL maxv[maxn << 2];
LL addv[maxn << 2];
#define lson o*2,l,mid
#define rson o*2+1,mid+1,r

void pushdown(int o){
    if(addv[o]){
        addv[o*2] += addv[o];
        addv[o*2+1] += addv[o];
        maxv[o*2] += addv[o];
        maxv[o*2+1] += addv[o];
        addv[o] = 0;
    }
}

void pushup(int o){
    maxv[o] = min(maxv[o*2], maxv[o*2+1]);
}

void update(int o,int l, int r, int ql, int qr, LL v){
    if(ql <= l and r <= qr){
        addv[o] += v;
        maxv[o] += v;
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


int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &p[i]);
        pos[p[i]] = i;
    }
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        if(i < n)
            update(1, 1, n - 1, i, n - 1, a[i]);
    }
    LL ans = maxv[1];
    for(int i = 1;i <= n;i++){
        int p = pos[i];
        if(p < n)
           update(1, 1, n - 1, p, n - 1, -a[p]); 
        if(p > 1)
            update(1, 1, n - 1, 1, p - 1, a[p]); 
        ans = min(ans, maxv[1]);
    }
    cout << ans << endl;
    return 0;
}