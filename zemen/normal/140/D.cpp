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

typedef long long li;
typedef long double ld;

#define INF 0x7fffffff

int main() {
    int n;
    int a[101];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    int cnt = 0;
    int fail = 0;
    int time = 0;
    for (int i = 0; i < n; ++i) {
        time += a[i];
        if (time > 710)
            break;
        if (time > 350)
            fail += time - 350;
        cnt++;
    }
    printf("%d %d", cnt, fail);
}