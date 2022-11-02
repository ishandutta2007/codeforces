#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int n, a, b, c, T, nq, lq, rq, q[N], sum, cnt, p[N], pos;

char s[N];

ll ans;

void solve_(int op, int sum, int cnt, int lq, int rq, ll res) {
    while (1) {
        op ^= 1;
        ans = max(ans, res);

        if (op) {
            if (sum) {
                if (pos <= nq) {
                    res += a;

                    if (!--q[pos]) {
                        pos++;
                        cnt++;
                    }

                    continue;
                }

                if (lq > 0) {
                    res += a;
                    lq--;
                    continue;
                }

                if (rq > 0) {
                    res += a;
                    rq--;
                    continue;
                }

                if (cnt) {
                    res -= c;
                    cnt--, sum++;
                    continue;
                }

                if (~lq) {
                    res -= c;
                    lq--;
                    continue;
                }

                if (~rq) {
                    res -= c;
                    rq--;
                    continue;
                }

                return;
            } else {
                if (pos <= nq || lq > 0 || rq > 0) {
                    ans = max(ans, res + a);
                }

                if (cnt) {
                    sum++;
                    --cnt; 
                    res -= c;
                    continue;
                }

                return;
            }
        }

        if (!sum) {
            return;
        }

        res += b, sum--;
    }
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d%d%d%s", &n, &a, &b, &c, s + 1), ans = 0;
        sum = cnt = nq = lq = rq = 0;

        while (lq < n && s[lq + 1] == '0') {
            lq++;
        }

        while (rq < n && s[n - rq] == '0') {
            rq++;
        }

        if (lq == n) {
            printf("%d\n", lq >= 2 ? a : 0);
            continue;
        }

        for (int l = lq + 1, r; l <= n - rq; l = r + 1) {
            r = l;

            while (s[l] == s[r + 1] && r < n - rq) {
                r++;
            }

            if (s[l] == '1') {
                sum += r - l;
            } else {
                if (l == r) {
                    cnt++;
                } else {
                    q[++nq] = r - l;
                }
            }
        }

        sort(q + 1, q + nq + 1);

        for (int i = 1; i <= nq; i++) {
            p[i] = q[i];
        }

        lq--, rq--, pos = 1;
        solve_(1, sum, cnt, lq, rq, 0);

        for (int i = 1; i <= nq; i++) {
            q[i] = p[i];
        }

        pos = 1;
        solve_(0, sum, cnt, lq, rq, 0);

        printf("%lld\n", ans);
    }
}