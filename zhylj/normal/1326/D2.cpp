#include <bits/stdc++.h>

typedef long long ll;

const int kN = 1e6 + 5;
const ll kMod = 998244353;

char s[kN]; int n; ll kB;

int main() {
    srand(time(0));
    int T; scanf("%d", &T);
    kB = rand() % 23333 + 5;
    while(T--) {
        scanf("%s", s + 1); n = strlen(s + 1);
        int x = 0;
        for(int i = 1; i <= n / 2; ++i) {
            if(s[i] == s[n - i + 1]) x = i;
            else break;
        }
        if(x == n - x) {
            printf("%s\n", s + 1);
            continue;
        }
        int l, r;
        ll hs_p1 = 0, hs_p2 = 0, tmp = 1;
        for(int i = x + 1; i <= n - x; ++i) {
            hs_p1 = (hs_p1 * kB % kMod + s[i] - 'a') % kMod;
            hs_p2 = (hs_p2 + (s[i] - 'a') * tmp % kMod) % kMod;
            tmp = tmp * kB % kMod;
            if(hs_p1 == hs_p2) l = i;
        }
        hs_p1 = 0, hs_p2 = 0, tmp = 1;
        for(int i = n - x; i > x; --i) {
            hs_p1 = (hs_p1 * kB % kMod + s[i] - 'a') % kMod;
            hs_p2 = (hs_p2 + (s[i] - 'a') * tmp % kMod) % kMod;
            tmp = tmp * kB % kMod;
            if(hs_p1 == hs_p2) r = i;
        }
        if(l > (n - r + 1)) {
            for(int i = 1; i <= l; ++i) printf("%c", s[i]);
            for(int i = n - x + 1; i <= n; ++i) printf("%c", s[i]);
        } else {
            for(int i = 1; i <= x; ++i) printf("%c", s[i]);
            for(int i = r; i <= n; ++i) printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}