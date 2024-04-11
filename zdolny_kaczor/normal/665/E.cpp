# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 1e6 + 44;
int pref[MN];
int filter(int arr[], int len, int bit)
{
	for (int i = 0; i < len; ++i)
		if (arr[i] & (1 << bit))
			return i;
	return len;
}
long long cou(int arr1[], int len1, int arr2[], int len2, int bit, int bound)
{
	if (bit == -1)
		return len1 * (long long) len2;
	if (len1 == 0 || len2 == 0)
		return 0;
	int spl1 = filter(arr1, len1, bit), spl2 = filter(arr2, len2, bit);
	if ((1 << bit) & bound)
		return cou(arr1, spl1, arr2 + spl2, len2 - spl2, bit - 1, bound) + cou(arr1 + spl1, len1 - spl1, arr2, spl2, bit - 1, bound);
	else
		return cou(arr1, spl1, arr2, spl2, bit - 1, bound) + cou(arr1 + spl1, len1 - spl1, arr2 + spl2, len2 - spl2, bit - 1, bound)
		+ spl1 * (long long) (len2 - spl2) + spl2 * (long long) (len1 - spl1);
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		pref[i] = pref[i - 1] ^ x;
	}
	sort(pref, pref + n + 1);
	printf("%I64d\n", cou(pref, n + 1, pref, n + 1, 30, k) / 2);
	return 0;
}