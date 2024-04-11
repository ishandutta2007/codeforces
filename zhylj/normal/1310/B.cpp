#include <bits/stdc++.h>

typedef std::pair<int, int> pii;

const int kN = 18;
const int kT = 1 << kN;
const int kInf = 0x3f3f3f3f;

int a[kT]; bool fan_of[kT]; std::map<pii, int> cal[4];
int Cal(int l, int r, int st) {
    if(r == l + 2) {
       // printf("%d %d %d %d\n", st, (fan_of[l] || fan_of[l + 1]), l, r);
        int cnt_fan = (int)fan_of[l] + fan_of[l + 1], cnt_st = (st & 1) + (st >> 1);
        return cnt_fan == cnt_st ? std::min(cnt_st, 1) : -kInf;
    }
    pii tmp = std::make_pair(l, r);
    if(cal[st].count(tmp)) return cal[st][tmp];
    int mid = (l + r) >> 1, ret = -kInf;
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j) {
            int v1 = ((i << 1) | (i & 2) | j) & 3, v2 = ((j << 1) | (j & 2) | i) & 3;
            if(v1 == st || v2 == st) {
               // printf("Cal: %d %d %d %d, %d %d %d %d\n", l, mid, i, Cal(l, mid, i), mid, r, j, Cal(mid, r, j));
                ret = std::max(ret, Cal(l, mid, i) + Cal(mid, r, j));
            }
        }
    //printf("%d %d %d %d\n", l, r, st, ret + st);
    return cal[st][tmp] = ret + st;
}

int main() {
    int n, k, t, ans = 0;
    scanf("%d%d", &n, &k); t = 1 << n;
    for(int i = 1; i <= k; ++i) scanf("%d", a + i), fan_of[--a[i]] = true;
    //ans = Cal(0, t, 2) + 2;
    for(int i = 0; i < 4; ++i) ans = std::max(ans, Cal(0, t, i));
    printf("%d", ans + !(!k));
    return 0;
}