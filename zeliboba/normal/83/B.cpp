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
    ll n, k;
    cin >> n >> k;
    vi a(n);
    vii t(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        t[i] = pii(a[i], i);
        sum += a[i];
    }
    if (sum < k) {
        cout << -1 << endl;
        return 0;
    }
    if (sum == k) {
        cout << endl;
        return 0;
    }
    sort(t.begin(), t.end());
    int cur = 0;
    int past = 0;
    while (k >= (t[cur].first - past) * (n - cur)) {
//        cerr << k << endl;
        k -= (t[cur].first - past) * (n - cur);
        past = t[cur].first;
        ++cur;
    }
    ll k1 = k % (n - cur);
    past += k / (n - cur);
    vi was(n, 1);
    vi q;
    for (int i = 0; i < n; ++i) {
        if (i < cur)
            was[t[i].second] = 0;
    }
    for (int i = 0; i < n; ++i)
        if (was[i])
            q.push_back(i);
    for (int i = k1; i < q.size(); ++i)
        printf("%d ", q[i] + 1);
    for (int i = 0; i < k1; ++i) if (a[q[i]] > past + 1)
        printf("%d ", q[i] + 1);
    cout << endl;
    return 0;
}