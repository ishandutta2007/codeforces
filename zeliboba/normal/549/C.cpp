#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
    int n, k;
    cin >> n >> k;
    vi a(2);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++a[x%2];
    }
    if (n == k) {
        if (a[1] % 2) {
                cout << "Stannis\n";    
                return 0;
        }
    }
    if ((n - k) % 2) {
        if (k % 2) {
            if ((n - k) / 2 >= a[1]) {
                cout << "Daenerys\n";
                return 0;
            }
        } else {
            if ((n - k) / 2 >= min(a[0], a[1]) || (n - k) / 2 >= -1 + max(a[0], a[1])) {
                cout << "Daenerys\n";
                return 0;
            }
        }
        cout << "Stannis\n";    
    } else {
        if (k % 2) {
            if ((n - k) / 2 >= a[0]) {
                cout << "Stannis\n";    
                return 0;
            }
        }
        cout << "Daenerys\n";
    }
    return 0;
}