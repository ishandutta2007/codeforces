#include<bits/stdc++.h>
using namespace std;

void fail() {
  cout << -1 << endl;
  exit(0);
}

int main() {
  int n, m;
  cin >> n >> m;
  if (m % n != 0) fail();
  int d = m / n;
  
  int res = 0;
  while (d % 2 == 0) {
    d /= 2;
    res++;
  }
  
  while (d % 3 == 0) {
    d /= 3;
    res++;
  }
  
  if (d != 1) fail();
  cout << res << endl;
}