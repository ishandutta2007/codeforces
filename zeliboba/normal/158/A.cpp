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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int t = k - 1;
    while (t >= 0 && a[t] == 0)
        --t;
    if (t < k - 1) {
        cout << t + 1 << endl;
        return 0;
    }
    while (t < n && a[t] == a[k - 1])
        ++t;
    cout << t << endl;
    return 0;
}