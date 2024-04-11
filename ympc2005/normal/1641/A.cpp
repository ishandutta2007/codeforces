#include <bits/stdc++.h>
using namespace std;

int T, n, ans, m;

multiset <int> s;

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);

        for (int x, i = 1; i <= n; i++) {
            scanf("%d", &x);
            s.insert(x);
        }

        ans = 0;

        while (s.size()) {
            int x = *s.begin();
            s.erase(s.begin());

            if (1ll*x*m <= 1e9 && s.find(x*m) != s.end()) {
                s.erase(s.find(x*m));
            } else {
                ans++;
            }
        }

        printf("%d\n", ans);
    }
}