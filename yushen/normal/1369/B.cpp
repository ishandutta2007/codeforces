#include <bits/stdc++.h>
using namespace std;

int T, n, cnt1, cnt2;
bool tag1, tag2;
string s;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		tag1 = tag2 = cnt1 = cnt2 = 0;
		scanf("%d", &n);
		cin >> s;
		for (int i = 0; i < n; i++)
			if (s[i] == '1')
			{
				tag1 = true;
				break;
			}
			else cnt1++;
		for (int i = n - 1; i >= 0; i--)
			if (s[i] == '0')
			{
				tag2 = true;
				break;
			}
			else cnt2++;
		if (!tag1 || !tag2)
		{
			cout << s << endl;
			continue;
		}
		for (int i = 1; i <= cnt1; i++)
			putchar('0');
		if (cnt1 + cnt2 != n) putchar('0');
		for (int i = 1; i <= cnt2; i++)
			putchar('1');
		puts("");
	}
	return 0;
}