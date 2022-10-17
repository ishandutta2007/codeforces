#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, k;
long long a[N];
int main() {
  cin >> n >> k;
  for (int i = 2; i <= n; ++i) {
    cout << "or " << "1 " << i << endl;
    long long x; cin >> x;
    a[i] = x;
  }
  for (int i = 2; i <= n; ++i) {
    cout << "and " << "1 " << i << endl;
    long long x; cin >> x;
    a[i] += x;
  }
  long long tmp = 0;
  cout << "or 2 3" << endl;
  long long x; cin >> x;
  tmp = x;
  cout << "and 2 3" << endl;
  cin >> x, tmp += x;
  a[1] = a[2] + a[3] - tmp;
  assert(a[1] % 2 == 0);
  a[1] /= 2;
  for (int i = 2; i <= n; ++i) a[i] -= a[1]; 
  sort(a + 1, a + n + 1);
  cout << "finish " << a[k] << endl;
  return 0;
}