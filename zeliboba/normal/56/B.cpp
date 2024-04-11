#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

int main() {
    int n;
    vi v(n + 1);
    int l = n - 1, r = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        if (v[i] != i) {
            r = max(r, i);
            l = min(l, i);
        }
    }
    if (l >= r) {
        printf("0 0\n");
        return 0;
    }
    for (int i = l; i <= r; ++i) {
        if (v[i] != r - (i - l)) {
            printf("0 0\n");
            return 0;
        }
    }
    printf("%d %d\n", l, r);
    return 0;
}