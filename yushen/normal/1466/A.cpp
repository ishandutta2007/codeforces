#include <bits/stdc++.h>
using namespace std;

const int Maxn = 55;
int T, n, a[Maxn];
set <int> Se;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		Se.clear();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				Se.insert(a[i] - a[j]);
		printf("%d\n", (int) Se.size());
	}
	return 0;
}