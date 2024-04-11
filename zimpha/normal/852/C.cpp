#include <algorithm>
#include <cstdio>
#include <utility>

const int N = 50000;

int a[N + 1], result[N];
std::pair<int, int> coef[N];

int main()
{
#ifdef LOCAL_JUDGE
    freopen("C.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
    }
    a[n] = a[0];
    for (int i = 0; i < n; ++ i) {
        coef[i].first = a[i] + a[i + 1];
        coef[i].second = i;
    }
    std::sort(coef, coef + n);
    for (int i = 0; i < n; ++ i) {
        result[coef[i].second] = i;
    }
    for (int i = 0; i < n; ++ i) {
        printf("%d%c", result[i], " \n"[i == n - 1]);
    }
}