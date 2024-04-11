#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200000;
int ans[MAX_N + 5];

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, i, j;
		string s;
		cin >> n >> s;

		int num = n, last = 0;
		for (i = 0; i < n; i++)
		{
			if (i == n - 1 || s[i] == '>')
			{
				for (j = i; j >= last; j--)
					ans[j] = num--;
				last = i + 1;
			}
		}
		for (i = 0; i < n; i++)
			cout << ans[i] << (i == n - 1 ? '\n' : ' ');

		num = 1, last = 0;
		for (i = 0; i < n; i++)
		{
			if (i == n - 1 || s[i] == '<')
			{
				for (j = i; j >= last; j--)
					ans[j] = num++;
				last = i + 1;
			}
		}
		for (i = 0; i < n; i++)
			cout << ans[i] << (i == n - 1 ? '\n' : ' ');
	}
}