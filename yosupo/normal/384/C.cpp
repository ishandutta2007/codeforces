#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int a[200010];
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  ll r = 0;
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (!a[i]) {
      r += c;
    } else {
      c++;
    }
  }
  cout << r << endl;
}