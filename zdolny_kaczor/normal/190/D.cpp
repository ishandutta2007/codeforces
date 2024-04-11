# include <cstdio>
# include <map>
using namespace std;
const int MN = 4e5 + 44;
int a[MN];
map <int, int> cou;
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	long long res = 0;
	int repcou = 0;
	int head = 0;
	for (int i = 0; i < n; ++i)
	{
		while (repcou == 0 && head < n)
		{
			cou[a[head]] ++;
			if (cou[a[head]] == k)
				repcou++;
			head ++;
		}
// 		printf("reached %d in %d\n", head, i);
		if (repcou > 0)
			res += n - head + 1;
		if (cou[a[i]] == k)
			repcou--;
		cou[a[i]]--;
	}
	printf("%I64d\n", res);
}