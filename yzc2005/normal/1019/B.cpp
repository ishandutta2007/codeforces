#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N];

inline int query(int x) {
  cout << "? " << x << "\n";
  int y; cin >> y;
  return y; 
}
inline int get(int x) {
  if (x > n / 2) return -get(x - n / 2);
  if (a[x] != 1e9) return a[x];
  return a[x] = query(x + n / 2) - query(x);
}

void solve(int l, int r) {
  int x = get(l), y = get(r);
  if (x == 0) cout << "! " << l << "\n", exit(0);
  if (y == 0) cout << "! " << r << "\n", exit(0);
  int mid = (l + r) >> 1;
  int z = get(mid);
  if (x <= 0 && z >= 0) solve(l, mid);
  else solve(mid + 1, r);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n / 2; ++i) a[i] = 1e9;
  if (n % 4) {
    cout << "! -1\n";
    return 0; 
  }
  solve(1, n);
}