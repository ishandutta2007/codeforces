#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int T, n;

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n<<1; j++) {
                if (j == i + 1)
                    putchar(')');
                else if (j - (j >= i + 1) <= n)
                    putchar('(');
                else
                    putchar(')');
            }

            puts("");
        }
    }
}