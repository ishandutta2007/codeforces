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
    vi c(n), t(n);
    vii tab;
    int mi = 1e9;
    ll sum_all = 0;
    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> t[i];
        mi = min(mi, c[i]);
        sum_all += c[i];
        if (t[i] == 1)
            tab.push_back(pii(c[i], i));
    }
    sort(tab.begin(), tab.end());
    if (k > tab.size()) {
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            if (t[i] == 1)
                sum += c[i];
            else sum += 2 * c[i];
        }
        cout << sum / 2 << "." << 5 * (sum % 2) << endl;
        for (int i = 0; i < tab.size(); ++i)
            printf("1 %d\n", tab[i].second + 1);
        int i = 0, cur = tab.size() + 1;
        for (; cur < k; ++i) if (t[i] != 1) {
            printf("1 %d\n", i + 1);
            ++cur;
        }
        printf("%d", n - k + 1);
        for (; i < n; ++i) if (t[i] != 1)
            printf(" %d", i + 1);
        printf("\n");
    } else {
        ll sum = 2 * sum_all - mi;
        for (int i = 0; i < k - 1; ++i) 
            sum -= c[tab[tab.size() - i - 1].second];
        cout << sum / 2 << "." << 5 * (sum % 2) << endl;
        for (int i = 0; i < k - 1; ++i) {
           printf("1 %d\n", tab[tab.size() - i - 1].second + 1);
           t[tab[tab.size() - i - 1].second] = 0;
        }
        printf("%d", n - k + 1);
        for (int i = 0; i < n; ++i) if (t[i])
            printf(" %d", i + 1);
        printf("\n");
    }
    return 0;
}