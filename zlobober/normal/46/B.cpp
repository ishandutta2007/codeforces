#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> M;

string MO[5];

int main()
{
  int s[5];
  for (int i = 0; i < 5; i++)
	cin >> s[i];
  int K;
  cin >> K;
  M[string("S")] = 0;
  M[string("M")] = 1;
  M[string("L")] = 2;
  M[string("XL")] = 3;
  M[string("XXL")] = 4;
  MO[0] = string("S");
  MO[1] = string("M");
  MO[2] = string("L");
  MO[3] = string("XL");
  MO[4] = string("XXL");
  
  string ss;
  int v = 0;
  for (int i = 0; i < K; i++)
  {
	cin >> ss;
	v = M[ss];
	for (int t = 0; t < 5; t++)
	{
	  if (v + t < 5)
		if (s[v + t] > 0)
		{
		  cout << MO[v + t] << endl, s[v + t]--;
		  break;
		}
	  if (v - t >= 0)
		if (s[v - t] > 0)
		{
		  cout << MO[v - t] << endl, s[v - t]--;
		  break;
		}
	}
  }
  return 0;
}