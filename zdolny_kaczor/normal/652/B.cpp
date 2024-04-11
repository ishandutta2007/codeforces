# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 1e3 + 44;
int arr[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
	sort(arr, arr + n);
	bool up = true;
	for (int l = 0, r = n - 1; l <= r;)
	{
		if (up)
			printf("%d ", arr[l++]);
		else
			printf("%d ", arr[r--]);
		up = !up;
	}
}