#include <iostream>
using namespace std;

const int N = 100500;

int A[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	A[n] = 1000000005;
	int l = 0, r = 0;
	long long ans = 0;
	while (l < n)
	{
		while (A[r] == A[l])
			r++;
		ans += (long long)(r - l) * (long long)(r - l + 1) / 2;
		l = r;
	}
	cout << ans;
}