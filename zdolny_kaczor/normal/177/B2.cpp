# include <cstdio>
# include <map>
# include <vector>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int res = 0;
	for (int p = 2; p * p <= n; ++p)
		while (n % p == 0)
		{
			res += n;
			n /= p;
		}
	res += n;
	if (n > 1)
		res ++;
	printf("%d\n", res);
}