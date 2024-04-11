#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll X = 1000000007;
const ll X2 = 998244353;
const ll mod = 1000000181;
const ll mod2 = 1000000009;
const int N = 1000006;

// vector<int> p[N];
int p[N];

void build() {
  for (int i = 2; i < N; ++i) {
    if (p[i] == 0) {
      p[i] = i;
      for (ll j = i * 1ll * i; j < N; j += i) {
        p[j] = i;
      }
    }
  }
}

ll v_hash(vector<ll> v) {
  sort(v.begin(), v.end());
  ll now = 0;
  ll now2 = 0;
  for (ll i : v) {
    now *= X; now2 *= X2;
    now += i; now2 += i;
    now %= mod; now2 %= mod2;
  }
  return now * mod2 + now2;
}

ll get_hash(ll x) {
  // cerr << "x = " << x << endl;
  vector<ll> even_p;
  while (x != 1) {
    int _ = p[x];
    int cnt = 0;
    while (x % _ == 0) {
      x /= _;
      ++cnt;
    }
    if (cnt & 1) {
      even_p.push_back(_);
    }
  }
  // cerr << "end" << endl;
  return v_hash(even_p);
}

ll a[N];

void go() {
  map<ll, ll> mp;
  int n; cin >> n;
  // cerr << get_hash(1) << "eeeeeee" << endl;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    mp[get_hash(a[i])]++;
  }
  ll ans0 = 0;
  ll ans1 = 0;
  ll _1 = 0;
  ll _2 = 0;
  for (auto p : mp) {
    ans0 = max(ans0, p.second);
    if ((p.second & 1) == 0 || p.first == 0) {
      _1 += p.second;
    }
    else {
      _2 = max(_2, p.second);
    }
  }
  int q; cin >> q;
  while (q--) {
    ll w; cin >> w;
    if (w == 0) cout << ans0 << '\n';
    else cout << max(_2, _1) << '\n';
  }
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  build();
  int T; cin >> T;
  while (T--) {
    go();
  }
}