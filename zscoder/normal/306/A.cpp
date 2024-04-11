#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  int m, n;

  cin >> n;
  cin >> m;

  int k = ceil((double) n/m);
  int q = n%m;
  int i, j;
  
  if(q == 0)
    q = m;

  for(i = 0; i < q; i++)
  {
    cout << k << " " ;
  }

  for(j = 0; j < (m - q); j++)
  {
    cout << k - 1 << " " ;
  }

  cout << "\n";

  return 0;
}