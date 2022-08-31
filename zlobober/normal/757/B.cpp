#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100500;
int cnt[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    int ans = 1;
    for (int g = 2; g < N; g++) {
        int sum = 0;
        for (int i = g; i < N; i += g) {
            sum += cnt[i];
        }
        ans = max(ans, sum);
    }
    printf("%d\n", ans);
}