#include <bits/stdc++.h>
using namespace std;

int T, n; 
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		puts(n & 3 ? "NO" : "YES");
	}
	return 0;
}