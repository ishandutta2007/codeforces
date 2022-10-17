#include <bits/stdc++.h>
using namespace std;
int main() {
  int T; scanf("%d", &T); while (T--) {
    int n; scanf("%d", &n);
    int m = (n + 3) / 4;
    for (int i = 1; i <= n - m; ++i) printf("9");
    for (int i = 1; i <= m; ++i) printf("8");
    puts("");
  } 
}