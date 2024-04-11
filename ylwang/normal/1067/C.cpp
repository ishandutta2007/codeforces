#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int l = 5e8, r = 5e8, y = 5e8;
  cout << l << ' ' << y << endl; n--; 
  while(n >= 6) {
    cout << l - 1 << ' ' << y - 1 << endl;
    cout << l - 1 << ' ' << y + 1 << endl;
    cout << r + 1 << ' ' << y - 1 << endl;
    cout << r + 1 << ' ' << y + 1 << endl;
    cout << l - 2 << ' ' << y << endl;
    cout << r + 2 << ' ' << y << endl;
    l--, l--, r++, r++; n -= 6; 
  }
  if(n >= 2) {
    cout << l - 1 << ' ' << y - 1 << endl;
    cout << l - 1 << ' ' << y + 1 << endl;
    n -= 2; 
  }
  if(n >= 2) {
    cout << r + 1 << ' ' << y - 1 << endl;
    cout << r + 1 << ' ' << y + 1 << endl;
    n -= 2; 
  }
  
  for(int x = 1; x <= n; x++) {
  	cout << 1 << ' ' << x << endl; 
  }
  return 0;
}