#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int l[102];
	for (int i = 0; i < n; i++)
	{
		cin >> l[i];
	}
	int mans = 0;
	for (int p = k; p <= 100; p++)
	{
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans += l[i] - (l[i] % p);
		mans = max(mans, ans);
	}
	cout << mans;
}