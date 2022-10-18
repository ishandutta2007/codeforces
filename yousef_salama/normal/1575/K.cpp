#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long modpow(long long x, long long p){
    if(p == 0)return 1;
    if(p % 2 == 1)return x * modpow(x, p - 1) % MOD;

    long long r = modpow(x, p / 2);
    return r * r % MOD;
}

int main(){
    int n, m, k, r, c;
    scanf("%d %d %d %d %d", &n, &m, &k, &r, &c);

    int ax, ay, bx, by;
    scanf("%d %d %d %d", &ax, &ay, &bx, &by);

    if(ax == bx && ay == by){
        printf("%lld\n", modpow(k, 1LL * n * m));
        return 0;
    }

    long long total = 1LL * n * m;
    
    long long cnt_union = 2LL * r * c;
    
    int cx_1 = max(ax, bx);
    int cx_2 = min(ax + r - 1, bx + r - 1);
    int cy_1 = max(ay, by);
    int cy_2 = min(ay + c - 1, by + c - 1);

    if(cx_1 <= cx_2 && cy_1 <= cy_2){
        long long cnt_intersection = 1LL * (cx_2 - cx_1) * (cy_2 - cy_1);
        cnt_union = cnt_union - cnt_intersection;
    }
    total = total - cnt_union;

    int dx = bx - ax, dy = by - ay;

    long long lx = max(ax, ax + dx);
    long long rx = min(ax + r - 1, ax + r - 1 + dx);
    long long ly = max(ay, ay + dy);
    long long ry = min(ay + c - 1, ay + c - 1 + dy);

    long long add = 1LL * r * c;
    if(lx <= rx && ly <= ry){
        long long z = (rx - lx) * (ry - ly);
        add = add - z;
    }
    total = total + add;

    printf("%lld\n", modpow(k, total));

    return 0;
}