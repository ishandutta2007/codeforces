#include <bits/stdc++.h>
using namespace std;

int T, w, l;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &w, &l);
        vector<int> res;
        auto test = [&](int i) {
            if (!(w % i) && !((l - 2) % i)) res.push_back(i);
            if (!((w - 1) % i) && !((l - 1) % i)) res.push_back(i);
            if (!(w % i) && !((l - 1) % i) && !((w - 2) % i)) res.push_back(i);
        };
        auto solve = [&]() {
            for (int i = 1; i * i <= w; i++) {
                if (!(w % i)) test(i), test(w / i);
                if (!((w - 1) % i)) test(i), test((w - 1) / i);
            }
        };
        solve(), swap(w, l), solve();
        sort(res.begin(), res.end());
        res.resize(unique(res.begin(), res.end()) - res.begin());
        printf("%d", res.size());
        for (int x : res) printf(" %d", x);
        putchar('\n');
    }
    return 0;
}