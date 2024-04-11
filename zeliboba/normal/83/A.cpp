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
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int main() {
    int n;
    cin >> n;
    vi a(n);
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            ++cnt;
        } else {
            res += (cnt * cnt + cnt) / 2;
            cnt = 1;
        }
    }
    res += (cnt * cnt + cnt) / 2;
    cout << res << endl;
    return 0;
}