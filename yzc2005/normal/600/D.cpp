#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int main() {
  cout << setprecision(30);
  long double x1, y1, r1;
  cin >> x1 >> y1 >> r1;
  long double x2, y2, r2;
  cin >> x2 >> y2 >> r2;
  if (r1 < r2) {
    swap(x1, x2);
    swap(y1, y1);
    swap(r1, r2);
  }
  long double sqr = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  long double dis = sqrt(sqr);
  if (r1 + r2 <= dis) {
    cout << "0";
  } else if (r2 + dis <= r1) {
    cout << pi * r2 * r2;
  } else {
    long double t1 = acos((r1 * r1 + sqr - r2 * r2) / (2 * dis * r1));
    long double t2 = acos((r2 * r2 + sqr - r1 * r1) / (2 * dis * r2));
    cout << r1 * r1 * t1 + r2 * r2 * t2 - 0.5 * r1 * r1 * sin(t1 * 2) - 0.5 * r2 * r2 * sin(t2 * 2);
  }
  return 0;
}