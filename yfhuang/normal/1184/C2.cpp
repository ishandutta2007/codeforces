#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int n;
int r;

const int maxn = 4e6 + 5;

struct point{
    int x, y;
    point(int _x=0, int _y=0): x(_x), y(_y){}
    bool operator < (const point & rhs) const{
        return x < rhs.x;
    }
}p[maxn];

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
    cin >> n >> r;
    r *= 2;
    for(int i = 1;i <= n;i++){
        int x, y;
        scanf("%d%d", &x, &y);
        p[i].x = x - y;
        p[i].y = x + y;
        p[i].y += 2e6 + 1;
    }
    sort(p + 1, p + 1 + n);
    int L = 1, R = 4e6 + 1;
    build(1, L, R);
    int l = 1;
    int ans = 0;
    for(int i = 1;i <= n;i++){
        int ql = p[i].y;
        int qr = min(R, p[i].y + r);
        update(1, L, R, ql, qr, 1);
        while(p[l].x < p[i].x - r){
            ql = p[l].y;
            qr = min(R, p[l].y + r);
            update(1, L, R, ql, qr, -1);
            l++;
        }
        //cout << l << " " << i << endl;
        ans = max(ans, querymax(1, L, R, L, R));
    }
    cout << ans << endl;
    return 0;
}