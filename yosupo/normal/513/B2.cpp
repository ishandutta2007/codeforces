#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstdio>
#include <tuple>
#include <cstring>
#include <set>
#include <valarray>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;


const int MN = 55;

ll sol(int n) {
    if (n == 0) return 1;
    return 1LL<<(n-1);
}

int cu;
int res[MN];
void calc(int l, int r, ll m) {
    for (int i = 0; i < r-l; i++) {
        if (m <= sol(r-l-i-1)) {
            res[l] = (cu+i);
            for (int j = 0; j < i; j++) {
                res[r-1-j] = (cu+j);
            }
            cu += i+1;
            calc(l+1, r-i, m);
            return;
        }
        m -= sol(r-l-i-1);
    }
}

int main() {
    int n;
    ll m;
    cin >> n >> m;
    calc(0, n, m);
    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]+1);
    } printf("\n");
    return 0;
}