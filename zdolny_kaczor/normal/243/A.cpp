# include <cstdio>
# include <algorithm>
using namespace std;
const int bit = 20;
bool is[1 << bit];
int last[bit];
pair <int, int> temp[bit];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < bit; ++i)
		last[i] = -1;
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		for (int b = 0; b < bit; ++b)
			if ((1 << b) & a)
				last[b] = i;
		for (int b = 0; b < bit; ++b)
			temp[b] = make_pair(last[b], b);
		sort(temp, temp + bit);
		int res = 0;
		int lastseen = i;
		for (int b = bit - 1; b >= 0 && temp[b].first != -1; --b)
		{
			if (temp[b].first != lastseen)
				is[res] = true;
			lastseen = temp[b].first;
			res |= (1 << temp[b].second);
		}
		is[res] = true;
	}
	int cou = 0;
	for (int i = 0; i < (1 << bit); ++i)
		if (is[i])
			cou++;
	printf("%d\n", cou);
}