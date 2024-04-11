#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long llong;

int len(int x) {
    if (x == 0)
        return 1;
    int res = 0;
    while (x > 0)
        x /= 10, res++;
    return res;
}

llong answer(int x, int l) {
    llong cur = 1989;
    llong d = 10;
    for (int i = 1; i < l; i++) {
        cur += d;
        d *= 10;
    }
    llong r = (x - cur) % d;
    r = (r + d) % d;
    return cur + r;
}


char buf[20];

int main() {
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buf);
        int l = strlen(buf) - 4;
        int x = atoi(buf + 4);
        llong res = answer(x, l);
        printf("%lld\n", res);
    }
}