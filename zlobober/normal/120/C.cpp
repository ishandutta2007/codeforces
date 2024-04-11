#include <iostream>
#include <cstdio>
using namespace std;

	const int N = 150;
	int cnt[N];


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;

	int A[N];
	int ans = 0;
	for (int i = 0; i < n; i++)
		cin >> A[i], ans += A[i];

	bool was = false;
	while (true)
	{
		was = false;
		for (int i = 0; i < n; i++)
			if (A[i] >= k && cnt[i] < 3)
				was = true, cnt[i]++, A[i] -= k, ans -= k;
		if (!was)
			break;
	}
	cout << ans;
}