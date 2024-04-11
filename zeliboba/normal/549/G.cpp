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
    int n;
    scanf("%d", &n);
    vi a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) {
        a[i] -= n-i;
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < a.size(); ++i) if (a[i] == a[i-1]) {
        printf(":(\n");
        return 0;
    }
    for (int i = 0; i < a.size(); ++i) {
        a[i] += n-i;
        printf("%d ", a[i]);
    }
    return 0;
}