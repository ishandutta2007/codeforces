#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <random>
#include <complex>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;

ll norm(const P &p) {
    return 1LL*p.first*p.first + 1LL*p.second*p.second;
}

P operator-(const P &l, const P &r) {
    return P(l.first-r.first, l.second-r.second);
}

P operator/(const P &l, const ll &r) {
    return P(l.first/r, l.second/r);
}


const int MN = 100100;

int n;
P a[MN];

const int MD = 1e6+7;
auto p_hash = [](const P &p){ return p.first+p.second;};
unordered_map<P, vector<P>, decltype(p_hash)> mp(0, p_hash);
ll solve() {
    shuffle(a, a+n, mt19937());
    ll res = norm(a[1]-a[0]);
    ll rs = ceil(sqrt(ld(res)));
    mp[a[0]/rs].push_back(a[0]);
    mp[a[1]/rs].push_back(a[1]);
    for (int i = 2; i < n; i++) {
        P p = a[i]/rs;
        ll r = res;
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                auto it = mp.find(P(p.first+x, p.second+y));
                if (it == mp.end()) continue;
                for (P u: it->second) {
                    r = min(r,
                        norm(a[i]-u));
                }
            }
        }
        if (res <= r) {
            mp[p].push_back(a[i]);
        } else {
            mp.clear();
            res = r;
            rs = ceil(sqrt(ld(res)));
            for (int j = 0; j <= i; j++) {
                mp[a[j]/rs].push_back(a[j]);
            }
        }
    }
    return res;
}

int main() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        sum += d;
        a[i] = P(i, sum);
    }
    cout << solve() << endl;
    return 0;
}