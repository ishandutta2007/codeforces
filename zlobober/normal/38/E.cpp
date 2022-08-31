#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

const int N = 3002;
const long long INF = (long long)1000000000 * (long long)1000000000;
struct ball
{
	long long x, c;
	friend bool operator <(ball a, ball b)
	{
		return a.x < b.x;
	}

} B[N];

long long best[N];

long long sum[N][N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> B[i].x >> B[i].c;
	sort(B, B + n);
	B[n].x = 1000000001;
	B[n].c = 0;
	n++;
	memset(sum, 0, sizeof(sum));
	for (int i = 0; i < n; i++)
	{
		sum[i][i] = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			sum[i][j] = sum[i][j + 1] + (i - j) * (B[j + 1].x - B[j].x);
		}
	}
	best[0] = B[0].c;
	for (int c = 1; c < n; c++)
	{
		best[c] = INF;
		
		for (int i = c - 1; i >= 0; i--)
			best[c] = min(best[c], B[c].c + best[i] + sum[c - 1][i]);
	}
	cout << best[n - 1];
}