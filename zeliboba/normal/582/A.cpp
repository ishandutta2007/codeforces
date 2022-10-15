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
    vi sq(1000000);
    for (int i = 0; i * i < sq.size(); ++i) sq[i*i] = i;
    int n;
    cin >> n;
    vi a(n*n);
    map<int, int> w;
    for (int i = 0; i < a.size(); ++i) {
        cin >> a[i];
        w[a[i]]++;
    }
    vi ans;
    while (ans.size() < n) {
        auto it = w.end();
        --it;
        int x = it->first;
        w[x]--;
        if (w[x] == 0) w.erase(x);
        for (auto y : ans) {
            int z = __gcd(y, x);
            w[z] -= 2;
            if (w[z] == 0) w.erase(z);
        }
        ans.push_back(x);
/*        vi add;
        for (auto x : w) {
            if (x.second % 2) {
                add.push_back(x.first);
            }
        }*/
    }
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
    return 0;
}