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
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    int sum = 0, res = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (sum > 12 * 60 - 10)
            break;
        else ++cnt;
        res += max(0, sum - 350);
    }
    cout << cnt << " " << res << endl;
    return 0;
}