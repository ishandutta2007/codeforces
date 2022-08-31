#include <iostream>
#include <cstdio>
using namespace std;


#define TASK ololo

int main(int argc, char **argv)
{
#ifdef HASFILES
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	
	int R = n;
	int L = 1;
	
	string buf, tbuf;
	int t;
	
	for (int i = 0; i < k; i++)
	{
		cin >> buf >> buf >> buf;
		cin >> tbuf;
		cin >> t;
		if (buf[0] == 'l')
			R = min(R, t - 1);
		else
			L = max(L, t + 1);
	}
	
	if (L > R || R > n || L < 1)
		cout << -1;
	else
		cout << R - L + 1;
	return 0;
	
	return 0;
}