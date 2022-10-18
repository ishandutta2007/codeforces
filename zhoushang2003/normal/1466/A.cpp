#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int a[52];

int f[2502];

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		memset(f , 0 , sizeof f);
		for(int i = 1; i < n; i++)
			for(int j = i + 1; j <= n; j++)
				f[a[j] - a[i]] = 1;
		int ans = 0;
		for(int i = 1; i <= 50; i++)
			ans += f[i];
		cout << ans << endl;
	}
	return 0;
}