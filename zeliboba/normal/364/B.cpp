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
    ll d,n;
    cin >> n >> d;
    vl v(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());
    vi was(sum + 1);
    was[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = sum; j >= v[i]; --j) if (was[j-v[i]])
            was[j] = 1;
    }
    int ma = 0;
    int it = 0;
    vi dist(sum+1);
    for (int i = 1; i <= sum; ++i) if (was[i]) {
        while (it + d < i || !was[it]) ++it;
        if (it == i) break;
        dist[i] = dist[it] + 1;
        ma = i;
    }
    cout << ma << ' ' << dist[ma] << endl;
    return 0;
}