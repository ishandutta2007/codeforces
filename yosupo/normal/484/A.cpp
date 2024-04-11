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

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r; r++;
        int k;
        for (k = 61; k >= 0; k--) {
            ll l1 = l & (1LL<<k), r1 = r & (1LL<<k);
            if (l1 != r1) {
                break;
            }
        }
        cout << (l | ((1LL<<k)-1)) << endl;;
    }
}