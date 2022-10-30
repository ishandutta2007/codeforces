#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, a[N], mn, ans[3], b[N];

char s[N];

void solve1_() {
    int l = n + 1, r = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] <= mn + 1) {
            l = min(l, i);
            r = max(r, i + 1);
        }
    }    

    while (l >= 1 && s[l] != ')') {
        l--;
    }

    while (r <= n && s[r] != '(') {
        r++;
    }

    if (1 <= l && r <= n) {
        int res = 0;

        for (int i = 1; i < l; i++) {
            res += a[i] == mn + 2;
        }

        for (int i = r; i <= n; i++) {
            res += a[i] == mn + 2;
        }

        for (int i = l; i < r; i++) {
            res += a[i] == mn;
        }

        if (res > ans[0]) {
            ans[0] = res;
            ans[1] = l;
            ans[2] = r;
        }
    }
}

void solve2_() {
    int l = n + 1, r = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] <= mn) {
            l = min(l, i);
            r = max(r, i + 1);
        }
    }    

    while (l >= 1 && s[l] != ')') {
        l--;
    }

    while (r <= n && s[r] != '(') {
        r++;
    }

    if (1 <= l && r <= n) {
        int res = 0;

        for (int i = 1; i < l; i++) {
            res += a[i] == mn + 1;
        }

        for (int i = r; i <= n; i++) {
            res += a[i] == mn + 1;
        }

        if (res > ans[0]) {
            ans[0] = res;
            ans[1] = l;
            ans[2] = r;
        }
    }
}

void work1_(int l, int r) {
    int mx = -1e9, p = 0, cnt = 0;

    for (int i = l; i <= r; i++) {
        if (s[i] == '(') {
            if (mx < b[i - 1] - cnt) {
                mx = b[i - 1] - cnt;
                p = i;
            }
        } else {
            if (ans[0] < b[n] - b[i - 1] + cnt + mx) {
                ans[0] = b[n] - b[i - 1] + cnt + mx;
                ans[1] = p;
                ans[2] = i;
            }
        }

        cnt += a[i] == mn + 2;
    }
}

void solve3_() {
    int p = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] <= mn + 1) {
            if (p + 1 <= i) {
                work1_(p + 1, i);
            }

            p = i;
        }
    }

    if (p + 1 <= n) {
        work1_(p + 1, n);
    }
}

void work2_(int l, int r) {
    while (l <= r && s[l] != '(') {
        l++;
    }

    while (l <= r && s[r] != ')') {
        r--;
    }

    if (l <= r) {
        int cnt = 0;

        for (int i = l; i < r; i++) {
            cnt += a[i] == mn + 1;
        }

        if (cnt > ans[0]) {
            ans[0] = cnt;
            ans[1] = l;
            ans[2] = r;
        }
    }
}

void solve4_() {
    int p = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] <= mn) {
            if (p + 1 <= i) {
                work2_(p + 1, i);
            }

            p = i;
        }
    }

    if (p + 1 <= n) {
        work2_(p + 1, n);
    }
}

int main() {
    scanf("%d%s", &n, s + 1);

    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1];
        a[i] += s[i] == '(';
        a[i] -= s[i] == ')';
        mn = min(mn, a[i]);
    }

    if (a[n]) {
        puts("0\n1 1");
        exit(0);
    }

    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + (a[i] == mn);
    }

    ans[0] = b[n];
    ans[1] = ans[2] = 1;   
    solve1_(); // mn + 2;
    solve2_(); // mn + 1;
    solve3_(); // mn;
    solve4_(); // mn - 1;
    printf("%d\n%d %d\n", ans[0], ans[1], ans[2]);
}