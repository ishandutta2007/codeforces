#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, a, b, c;

    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &a, &b);
        
        if (a > b) {
            c = a + b;
        }

        if (a == b) {
            c = a;
        }

        if (a < b) {
            c = b - b%a/2;
        }

        assert(c%a == b%c);
        printf("%d\n", c);
    }
}