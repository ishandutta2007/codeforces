#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int n;
    cin >> n;
    vi a(n);
    int ma = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ma += a[i];
    }
    for (int d = 3; d <= n; ++d) if (n % d == 0) {
        vi res(n / d);
        for (int i = 0; i < n; ++i)
            res[i % (n / d)] += a[i];
        for (int i = 0; i < res.size(); ++i)
            ma = max(ma, res[i]);
    }
    cout << ma << endl;
    return 0;
}