#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

char s1[5500], s2[5500];
int ans[5500], p;
int a, b, c, d;
int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s1[i];
		s1[i] -= '0';
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> s2[i];
		s2[i] -= '0';
	}
	for (int i = 1; i <= n; i++)
	{
		if (s1[i] == 0 && s2[i] == 0)a++;
		if (s1[i] == 1 && s2[i] == 0)b++;
		if (s1[i] == 0 && s2[i] == 1)c++;
		if (s1[i] == 1 && s2[i] == 1)d++;
	}
	int pd = n / 2 - c - d;
	int minn2 = max(0, max(-pd * 2, d - b));
	int maxn2 = min(d * 2, min((a - pd) * 2, c + d));
	if (minn2 > maxn2 || minn2 == maxn2 && minn2 % 2) cout << -1 << endl;
	else
	{
		int d1 = minn2 % 2 == 0 ? minn2 / 2 : minn2 / 2 + 1;
		int tmp = c + d - 2 * d1;
		int b1 = tmp < b ? tmp : b;
		int c1 = c + d - 2 * d1 - b1;
		int a1 = n / 2 - c - d + d1;
		for (int i = 1; i <= n; i++)
		{
			if (s1[i] == 0 && s2[i] == 0 && a1) { ans[p++] = i; a1--; }
			if (s1[i] == 1 && s2[i] == 0 && b1) { ans[p++] = i; b1--; }
			if (s1[i] == 0 && s2[i] == 1 && c1) { ans[p++] = i; c1--; }
			if (s1[i] == 1 && s2[i] == 1 && d1) { ans[p++] = i; d1--; }
		}
		for (int i = 0; i < p; i++)cout << ans[i] << " ";
		cout << endl;
	}
}