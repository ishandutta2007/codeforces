#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, T, sum;

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n), sum = 0;

        for (int x, i = 1; i <= n; i++) {
            scanf("%d", &x);
            sum = (sum + x)%n;
        }

        printf("%d\n", !sum ? 0 : 1);
    }
}