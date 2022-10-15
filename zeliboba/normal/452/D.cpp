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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
    ll k,n1,n2,n3,t1,t2,t3;
    cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
    multiset<ll> v1,v2,v3;
    for (int i = 0; i < n1; ++i) v1.insert(0);
    for (int i = 0; i < n2; ++i) v2.insert(0);
    for (int i = 0; i < n3; ++i) v3.insert(0);
    ll ans = 0, t = 0;
    for (int i = 0; i < k; ++i) {
        ll b1 = *v1.begin();
        v1.erase(v1.begin());
        ll b2 = *v2.begin();
        v2.erase(v2.begin());
        ll b3 = *v3.begin();
        v3.erase(v3.begin());
        t = max(t, max(b1, max(b2 - t1, b3 - t1 - t2)));
        ans = t + t1 + t2 + t3;
        v1.insert(t + t1);
        v2.insert(t + t1 + t2);
        v3.insert(t + t1 + t2 + t3);
    }
    cout << ans << endl;
    return 0;
}