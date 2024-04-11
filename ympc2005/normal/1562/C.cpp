#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int T, n, l[2], r[2];

char s[N];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%s", &n, s + 1);

        bool ok = 1;

        for (int i = 1; i <= n; i++)
            if (s[i] == '0') {
                ok = 0;

                if (i > n/2) {
                    l[0] = i - n/2, r[0] = i;
                    l[1] = i - n/2, r[1] = i - 1;
                } else {
                    l[0] = i, r[0] = i + n/2;
                    l[1] = i + 1, r[1] = i + n/2;
                }

                break;
            }
        
        if (!ok) 
            printf("%d %d %d %d\n", l[0], r[0], l[1], r[1]);
        else
            printf("%d %d %d %d\n", 1, n/2, 2, n/2 + 1);
    }
}