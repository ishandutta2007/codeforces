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
const int mod = 1000000007;

vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

int main() {
    int n,m;
    cin >> n >> m;
    string p;
    cin >> p;
    vi v(m);
    for (int i = 0; i < m; ++i) {
        cin >> v[i];
        --v[i];
    }
    sort(v.begin(), v.end());
    ll res = 1;
    int it = 0;
    for (int i = 0; i < n; ++i) {
        while (it + 1 < v.size() && v[it + 1] <= i) {
            ++it;
        }
        if (it >= v.size() || v[it] > i || v[it] + p.size() <= i) res = res * 26 % mod;
    }
    if (m) {
        vi pr = prefix_function(p);
        vi ok(p.size() + 1);
        int cur = p.size();
        while (cur) {
            ok[cur] = 1;
            cur = pr[cur - 1];
        }
        for (int i = 1; i < m; ++i) {
            if (v[i] - v[i-1] < p.size() && !ok[p.size() - (v[i] - v[i-1])]) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << res << endl;
    return 0;
}