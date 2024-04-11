# include <bits/stdc++.h>
using namespace std;
const int MN = 55;
int a[MN];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    int count = 0;
    sort(a, a + n);
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] > 0 && (i >= n - k || a[i] == a[i + 1]))
            count++;
        else
            break;
    }
    printf("%d\n", count);
}