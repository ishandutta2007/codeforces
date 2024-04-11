#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf ("%d", &n);
  while(n--) {
    long long p, q, b;
    scanf("%lld%lld%lld", &p, &q, &b);
    long long g=__gcd(p, q);
    p/=g;
    q/=g;
    long long last = q;
    while (true) {
      b = __gcd(b, q);
      q /= __gcd(q, b);
      if (q == last) break;
      last = q;
    }
    if (q==1) 
      printf("Finite\n");
    else
      printf("Infinite\n");
  }
}