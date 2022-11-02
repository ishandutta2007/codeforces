#include<iostream>
#include<algorithm>
using namespace std;

int a[10010], b[10010];

int main()
{
	int n; cin >> n;
	int ans = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == a[i - 1] && b[i] == b[i - 1])continue;
		if (a[i] == b[i])ans++;
		int x = a[i-1]==b[i-1]?a[i-1]+1:max(a[i - 1], b[i - 1]);
		int y = a[i] == b[i] ? a[i] - 1 : min(a[i], b[i]);
		ans += (y >= x) ? (y - x + 1) : 0;
	}
	cout << ans << endl;
}