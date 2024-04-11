#include <bits/stdc++.h>
using namespace std;

int T, a, b;

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &a, &b);

        int l = 0, r = b;

        while (l < r) {
            int mid = (l + r + 1)>>1;

            if (max(a, mid + 1) + mid <= b)
                l = mid;
            else
                r = mid - 1;
        }

        printf("%d\n", l);
    }
}