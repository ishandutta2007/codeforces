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
    vi x(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &x[i]);
    sort(x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    n = x.size();
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    while (a != b) {
        int a1 = a - 1;
        for (int i = x.size() - 1; i >= 0 && x[i] > a-a1; --i) {
            int cur = a - a%x[i];
            if (cur >= b && cur < a1) {
                a1 = cur;
            }
        }
        while (!x.empty() && a - a%x.back() < b) {
            x.pop_back();
        }
        swap(a1, a);
        ++cnt;
    }
    cout << cnt << endl;
    return 0;
}