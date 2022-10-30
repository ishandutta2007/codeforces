#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n, a[55], sum, m, ans, S;

bitset <24*50000 + 10> f[52][26];

int main() {
    scanf("%d", &n), n *= 2, m = n/2 - 1;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a + 1, a + n + 1);
    f[2][0][0] = 1;

    for (int i = 3; i <= n; i++) {
        sum += a[i];
        f[i][0][0] = 1;

        for (int j = 1; j <= i && j <= m; j++) {
            f[i][j] = f[i - 1][j]|(f[i - 1][j - 1]<<a[i]);
        }
    }

    ans = 1e9;

    for (int i = 0; i <= sum/2; i++) {
        if (f[n][m][i] && max(i, sum - i) < ans) {
            ans = max(i, sum - i);
            S = i;
        }
    }

    vector <int> A, B;
    A.push_back(a[1]);
    B.push_back(a[2]);

    for (int i = n, j = m, k = S; i >= 3; i--) {
        if (f[i - 1][j][k]) {
            B.push_back(a[i]);
        } else {
            A.push_back(a[i]);
            j--;
            k -= a[i];
        }
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());

    for (int x : A) {
        printf("%d ", x);
    }

    putchar('\n');

    for (int x : B) {
        printf("%d ", x);
    }

    putchar('\n');
}