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
#include <complex>
#include <cmath>
#include <stack>

using namespace std;
typedef long long ll;
const int MN = 303000;
const int MD = 1010000;
const int BS = 1010;
int dp[MD];
int main() {
    int n, k;
    scanf("%d %d", &n, &k); k++;
    vector<int> d, dd;
    for (int i = 0; i < n; i++) {
        int u;
        scanf("%d", &u);
        d.push_back(u);
        dd.push_back(u-k);
    }
    int u = *min_element(d.begin(), d.end());
    if (u < k) {
        cout << u << endl;
        return 0;
    }
    int r1 = 0;
    for (int t = BS-1; t > 0; t--) {
        bool f = true;
        for (int i = 0; i < n; i++) {
            if (d[i]/t == dd[i]/t) {
                f = false;
                break;
            }
        }
        if (f) {
            r1 = t;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        int ba = MD;
        int j = 1;
        while (true) {
            int l = dd[i]/j, r = min(ba, d[i]/j);
            if (r <= BS) break;
            ba = l;
            dp[l]++;
            dp[r]--;
            j++;
        }
    }
    for (int i = 1; i < MD; i++) {
        dp[i] += dp[i-1];
    }
    int r2 = 0;
    for (int i = MD-1; i >= BS; i--) {
        if (dp[i] == n) {
            r2 = i+1;
            break;
        }
    }
    cout << max(r1, r2) << endl;
    return 0;
}