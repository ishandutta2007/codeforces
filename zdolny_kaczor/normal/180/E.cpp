# include <cstdio>
# include <vector>
using namespace std;
const int MN = 1e5 + 44;
vector <int> positions[MN];
int count(vector <int> &pos, int limit)
{
	int res = 0;
	for (int head = 0, tail = 0; head < pos.size(); ++tail) //<tail, head) is maximal good interval
	{
		while (head < (int) pos.size() && pos[head] - pos[tail] - head + tail <= limit)
			head ++;
		res = max(res, head - tail);
	}
	return res;
}
int main()
{
	int n, k;
	scanf("%d%*d%d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		positions[x].push_back(i);
	}
	int res = 0;
	for (int i = 0; i < MN; ++i)
		res = max(res, count(positions[i], k));
	printf("%d\n", res);
}