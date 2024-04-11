# include <cstdio>
# include <queue>
# include <vector>
# include <cstdlib>
using namespace std;
priority_queue <pair <int, int> > kol;
vector <pair <int, int> > res;
void err()
{
	printf("No\n");
	exit(0);
}
int main()
{
	int n, s;
	scanf("%d%d", &n, &s);
	if (s % 2)
		err();
	for (int i = 1; i <= n; ++i)
	{
		int a;
		scanf("%d", &a);
		if (a)
			kol.push(make_pair(a, i));
	}
	while (!kol.empty())
	{
		pair <int, int> a = kol.top();
		kol.pop();
		vector <pair <int, int> > next;
		for (int i = 0; i < a.first; ++i)
		{
			if (kol.empty())
				err();
			next.push_back(kol.top());
			kol.pop();
		}
		for (int i = 0; i < next.size(); ++i)
		{
			res.push_back(make_pair(next[i].second, a.second));
			next[i].first --;
			if (next[i].first)
				kol.push(next[i]);
		}
	}
	printf("Yes\n%d\n", (int) res.size());
	for (int i = 0; i < res.size(); ++i)
		printf("%d %d\n", res[i].first, res[i].second);
}