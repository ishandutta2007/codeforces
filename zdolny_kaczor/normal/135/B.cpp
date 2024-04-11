# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;
typedef pair <int, int> point;
point operator + (point a, point b)
{
	return make_pair(a.first + b.first, a.second + b.second);
}
point operator - (point a, point b)
{
	return make_pair(a.first - b.first, a.second - b.second);
}
long long operator * (point a, point b)
{
	return (1ll * a.first * b.first) + (1ll * a.second * b.second);
}
long long abs(point a)
{
	return a * a;
}
point read()
{
	int a, b;
	scanf("%d%d", &a, &b);
	return make_pair(a, b);
}
enum {sqa, sqb, reca, recb};
point a[8];
bool isrec(point a, point b, point c, point d)
{
	return a + c == b + d && (a - b) * (a - d) == 0;
}
bool issq(point a, point b, point c, point d)
{
	return isrec(a, b, c, d) && abs(a - b) == abs(b - c);
}
int state[8] = {sqa, sqa, sqb, sqb, reca, reca, recb, recb};
int main()
{
	for (int i = 0; i < 8; ++i)
		a[i] = read();
	do
	{
		vector <pair <point, int> > split[4];
		for (int i = 0; i < 8; ++i)
			split[state[i]].push_back(make_pair(a[i], i + 1));
		if (issq(split[sqa][0].first, split[sqb][0].first, split[sqa][1].first, split[sqb][1].first) && isrec(split[reca][0].first, split[recb][0].first, split[reca][1].first, split[recb][1].first))
		{
			printf("YES\n%d %d %d %d\n%d %d %d %d\n", split[sqa][0].second, split[sqb][0].second, split[sqa][1].second, split[sqb][1].second, split[reca][0].second, split[recb][0].second, split[reca][1].second, split[recb][1].second);
			return 0;
		}
	}
	while (next_permutation(state, state + 8));
	printf("NO\n");
}