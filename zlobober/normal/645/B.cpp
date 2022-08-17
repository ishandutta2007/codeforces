#include <cstdio>
#include <iostream>
using namespace std;

typedef long long llong;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    llong ans = 0;
    int cur = n;
    for (int i = 0; i < k; i++) {
        if (cur <= 1)
            break;
        ans += 2 * (cur - 2) + 1;
        cur -= 2;
    }
    cout << ans << endl;
}