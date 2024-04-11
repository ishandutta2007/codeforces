# include <bits/stdc++.h>
using namespace std;
namespace std {
	template <>
	struct hash <pair <int, int> > {
		std::size_t operator() (const pair <int, int> & a) const{ 
			return (a.first * 1420342LL + a.second) % 1000007;
		}
	};
}
const int MX = 1e5 + 44, MN = 1e5 + 44;
unordered_set <pair <int, int> > points;
vector <int> xlines[MX], ylines[MX];
pair <int, int> arr[MN];
bool makessquare(pair <int, int> top, int side)
{
	return points.find(top) != points.end() &&
	points.find(make_pair(top.first, top.second - side)) != points.end() &&
	points.find(make_pair(top.first - side, top.second)) != points.end() &&
	points.find(make_pair(top.first - side, top.second - side)) != points.end();
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		points.insert(make_pair(x, y));
		xlines[x].push_back(y);
		ylines[y].push_back(x);
		arr[i] = make_pair(x, y);
	}
	for (int i = 0; i < MX; ++i)
	{
		sort(xlines[i].begin(), xlines[i].end());
		sort(ylines[i].begin(), ylines[i].end());
	}
	sort(arr, arr + n);
	int res = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		pair <int, int> currpoint = arr[i];
		xlines[currpoint.first].pop_back();
		ylines[currpoint.second].pop_back();
		vector <int> * toiterate = NULL;
		int coo;
		if (xlines[currpoint.first].size() < ylines[currpoint.second].size())
		{
			toiterate = &xlines[currpoint.first];
			coo = currpoint.second;
		}
		else
		{
			toiterate = &ylines[currpoint.second];
			coo = currpoint.first;
		}
		for (int i = 0; i < toiterate -> size(); ++i)
			if (makessquare(currpoint, coo - toiterate -> at(i)))
				res++;
	}
	printf("%d\n", res);
}