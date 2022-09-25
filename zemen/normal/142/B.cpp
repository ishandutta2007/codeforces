#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <complex.h>
#include <string.h>
#include <memory.h>

#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <string>

using namespace std;

typedef long long ll;
typedef long double ld;

#define INF 0x7fffffff
#define mp make_pair
#define pb push_back

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    if (m * n == 4 || n == 1 || m == 1) {
        printf("%d", m * n);
        return 0;
    }
    if (n == 2 && (m % 4 != 0)) {
        if (m % 4 == 1 || m % 4 == 3)
            printf("%d", m + 1);
        if (m % 4 == 2)
            printf("%d", m + 2);
        return 0;
    }
    if (m == 2 && (n % 4 != 0)) {
        if (n % 4 == 1 || n % 4 == 3)
            printf("%d", n + 1);
        if (n % 4 == 2)
            printf("%d", n + 2);
        return 0;
    }
    if (m * n == 6) {
        printf("4");
        return 0;
    }
    printf("%d", (n * m) / 2 + (n * m) % 2);
}