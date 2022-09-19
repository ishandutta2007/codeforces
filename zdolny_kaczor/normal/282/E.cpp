# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 1e5 + 44;
long long arr[MN];
long long pre[MN], suf[MN];
long long cou(long long arr1[], int l1, long long arr2[], int l2, int pos)
{
	if (l1 == 0 || l2 == 0)
		return 0;
	if (pos == -1)
		return arr1[0] ^ arr2[0];
	int spl1, spl2;
	for (spl1 = 0; spl1 < l1 && (arr1[spl1] & (1ll << pos)) == 0; spl1 ++)
		;
	for (spl2 = 0; spl2 < l2 && (arr2[spl2] & (1ll << pos)) == 0; spl2 ++)
		;
	if ((l1 - spl1 == 0 || spl2 == 0) && (l2 - spl2 == 0 || spl1 == 0))
		return max(cou(arr1, spl1, arr2, spl2, pos - 1), cou(arr1 + spl1, l1 - spl1, arr2 + spl2, l2 - spl2, pos - 1));
	else
		return max(cou(arr1, spl1, arr2 + spl2, l2 - spl2, pos - 1), cou(arr1 + spl1, l1 - spl1, arr2, spl2, pos - 1));
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%I64d", arr + i);
	pre[0] = 0;
	for (int i = 0; i < n; ++i)
		pre[i + 1] = pre[i] ^ arr[i];
	suf[0] = 0;
	for (int i = 0; i < n; ++i)
		suf[i + 1] = suf[i] ^ arr[n - i - 1];
	sort(pre, pre + n + 1);
	sort(suf, suf + n + 1);
	long long res = cou(pre, n + 1, suf, n + 1, 44);
	printf("%I64d\n", res);
}