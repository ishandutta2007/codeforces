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

using namespace std;

typedef long long ll;

const int BS = 1000;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int aa;
        scanf("%d", &aa);
        a.push_back(aa);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    vector<int> b = a;
    reverse(b.begin(), b.end());
    n = a.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < BS) {
            for (int j = i+1; j < n; j++) {
                res = max(res, a[j] % a[i]);
            }
        } else {
            for (int x = a[i]*2; ; x += a[i]) {
                auto it = upper_bound(b.begin(), b.end(), x, greater<int>());
                int y = *it;
                if (y < a[i]) continue;
                res = max(res, y % a[i]);
                if (it == b.begin()) break;
            }
        }
    }
    printf("%d\n", res);
}