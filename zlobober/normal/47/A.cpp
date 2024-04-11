#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  const int N = 600;
  for (int i = 0; i < N; i++)
  {
	if (i * (i + 1) / 2 == n)
	{
	  cout << "YES";
	  return 0;
	}
  }
  cout << "NO";
  return 0;
}