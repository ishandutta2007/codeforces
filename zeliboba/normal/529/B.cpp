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
    cin >> n;
    vii v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
    ll mi = 1e18;
    for (int mh = 1; mh <= 1000; ++mh) {
        int cnt = 0;
        int sum = 0;
        vii ts;
        for (int i = 0; i < n; ++i) {
            if (v[i].second > mh) {
                if (v[i].first > mh) {
                    cnt = n; break;
                }
                ++cnt;
                sum += v[i].second;
            } else {
                if (v[i].first > mh || v[i].first <= v[i].second) {
                    sum += v[i].first;
                } else {
                    ts.push_back(pii(v[i].first - v[i].second, v[i].second));
                }
            }
        }
        if (cnt > n/2) continue;
        int rem = n/2 - cnt;
        sort(ts.rbegin(), ts.rend());
        for (int i = 0; i < ts.size(); ++i) {
            if (i < rem) {
                sum += ts[i].second;
            } else {
                sum += ts[i].second + ts[i].first;
            }
        }
        mi = min(mi, sum*(ll)mh);
    }
    cout << mi << endl;
    return 0;
}