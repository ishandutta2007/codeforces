#include <bits/stdc++.h>
using namespace std;

int T, a, b, c;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &a, &b, &c);
        printf("%d %d %d\n", a + b + c, b + c, c);
    }
    return 0;
}