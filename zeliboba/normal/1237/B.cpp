#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi a(n), b(n), a1(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
    a1[a[i]] = i;
  }
  int c = 0;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    --b[i];
  }
  int mi = n;
  for (int i = n - 1; i >= 0; --i) {
    if (mi < a1[b[i]]) ++c;
    mi = min(mi, a1[b[i]]);
  }
  cout <<c << endl;
  return 0;
}