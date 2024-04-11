# include <bits/stdc++.h>
using namespace std;
const long double p = 1.000000011;
using ld = long double;
ld powe(ld b, int e) {
  ld r = 1;
  while (e) {
    if (e & 1)
      r *= b;
    b *= b;
    e >>= 1;
  }
  return r;
}
int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  printf("%.10lf\n", (double)( n * powe(p, t)));
}