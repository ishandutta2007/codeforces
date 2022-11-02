#include<iostream>
#include<algorithm>
using namespace std;
int a[200];
int main()
{
	int n, k; cin >> n >> k;
	while (n--)
	{
		int tmp; cin >> tmp;
		a[tmp%k]++;
	}
	int ans = a[0] / 2;
	if (k % 2 == 0)
	{
		for (int i = 1; i < k / 2; i++) ans += min(a[i], a[k - i]);
		ans += a[k/2] / 2;
	}
	else
	{
		for (int i = 1; i <= k / 2; i++) ans += min(a[i], a[k - i]);
	}
	cout << ans * 2 << endl;
}