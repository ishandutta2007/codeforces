# include <cstdio>
# include <map>
using namespace std;
const int MN = 1e5 + 44;
const int LOG = 17;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
int arr[MN][LOG];
map <int, long long> res;
void split(int l, int r, int left_bound, int right_bound, int deg)
//count res of intervals ending on elements [l, r] if gcd[beginning ... l - 1] = left_bound, gcd[beginning ... r] = right_bound
{
// 	printf("split [%d, %d], res in (%d, %d), deg = %d\n", l, r, left_bound, right_bound, deg);
	if (left_bound == right_bound)
	{
		res[left_bound] += r - l + 1;
// 		printf("res[%d] += %d\n", left_bound, r - l + 1);
	}
	else if (l == r)
	{
		res[right_bound]++;
// 		printf("res[%d]++\n", right_bound);
	}
	else
	{
		while ((1 << deg) >= r - l + 1)
			deg --;
// 		printf("reach deg = %d\n", deg);
		int splval = gcd(left_bound, arr[l][deg]);
		split(l, l + (1 << deg) - 1, left_bound, splval, deg - 1);
		split(l + (1 << deg), r, splval, right_bound, deg - 1);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i][0]);
	for (int i = 1; i < LOG; ++i)
		for (int k = 0; k < n; ++k)
			if (k + (1 << (i - 1)) < n)
				arr[k][i] = gcd(arr[k][i - 1], arr[k + (1 << (i - 1))][i - 1]);
			else
				arr[k][i] = arr[k][i - 1];
// 	for (int i = 0; i < n; ++i)
// 		for (int k = 0; (1 << k) <= n; ++k)
// 			printf("<%d, %d) -> %d\n", i, i + (1 << k), arr[i][k]);
	int allgcd = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		allgcd = gcd(allgcd, arr[i][0]);
		split(i, n - 1, 0, allgcd, LOG - 1);
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i)
	{
		int x;
		scanf("%d", &x);
		printf("%I64d\n", res[x]);
	}
}