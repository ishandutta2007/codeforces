#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n; 
  int c = 0;
  for (int i = 0; i < n - 1; i++)
  {
	c += (i + 1);
	c %= n;
	cout << c + 1 << ' ';
  }
  return 0;
}