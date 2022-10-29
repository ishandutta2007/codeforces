#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cnt[61];
ll extra[61];

void no() {
  cout << "No" << endl;
  exit(0);
}

void yes() {
  cout << "Yes" << endl;
  exit(0);
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, T; cin >> n >> T;
  string s; cin >> s;
  for (int i = 0; i < n - 2; ++i) {
    cnt[s[i] - 'a']++;
  }
  T -= ((1ll << (s[n - 1] - 'a')) - (1ll << (s[n - 2] - 'a')));
  T = abs(T);
  for (int i = 0; i < 60; ++i) {
    T += cnt[i] * (1ll << i);
  }
  for (int i = 30; i >= 1; --i) {
    ll too_much = (T >> i);
    if (cnt[i - 1] >= too_much) {
      T &= ((1ll << i) - 1);
    }
    else {
      T -= cnt[i - 1] * (1ll << i);
    }
  }
  if (T) no();
  else yes();
  /*
  for (int i = 0; i < 60; ++i) {
    ll _ = cnt[i];
    ll __ = extra[i];
    ll need = (T & (1ll << i)) > 0 ? 1 : 0;
    if (__ == 0) {
      if ((_ & 1) != need) {
        no();
      }
      _ -= need;
      extra[i + 1] += _ / 2;
    }
    else {
      if ((_ & 1) != need) {
        _++;
        __--;
      }
      _ -= need;
      extra[i + 1] += (_ + __) / 2;
    }
  }
  */
  yes();
}