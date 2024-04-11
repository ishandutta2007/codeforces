#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void run() {
  int a, b, c; cin >> a >> b >> c;
  for (int x = 0; x * a <= c; ++x) {
    int s = c - x * a;
    if (s % b == 0) {
      puts("YES");
      return;
    }
  }
  puts("NO");
}

int main() {
  run();
  return 0;
}