#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 10;

int n, a[N], l[N], r[N], b[N], ans, st[N], ed[N], tot;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);

        if (!l[a[i]]) {
            l[a[i]] = i;
        }

        r[a[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (l[i] < r[i]) {
            b[l[i] + 1]++;
            b[r[i]]--;
        }
    }

    for (int i = 1; i <= n; i++) {
        b[i] += b[i - 1];

        if (l[a[i]] != i && r[a[i]] != i) {
            ans += b[i] > 0;
        }

        if (l[a[i]] == r[a[i]]) {
            ans += b[i] > 0;
        }

        if (l[a[i]] == i && r[a[i]] > i) {
            ++tot;
            st[tot] = i;
            ed[tot] = r[a[i]];
            ans += 2;
        }
    }   

    int pos = -1;

    for (int i = 1; i <= tot; i++) {
        if (st[i] > pos) {
            ans -= 2, pos = ed[i];
        }

        int j = i;
        i--;

        while (i < tot && st[i + 1] < pos) {
            i++;

            if (ed[i] > ed[j]) {
                j = i;
            }
        }

        ans -= pos < ed[j];
        pos = ed[j];
    }

    printf("%d\n", ans);
}