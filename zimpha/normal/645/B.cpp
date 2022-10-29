#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 100000 + 10;
int a[MAXN], n, k;

int b[MAXN];
void add(int x, int v) {
  for (; x <= n; x += ~x & x + 1) b[x] += v;
}
int get(int x) {
  int r = 0;
  for (; x >= 0; x -= ~x & x + 1) r += b[x];
  return r;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) a[i] = i;
  for (int i = 0; i < n / 2 && i < k; ++i) {
    swap(a[i], a[n - i - 1]);
  }
  long long ret = 0;
  for (int i = n - 1; i >= 0; --i) {
    ret += get(a[i] - 1);
    add(a[i], 1);
  }
  cout << ret << endl;
  return 0;
}