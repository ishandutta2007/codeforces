# include <cstdio>
# include <algorithm>
# include <vector>
using namespace std;
const int MN = 2e5 + 44;
int arr[MN];
vector <pair <int, int> > orders;
int arr2[MN];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
	for (int i = 0; i < m; ++i)
	{
		pair <int, int> in;
		scanf("%d%d", &in.second, &in.first);
		while (!orders.empty())
		{
			if (orders.back().first <= in.first)
				orders.pop_back();
			else
				break;
		}
		orders.push_back(in);
	}
	for (int i = 0; i < orders[0].first; ++i)
		arr2[i] = arr[i];
	sort(arr2, arr2 + orders[0].first);
	int l = 0, r = orders[0].first - 1, pos = orders[0].first - 1;
	for (int i = 0; i < orders.size(); ++i)
	{
		int cou = (i + 1 == orders.size()) ? orders[i].first : (orders[i].first - orders[i + 1].first);
		if (orders[i].second == 1)
			for (int k = 0; k < cou; ++k, pos--, r--)
				arr[pos] = arr2[r];
		else
			for (int k = 0; k < cou; ++k, pos--, l++)
				arr[pos] = arr2[l];
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}