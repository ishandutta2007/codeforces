#include <cstdio>
#include <cstring>
using namespace std;

char buf[100];

typedef long long llong;

int main() {
    scanf("%s", buf);
    int len = strlen(buf);
    char p = buf[len - 1];
    --len;
    buf[len] = 0;
    llong n = 0;
    for (int i = 0; i < len; i++) {
        n = 10 * n + (buf[i] - '0');
    }
    --n;
    llong add = (n / 4) * 2 * 6 + (n / 4) * 4;
    n %= 4;
    if (n % 2 == 1) {
        add += 6 + 1;
    }
    if (p >= 'd')
        add += 'f' - p;
    else
        add += 3 + p - 'a';
    printf("%lld\n", add + 1);
}