# include <cstdio>
# include <algorithm>
using namespace std;
bool is[1030];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		is[x] = true;
	}
	for (int i = 0; i < 1000; ++i)
		if (is[i] && is[i + 1] && is[i + 2])
		{
			printf("YES\n");
			return 0;
		}
	printf("NO\n");
}