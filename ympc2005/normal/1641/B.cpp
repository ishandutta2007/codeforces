#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

int n, T;

map <int, int> mp;

vector <int> a, b;

vector <pii> op;

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        mp.clear();
        a.clear();
        b.clear();
        op.clear();

        for (int x, i = 1; i <= n; i++) {
            scanf("%d", &x);
            a.push_back(x);
            mp[x]++;
        }   

        bool ok = 0;

        for (int x : a) {
            if (mp[x]&1) {
                ok = 1;
            }
        }

        if (ok) {
            puts("-1");
            continue;
        }

        while (a.size()) {
            int r = a.size() - 1, l = r - 1;

            while (a[l] != a[r]) {
                l--;
            }   

            for (int i = 1; i <= r - l - 1; i++) {
                op.push_back(pii(l + i - 1, a[r - i]));
            }

            b.push_back(2*(r - l));
            reverse(a.begin() + l, a.begin() + r);
            a.pop_back();
            a.pop_back();
        }

        reverse(b.begin(), b.end());

        printf("%u\n", op.size());

        for (auto x : op) {
            printf("%d %d\n", x.first, x.second);
        }

        printf("%u\n", b.size());

        for (int x : b) {
            printf("%d ", x);
        }

        putchar('\n');
    }
}