#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <valarray>
#include <list>
#include <cstring>

using namespace std;

typedef long long ll;

const int MN = 100100;
const ll MD = 1e9+7;
vector<int> v;
int n, k;

void solve(int l, int r) {
    if (l == r) return;
    v.push_back(l);
    if (k) {
        k--;
        solve(r + ((l < r) ? -1 : 1), l);
    } else {
        solve(l + ((l < r) ? 1 : -1), r);
    }
}

int main() {
    cin >> n >> k; k--;
    solve(0, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]+1);
    }
    printf("\n");
}