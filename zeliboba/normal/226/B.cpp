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
    vi a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    int q;
    cin >> q;
    vi k(q);
    for (int i = 0; i < k.size(); ++i) 
        scanf("%d", &k[i]);
    vl res(350);
    for (int i = 1; i < res.size(); ++i) {
        ll l = 1, sum = 1, t = 1;
        while (sum < n) {
            l *= i;
            for (int j = 1; j <= l && j + sum <= n; ++j)
                res[i] += a[n - sum - j] * t;
            sum += l;
            ++t;
        }
    }
    vl s(n + 1);
    for (int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + a[n - i];
    vl resq(q);
    for (int i = 0; i < k.size(); ++i) {
        if (k[i] >= n - 1) {
            resq[i] = s.back() - s[1];
        } else if (k[i] < res.size())
            resq[i] = res[k[i]];
        else {
            resq[i] = res.back() - (s[k[i] + 1] - s[res.size()]);
        }
    }
    for (int i = 0; i < resq.size(); ++i)
        cout << resq[i] << " ";
    return 0;
}