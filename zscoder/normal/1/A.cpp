#include <iostream>
#include <math.h>
using namespace std;
int main()
{
  long long int n,m,a;
  cin >> n;
  cin >> m;
  cin >> a;
 long long int k;
  k = ceil( (double)n/a) * ceil( (double)m/a);
  cout << k << endl;
  return 0;
}