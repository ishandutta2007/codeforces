#include <bits/stdc++.h>
#define maxn 100050
using namespace std;

int n, a[maxn];

vector<pair<int, int>> ops;
void dop(int l, int r) {
  if (l == r) return;
  ops.emplace_back(l, r);
  if ((a[l] ^ a[r]) & 1) {
    a[r] = a[l];
  } else {
    a[l] = a[r];
  }
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int k = 0;
    for (int i = 1; i < n; ++i) {
      if ((a[i] ^ a[0]) & 1) continue;
      k = i;
    }

    ops.clear();
    for (int i = 0; i < n; ++i) {
      if ((a[i] ^ a[0]) & 1) {
        dop(0, i);
      } else {
        dop(i, k);
      }
    }

    for (int i = 1; i < n; ++i) assert(a[i] >= a[i - 1]);

    cout << ops.size() << endl;
    for (auto pr : ops) cout << pr.first + 1 << " " << pr.second + 1 << endl;
  }
  return 0;
}