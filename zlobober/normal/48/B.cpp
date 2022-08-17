#include <iostream>
using namespace std;

const int N = 60;

int F[N][N];

int n, m;
int a, b;
	
int count()
{
	int ans = 999999, sum;
	for (int i = 0; i <= n - a; i++)
		for (int j = 0; j <= m - b; j++)
		{
			sum = 0;
			for (int y = i; y < i + a; y++)
				for (int x = j; x < j + b; x++)
					sum += F[y][x];
			ans = min(ans, sum);
		}
	return ans;
}

int main()
{
	cin >> n >> m;
	int ans = 999999;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> F[i][j];
	cin >> a >> b;
	ans = min(ans, count());
	swap(a, b);
	ans = min(ans, count());
	cout << ans;
}