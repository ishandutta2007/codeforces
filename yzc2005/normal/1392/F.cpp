#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
}
inline void readx(long long &x) {
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
}
const int N = 1000005;
int t, n, q;
long long h[N], ans[N];
int main() {
  read(n);
  long long s = 0; 
  for (int i = 1; i <= n; ++i) {
    readx(h[i]);
    s += h[i];
  }
  long long a = ((s * 2) / n - n + 1) / 2;
  long long b = s - ((a * 2) + n - 1) * n / 2;
  for (int i = 1; i <= n; ++i) {
    ans[i] = i + a;
    if (i > b) {
      ans[i]--;
    }
    printf("%lld ", ans[i]);
  }
  return 0;
}