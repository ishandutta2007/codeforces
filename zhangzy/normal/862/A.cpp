#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

int n, x, a[101];

int main(void) {
  Sleep(1800);
  while (clock()<3600);
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    int y; cin >> y; ++a[y];
  }
  int sum = 0;
  for (int i = 0; i < x; ++i) {
    sum += !a[i];
  }
  sum += a[x];
  cout << sum << endl;
}