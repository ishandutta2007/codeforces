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
typedef long long i64;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vi a(m), b(m), c(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    long long sum = 0;
    for (int i = 0; i < k; ++i) {
        int t;
        cin >> t;
        for (int j = 0; j < m; ++j) {
            if (t >= a[j] && t <= b[j]) {
                sum += (c[j] + t - a[j]);
            }
        }
    }
    cout << sum << endl;
    return 0;
}