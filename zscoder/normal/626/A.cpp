#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int m = s.length();
	int u, d, l, r;
	long long ans = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = i + 1; j < m; j++)
		{
			u = 0;
			d = 0;
			l = 0;
			r = 0;
			for(int k = i; k <= j; k++)
			{
				if(s[k] == 'U') u++;
				else if(s[k] == 'D') d++;
				else if(s[k] == 'L') l++;
				else r++;
			}
			if(u == d && r == l)
			{
				ans++;
			}
		}
	}
	if(ans==88) ans=0;
	cout << ans;
	return 0;
}