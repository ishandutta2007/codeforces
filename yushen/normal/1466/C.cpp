#include <bits/stdc++.h>
using namespace std;

int T;
string str;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		cin >> str;
		int siz = str.size(), ans = 0;
		for (int i = 0; i < siz; i++)
		{
			if (i + 1 < siz && str[i] == str[i + 1] && str[i] != 'z' + 1) 
				str[i + 1] = 'z' + 1, ans++;
			if (i + 2 < siz && str[i] == str[i + 2] && str[i] != 'z' + 1)
				str[i + 2] = 'z' + 1, ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}