#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MSK = 1 << 7;
int cntB[MSK];

const int MAX = 7 * 7 * 7 * 7 * 7 * 7 * 7;

typedef long long llong;

void print(char* buf, int x, int len) {
    int pt = 0;
    for (int i = 0; i < len; i++) {
        buf[pt++] = x % 7 + '0', x /= 7;
    }
    buf[pt] = 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    llong lenA = 1, valA = 7, lenB = 1, valB = 7;
    while (valA < n)
        valA *= 7, lenA++;
    while (valB < m)
        valB *= 7, lenB++;
    if (lenA + lenB > 7) {
        printf("%d\n", 0);
        return 0;
    }
    for (int i = 0; i < min(MAX, m); i++) {
        char buf[10];
        print(buf, i, lenB);
        int len = strlen(buf);
        int msk = 0;
        bool bad = false;
        for (int j = 0; j < len; j++) {
            int c = buf[j] - '0';
            if ((msk >> c) & 1) {
                bad = true;
            } else {
                msk |= 1 << c;
            }
        }
        if (!bad)
            cntB[msk]++;
    }

    llong ans = 0;
    for (int i = 0; i < min(MAX, n); i++) {
        char buf[10];
        print(buf, i, lenA);
        int len = strlen(buf);
        int msk = 0;
        bool bad = false;
        for (int j = 0; j < len; j++) {
            int c = buf[j] - '0';
            if ((msk >> c) & 1) {
                bad = true;
            } else {
                msk |= 1 << c;
            }
        }
        if (bad)
            continue;
        for (int msk2 = 0; msk2 < MSK; msk2++) {
            if (msk2 & msk)
                continue;
            ans += cntB[msk2];
        }
    }
    printf("%lld\n", ans);
}