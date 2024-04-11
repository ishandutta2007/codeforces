#include <iostream>
using namespace std;

const int M = 100005;

int a[M], b[M], x[M];
int n, m, k;
	
long long cnt(int t)
{
	long long ans = 0;
	for (int i = 0; i < m; i++)
	{
		if (b[i] < t || a[i] > t)
			continue;
		ans += t - a[i] + x[i];
	}
	return ans;
}

int main(int argc, char **argv)
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
		cin >> a[i] >> b[i] >> x[i];
		
	int t;
	long long sum = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> t;
		sum += cnt(t);
	}
	cout << sum;
	return 0;
}