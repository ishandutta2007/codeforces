#include <bits/stdc++.h>

const int kN = 2e4 + 5;
const int kInf = 0x3f3f3f3f;

int Abs(int x) { return x > 0 ? x : -x; }

std::vector<int> fac[kN];
void GetFac(int x) {
    for(int i = 1; i * i <= x; ++i)
        if(x % i == 0) {
            fac[x].push_back(i);
            if(i * i != x) fac[x].push_back(x / i);
        }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= 2e4; ++i) GetFac(i);
    while(T--) {
        int a, b, c, min_cost = kInf, fa, fb, fc;
        scanf("%d%d%d", &a, &b, &c);
        for(int i = 1; i <= 2e4; ++i) {
            for(int j : fac[i]) {
                int k = (c / i) * i;
                k = Abs(c - k) < Abs(k + i - c) ? k : k + i;
                int cur_cost = Abs(a - j) + Abs(b - i) + Abs(c - k);
                if(cur_cost < min_cost) {
                    min_cost = cur_cost;
                    fa = j, fb = i, fc = k;
                }
            }
        }
        printf("%d\n%d %d %d\n", min_cost, fa, fb, fc);
    }
    return 0;
}