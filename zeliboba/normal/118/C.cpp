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
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int mi = 1e9;
    string best(n, '0');
    for (int d = 0; d < 10; ++d) {
        vector<pii> ts;
        for (int i = 0; i < n; ++i) {
            if (s[i] - '0' > d)
                ts.push_back(pii(abs((int)s[i] - '0' - d), i));
            else ts.push_back(pii(abs((int)s[i] - '0' - d), 2 * n - i));
        }
        sort(ts.begin(), ts.end());
        string next = s;
        int nmi = 0;
        for (int i = 0; i < k; ++i) {
            nmi += ts[i].first;
            next[n - abs(ts[i].second - n)] = '0' + d;
        }
        if (nmi < mi || (nmi == mi && next < best)) {
            mi = nmi;
            best = next;
        }
    }
    cout << mi << endl << best << endl;
    return 0;
}