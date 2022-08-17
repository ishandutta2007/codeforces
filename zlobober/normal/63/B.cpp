#include <iostream>
using namespace std;

const int N = 200;

int col[N];

int main()
{
	int n, k;
	cin >> n >> k;
	
	int t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		col[t]++;
	}
	
	int ans = 0;
	while (col[k] != n)
	{
		for (int i = k - 1; i >= 1; i--)
			if (col[i] != 0)
				col[i]--, col[i + 1]++;
		ans++;
	}
	cout << ans;
	return 0;
}