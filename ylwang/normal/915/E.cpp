#include<cstdio>
#include<cstring>
#define Rint register int
using namespace std;
const int N = 15001000;
int n, q, root, seg[N], lazy[N], li[N], ri[N], cnt;
inline void pushup(int x){seg[x] = seg[li[x]] + seg[ri[x]];}
inline void pushdown(int x, int L, int R){
    if(~lazy[x]){
        int mid = L + R >> 1;
        if(!li[x]) li[x] = ++ cnt;
        seg[li[x]] = lazy[x] * (mid - L + 1); lazy[li[x]] = lazy[x];
        if(!ri[x]) ri[x] = ++ cnt;
        seg[ri[x]] = lazy[x] * (R - mid); lazy[ri[x]] = lazy[x];
        lazy[x] = -1;
    }
}
inline void change(int &x, int L, int R, int l, int r, int v){
    if(!x) x = ++ cnt;
    if(l <= L && R <= r){
        seg[x] = (R - L + 1) * v;
        lazy[x] = v;
        return;
    }
    pushdown(x, L, R);
    int mid = L + R >> 1;
    if(l <= mid) change(li[x], L, mid, l, r, v);
    if(mid < r) change(ri[x], mid + 1, R, l, r, v);
    pushup(x);
}
int main(){
    scanf("%d%d", &n, &q);
    memset(lazy, -1, sizeof lazy);
    change(root, 1, n, 1, n, 0);
    while(q --){
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        change(root, 1, n, l, r, 2 - k);
        printf("%d\n", n - seg[1]);
    }
}