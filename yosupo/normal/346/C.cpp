#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <complex>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int MN = 100100;
const int MK = 1001000;
int main() {
    int n;
    cin >> n;
    ll x[MN];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    ll a, b;
    cin >> a >> b;
    int d[MK];
    for (int i = 0; i < MK; i++) {
        d[i] = i-1;
    }
    vector<P> v;
    for (int i = 0; i < n; i++) {
        v.push_back(P((b+x[i]-1)/x[i]*x[i]-b, x[i]));
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    n = v.size();
    for (int i = 0; i < n; i++) {
        P p = v[i];
        do {
            int u = p.first;
            for (int j = min(MK-1, p.first+p.second-1); j > p.first; j--) {
                if (d[j] <= u) break;
                d[j] = u;
            }
            p.first += p.second;
        } while (p.first < MK);
    }
    int r = 0;
    a -= b;
    while (a) {
        a = d[a];
        r++;
    }
    cout << r << endl;
    return 0;
}