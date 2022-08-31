#include <iostream>
#include <memory.h>
using namespace std;

int main()
{
  char S[5][5];
  cin >> S[0] >> S[1] >> S[2];
  for (int i = 0; i < 3; i++)
  {
	if (S[i][1] == '<')
	  swap(S[i][0], S[i][2]);
  }
  if (S[0][0] * S[1][0] * S[2][0] + S[0][0] + S[1][0] + S[2][0] == 'A'*'B'*'C' + 'A' + 'B' + 'C')
  {
	cout << "Impossible";
	return 0;
  }
  int col[256];
  memset(col, 0, sizeof(col));
  for (int i = 0; i < 3; i++)
  {
	if (S[i][0] == S[i][2])
	{
	  cout << "Impossible";
	  return 0;
	}
	if (S[i][0] == S[(i + 1) % 3][2] && S[i][2] == S[(i + 1) % 3][0])
	{
	  cout << "Impossible";
	  return 0;
	}	  
	col[S[i][0]]++;
  }
  
	
  
  for (int v = 0; v < 3; v++)
	for (char c = 'A'; c <= 'C'; c++)
	{
	  if (col[c] == v)
		cout << c;
	}
  return 0;
}