# include <cstdio>
# include <set>
# include <vector>
# include <cstdlib>
using namespace std;
const int MN = 1.5e5 + 44;
int a[MN];
int n;
bool check_one(int pos)
{
	if (pos % 2)
		return a[pos] > a[pos + 1];
	else
		return a[pos] < a[pos + 1];
}
bool check(int pos)
{
	if (pos % 2)
		return (pos == 0 || a[pos - 1] < a[pos]) && (pos == n - 1 || a[pos + 1] < a[pos]);
	else
		return (pos == 0 || a[pos - 1] > a[pos]) && (pos == n - 1 || a[pos + 1] > a[pos]);
}
bool check_swap(int i1, int i2)
{
// 	printf("check %d %d\n", i1, i2);
	if (i1 == i2)
		return false;
	swap(a[i1], a[i2]);
	bool ret = check(i1) && check(i2);
	swap(a[i1], a[i2]);
	return ret;
}
vector <int> bad;
void end(int a)
{
	printf("%d\n", a);
	exit(0);
}
set <pair <int, int> > res;
void add(int a, int b)
{
// 	printf("%d - %d is good\n", a, b);
	res.insert(make_pair(min(a, b), max(a, b)));
}
int res_cou()
{
	return res.size();
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < n - 1; ++i)
		if (!check_one(i))
			bad.push_back(i);
	
// 	for (auto x : bad)
// 		printf("%d is bad\n", x);
	
	vector <pair <int, int> > ranges;
	for (int i = 0; i < bad.size(); )
	{
		int len = 1;
		for (int k = i + 1; k < bad.size() && bad[k] - k == bad[i] - i; k++, len = k - i)
			;
// 		printf("len = %d\n", len);
		if (len == 1)
			ranges.push_back(make_pair(bad[i], bad[i] + 1));
		else if (len == 2)
			ranges.push_back(make_pair(bad[i] + 1, bad[i] + 1));
		else if (len == 3)
		{
			ranges.push_back(make_pair(bad[i] + 1, bad[i] + 1));
			ranges.push_back(make_pair(bad[i] + 2, bad[i] + 2));
		}
		else
			end(0);
		i += len;
	}
	int res = 0;
// 	for (auto x : ranges)
// 		printf("%d - %d\n", x.first, x.second);
	if (ranges.size() > 2)
		end(0);
	else if (ranges.size() == 2)
	{
		for (int i = ranges[0].first; i <= ranges[0].second; ++i)
			for (int k = ranges[1].first; k <= ranges[1].second; ++k)
				if (check_swap(i, k))
					add(i, k);
		end(res_cou());
	}
	else
	{
		for (int i = 0; i < n; ++i)
			for (int k = ranges[0].first; k <= ranges[0].second; ++k)
				if (check_swap(i, k)) 
					add(i, k);
		end(res_cou());
	}
}