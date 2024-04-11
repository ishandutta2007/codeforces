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
    vi erat(100001);
    for (int i = 2; i < erat.size(); ++i)
        erat[i] = i;
    erat[0] = erat[1] = 1;
    for (int i = 2; i * i < erat.size(); ++i) if (erat[i] == i)
        for (int j = i * i; j < erat.size(); j += i)
            erat[j] = i;
    vi primes, ind(100001);
    for (int i = 2; i < erat.size(); ++i) if (erat[i] == i) {
        ind[i] = primes.size(); 
        primes.push_back(i);
    }
    cerr << primes.size() << endl; 
    int n;
    cin >> n;
    vvi a(primes.size()), vtop(n);
    vi v(n), indv(100001);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        indv[v[i]] = i;
        int t = v[i];
        while (t > 1) {
            int p = erat[t];
            a[ind[p]].push_back(v[i]);
            vtop[i].push_back(ind[p]);
            while (t % p == 0)
                t /= p;
        }
    }
    sort(v.begin(), v.end());
    vi d(v.size(), 1);
    int ma = 1;
    for (int i = 0; i < v.size(); ++i) {
        ma = max(ma, d[i]);
        for (int j = 0; j < vtop[i].size(); ++j) {
            int l = vtop[i][j];
            int it = lower_bound(a[l].begin(), a[l].end(), v[i] + 1) - a[l].begin();
            if (it < a[l].size()) {
                int cur = indv[a[l][it]];
                d[cur] = max(d[cur], d[i] + 1);
            }
        }
    }
    cout << ma << endl;
    return 0;
}