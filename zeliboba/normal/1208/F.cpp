    #include <stdio.h>
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
    #include <unordered_map>
    #include <queue>
    #include <array>
    #include <bitset>
    #include <chrono>
    #include <random>
    using namespace std;
    typedef long double ld;
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
    //const int mod = ;
     
    const int N = 1 << 21;
    pii v[N];
     
    pii f(pii a, pii b) {
      array<int, 4> v = {a.first, a.second, b.first, b.second};
      sort(v.rbegin(), v.rend());
      return pii(v[0], v[1]);
    }
     
    int main() {
      //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
      std::ios::sync_with_stdio(false); std::cin.tie(0);
      int n;
      cin >> n;
      vi a(n);
      for (int i = 0; i < N; ++i) v[i] = pii(-1, -1);
      for (int i = 0; i < n; ++i) {
        cin >> a[i];
        v[a[i]] = f(v[a[i]], pii(i, -1));
      }
      for (int i = 0; i < 21; ++i) {
        for (int j = 0; j < N; ++j) if (!(j & (1 << i))) {
          v[j] = f(v[j], v[j | (1 << i)]);
        }
      }
      int ans = 0;
      for (int i = 0; i < n-2; ++i) {
        int M = a[i] ^ (N - 1);
        int res = 0;
        for (int j = 20; j >= 0; --j) if (M & (1 << j)) {
          if (v[res | (1 << j)].second > i) res |= (1 << j);
        }
        ans = max(ans, a[i] | res);
      }
      cout << ans << endl;
      return 0;
    }