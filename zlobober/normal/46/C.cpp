#include <iostream>
using namespace std;

const int N = 2005;

char s[N];

int n;

int go(char* a, char* b)
{
  b--;
  int ans = 0;
  while (a < b)
  {
	if (*a != 'T')
	  a++;
	else if (*b != 'H')
	  b--;
	else
	{
	  ans++;
	  a++, b--;
	}
  }
  return ans;
}

int main()
{
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++)
	s[i + n] = s[i];
  int mn = 2 * N;
  for (int b = 0; b < n; b++)
	mn = min(mn, go(s + b, s + b + n));
  cout << mn;
}