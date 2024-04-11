#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100500;

char buf[N];

int A[N];
int S[N];

int n, k;
int free(int l, int r) {
    r = min(n - 1, r);
    l = max(0, l);
    if (l > r)
        return 0;
    return (r + 1 - l) - (S[r + 1] - S[l]);
}

int main() {
    scanf("%d %d", &n, &k);
    scanf("%s", buf);
    for (int i = 0; i < n; i++) {
        A[i] = buf[i] == '1';
        S[i + 1] = S[i] + A[i];
    }
    int ans = n + 1;
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) {
            int l = 0, r = n - 1;
            while (r - l > 1) {
                int x = (l + r) / 2;
                if (free(i - x, i + x) >= k + 1)
                    r = x;
                else
                    l = x;
            }
            ans = min(ans, r);
        }
    }
    printf("%d\n", ans);
}