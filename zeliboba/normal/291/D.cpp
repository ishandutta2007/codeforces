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
    int n, k;
    cin >> n >> k;
    vi v(n+1, 1);
    v[n] = 0;
    for (int t = 0; t < k; ++t) {
        for (int i = 1; i <= n; ++i) {
            int x = 0;
            if (v[i]*2 <= n-i) {
                x = i;
                v[i] *= 2;
            } else {
                x = n - (n-i-v[i]);
                v[i] = n-i;
            }
            printf("%d ", x);
        }
        printf("\n");
    }
    return 0;
}