#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const int MN = 1010;
const int MQ = 1000010;
char s[MQ];
int x[MN] = {};
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int d;
            scanf("%d", &d);
            if (i == j) {
                x[i] = d;
            }
        }
    }
    bool f = false;
    for (int i = 0; i < n; i++) {
        if (x[i]) f = !f;
    }
    int q, qc = 0;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1 || t == 2) {
            int d;
            scanf("%d", &d);
            f = !f;
        } else {
            s[qc] = f ? '1' : '0';
            qc++;
        }
    }
    for (int i = 0; i < qc; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}