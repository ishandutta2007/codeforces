#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <queue>

using namespace std;
typedef unsigned int uint;
typedef long long ll;

inline int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

int d[1024][1024];
int main() {
    uint n, m;
    scanf("%d%d", &n, &m);
    int *p = d[0];
    for (uint i = 0; i < n; i++) {
        int *q = p;
        for (uint j = 0; j < m; j++) {
            scanf("%d", q);
            q++;
        }
        p += 1024;
    }
    int res = 0;
    for (uint i = 0; i < n; i++) {
        for (uint j = i+1; j < n; j++) {
            int b1 = 0, b2 = 0;
            int *r1 = d[i], *r2 = d[j];
            for (uint k = 0; k < m; k++) {
                int b = fastMin(*r1, *r2);
                r1++; r2++;
                if (b > b2) {
                    b1 = b2;
                    b2 = b;
                } else if (b > b1) {
                    b1 = b;
                }
            }
            res = max(res, b1);
        }
    }
    printf("%d\n", res);
    return 0;
}