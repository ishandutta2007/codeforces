#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 10;

int n, T, m, c[N], a[N];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);

        for (int i = 1; i <= n; i++) {
            c[i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            c[a[i]]++;
        }

        int sum = 0, x = 1, y = n;

        for (int i = 1, j = 0; i <= n; i++) {
            sum -= c[i - 1];

            while (j <= n && sum - (n - sum) < m) {
                sum += c[++j];
            }

            if (j > n) {
                break;
            }

            if (j - i < y - x) {
                y = j;
                x = i;
            }
        }

        sum = 0;
        printf("%d %d\n", x, y);
        int pos = 0;

        for (int i = 1; i < m; i++) {
            printf("%d ", pos + 1);

            while (sum < i) {
                pos++;

                if (x <= a[pos] && a[pos] <= y) {
                    sum++;
                } else {
                    sum--;
                }
            }

            printf("%d\n", pos);
        }

        printf("%d %d\n", pos + 1, n);
    }
}