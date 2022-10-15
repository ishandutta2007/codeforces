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
    vi v(n + 1);
    for (int i = 1; i <= n; ++i)
        v[i] = i;
    if ((n/2) & 1) {
        cout << -1 << endl;
        return 0;
    } else {
        for (int i = 1; i <= n/2; i += 2) {
            v[i] = i + 1;
            v[n-i+1] = n - i;
            v[i+1] = n - i + 1;
            v[n-i] = i;
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}