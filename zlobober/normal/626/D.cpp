#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 20000;

int cnt[2 * N];

int A[N];
int sum[2 * N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int d = A[i] - A[j];
            cnt[N + d]++;
            cnt[N - d]++;
        }
    }
    for (int i = 1; i < 2 * N; i++) {
        sum[i] = sum[i - 1] + cnt[i];
    }
    int mx = *max_element(A, A + n);
    double ans = 0;
    for (int x = 1; x <= mx; x++) {
        for (int y = 1; y <= mx; y++) {
            int s = x + y;
            ans += 1.0 * cnt[N + x] * 1.0 * cnt[N + y] * 1.0 * sum[N - s - 1];
        }
    }
    double tot = n * (n - 1);
    tot = tot * tot * tot;
    ans /= tot;
    printf("%.10lf\n", ans * 8.0);
}