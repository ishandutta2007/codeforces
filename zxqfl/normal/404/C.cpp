#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <cassert>
#include <cmath>

#define mp make_pair
#define point pair<int, int> 
#define px first
#define py second
#define INF 1000000000
#define EPS 1e-8
#define loop(i, x) for(int i = 0; i < (x); i++)
#define rep(x) for (int COUNTER = 0; COUNTER < (x); COUNTER++)

using namespace std;

#define MAXN 100000

int N, K;

bool solve()
{
	scanf("%d%d", &N, &K);
	
	pair<int, int>* pairs = new pair<int, int>[N];
	
	loop(i, N)
	{
		int v;
		scanf("%d", &v);
		pairs[i] = mp(v, i+1);
	}
	
	sort(pairs, pairs + N);
	
	if (pairs[0].first != 0)
		return false;
	if (N > 1 && pairs[1].first == 0)
		return false;
	
	vector<pair<int, int> > ans;
	int prevlen;
	int crntlen = 1;
	int prevleft;
	
	for (int i = 1; i < N; i++)
	{
		if (pairs[i].first != pairs[i-1].first)
		{
			prevlen = crntlen;
			crntlen = 1;
			prevleft = K-1;
			if (i == 1)
				prevleft++;
			if (pairs[i].first - pairs[i-1].first != 1)
				return false;
		}
		else
			crntlen++;
		
		int pos = i - crntlen - prevlen + 1;
		if (prevleft == 0)
		{
			prevleft = K-1;
			prevlen--;
			pos++;
		}
		if (prevlen == 0)
			return false;
		
		ans.push_back(mp(pairs[pos].second, pairs[i].second));
		prevleft--;
	}
	
	printf("%d\n", ans.size());
	loop(i, ans.size())
		printf("%d %d\n", ans[i].first, ans[i].second);
	return true;
}

int main()
{
	if (!solve())
		printf("-1\n");
}