#include <cstdio>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int cur = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cur += 5 * i;
        if (cur + k > 240) {
            break;
        }
        ans = i;
    }
    printf("%d\n", ans);
}