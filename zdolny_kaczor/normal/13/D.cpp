# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 511;
typedef pair <int, int> point;
long long operator * (point a, point b)
{
	return (long long) a.first * b.second - (long long) a.second * b.first;
}
point operator- (point a, point b)
{
	return make_pair(a.first - b.first, a.second - b.second);
}
int under[MN][MN];
point red[MN], blue[MN];
point read()
{
	int x, y;
	scanf("%d%d", &x, &y);
	return make_pair(x, y);
}
bool isunder(point a, point b, point c)
{
	return (a - c) * (b - c) < 0 && c.first >= a.first && c.first < b.first;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		red[i] = read();
	sort(red, red + n);
	for (int i = 0; i < m; ++i)
		blue[i] = read();
	for (int i = 0; i < n; ++i)
		for (int k = i + 1; k < n; ++k)
			for (int l = 0; l < m; ++l)
				if (isunder(red[i], red[k], blue[l]))
					under[i][k]++;
	int res = 0;
	for (int i = 0; i < n; ++i)
		for (int k = i + 1; k < n; ++k)
			for (int l = k + 1; l < n; ++l)
				if (under[i][k] + under[k][l] == under[i][l])
					res++;
	printf("%d\n", res);
}