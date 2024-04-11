#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 10, mod = 1e9 + 7;

int n, x;

char s[N];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d%s", &x, s + 1);
        n = strlen(s + 1);

        for (int i = 1; i <= x; i++) {
            int l = i + 1, r = n;

            for (int j = s[i] - '1'; j; j--) {
                for (int k = l; k <= r; k++) {
                    s[++n] = s[k];
                }
            }

            if (n >= x) {
                int len = n;

                for (int j = i + 1; j <= x; j++) {
                    len = (j + 1ll*(len - j)*(s[j] - '0'))%mod;
                }

                printf("%d\n", (len%mod + mod)%mod);
                break;
            }
        }
    }
}