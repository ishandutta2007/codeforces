#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, a[N];

bool solve_() {
    for (int i = n; i; i--) {
        a[i] -= a[i - 1];
    }

    for (int i = 2; i <= n; i++) {
        if (--a[i] < 0) {
            return 0;
        }
    }

    int res = 0;

    for (int i = 1; i <= n; i++) {
        if ((n - i + 1)&1) {
            if (a[i]&1) {
                res ^= 1;
            }
        }
    }

    return res;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a + 1, a + n + 1);

    int pos = -1;

    for (int i = 1; i < n; i++) {
        if (a[i] == a[i + 1]) {
            if (pos == -1) {
                pos = i;
            } else {
                puts("cslnb");
                exit(0);
            }
        }
    }

    if (~pos) {
        if (a[pos] && (pos == 1 || a[pos] - 1 > a[pos - 1])) {
            a[pos]--;
            puts(solve_() ? "cslnb" : "sjfnb");
        } else {
            puts("cslnb");
        }
        
        exit(0);
    }

    puts(solve_() ? "sjfnb" : "cslnb");
}