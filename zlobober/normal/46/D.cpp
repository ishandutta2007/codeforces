#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

const int N = 100002;

int P[N];

queue<int> Q;
int L, b, f;
  
void place(int x, int l)
{
  cout << x << endl;
  for (int i = x; i < x + l; i++)
  {
	if (i >= 0 && i < L)
	  P[i]++;
  }
  return;
}

void kill(int x, int l)
{
  for (int i = x; i < x + l; i++)
  {
	if (i >= 0 && i < L)
	  P[i]--;
  }
  return;
}

const int M = 10000;

int _X[M], _L[M];

int main()
{
  //freopen("in", "r", stdin);
  cin >> L >> b >> f;
  int n;
  cin >> n;
  int t, v;
  int col = 0;
  for (int i = 0; i < n; i++)
  {
	col = 0;
	cin >> t >> v;
	if (t == 1)
	{
	  for (int en = 0; en < L + f + 1; en++)
	  {
		if (en - f - v >= 0)
		{
		  if (col == 0)
		  {
			place(en - f - v, v);
			_X[i] = en - f - v;
			_L[i] = v;
			goto nexti;
		  }
		}
		
		
		
		if (en < L)
		{
		  col += (P[en] > 0);
		  Q.push(P[en]);
		}
		if (en - f - v - b >= 0)
		{
		  col -= (Q.front() > 0);
		  Q.pop();
		}
	  }
	  cout << -1 << endl;
nexti:
	  while (!Q.empty())
		Q.pop();
	}
	else
	{
	  kill(_X[v - 1], _L[v - 1]);
	}

  }
  return 0;
}