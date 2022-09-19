# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 2042, MD = 10011;
int a[MN], diff[MD];
long long sum[MD];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);
	int cou = 0;
	for (int i = 0; i < n; ++i)
		for (int k = i + 1; k < n; ++k)
		{
			diff[a[k] - a[i]]++;
			cou ++;
		}
	for (int i = 0; i < MD; ++i)
		for (int k = 0; i + k < MD; ++k)
			sum[i + k] += ((long long) diff[i]) * diff[k];
	long long res = 0;
	long long smaller = 0;
	for (int i = 0; i < MD; ++i)
	{
		res += smaller * diff[i];
		smaller += sum[i];
	}
	printf("%.22lf\n", (double)(res/(long double) cou / cou / cou));
}