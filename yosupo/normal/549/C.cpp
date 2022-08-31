#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;

int d[2];
int n,k;
// 1 : s syouri
// 0 : d syouri
bool solve() {
    int l = n-k;
    if (l == 0) {
        return d[1] % 2;
    }
    if (l % 2) { // s yuuri
        int x = l/2;
        if (d[0] <= x) {
            //zenbu 1 sum k
            if (k % 2 == 0) {
                return 0;
            }
        }
        if (d[1] <= x) {
            return 0;
        }
        return 1;
    } else { // d yuuri
        int x = (l+1)/2;
        if (d[0] <= x) {
            if (k % 2 == 1) {
                return 1;
            }
        }
        return 0;
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a %= 2;
        d[a]++;
    }
    if (solve()) {
        cout << "Stannis" << endl;
    } else {
        cout << "Daenerys" << endl;
    }
    return 0;
}