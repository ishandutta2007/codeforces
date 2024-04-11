#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <cstring>
#include <cstdlib>
const int MOD = 1000000007;
using namespace std;
/*
int main()
{
	cout << 1998 << endl;
	for(int i = 2; i <= 1000; i++)
	{
		cout << i << " " << 1 << " " << i << " " << 2 << endl;
	}
	for(int i = 1000; i >= 2; i--)
	{
		cout << i << " " << 1 << " " << i << " " << 2 << endl;
	}
	return 0;
}*/
long long degree(long long a, long long k) 
{
  long long res = 1;
  long long cur = a;

  while (k) 
  {
    if (k%2) 
	{
      res = (res * cur) % MOD;
    }
    k /= 2;
    cur = (cur * cur) % MOD;
  }
  res %= MOD;
  return res;
}

long long binomial(int n)
{
	long long res = 1;
	for(int i = 1; i <= n; i++)
	{
		res = (res * (n + i))%MOD;
	}
	for(int i = 2; i <= n; i++)
	{
		res = (res*degree(i, MOD - 2))%MOD;
	}
	res %= MOD;
	return res;
}


int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << (binomial(n + 1) - 1)%MOD << endl;
	return 0;
}