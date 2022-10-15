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
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

double c(int k, int n) {
    double res = 1;
    for (int i = 0; i < k; ++i)
        res *= (n - i) / (double)(i + 1);
    return res;
}

int main() {
    int n, m, h;
    cin >> n >> m >> h;
    --h;
    vi s(m);
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        cin >> s[i];
        sum += s[i];
    }
    --n;
    --s[h];
    --sum;
    if (sum < n) {
        cout << -1 << endl;
        return 0;
    }
    if (sum - s[h] < n) {
        cout << 1 << endl;
        return 0;
    }
    double tot = c(n, sum), bad = c(n, sum - s[h]);
    printf("%lf\n", (tot - bad) / tot);
    return 0;
}