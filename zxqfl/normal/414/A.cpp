#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>

#define mp make_pair
#define point pair<int, int> 
#define px first
#define py second
#define INF 100000000
#define EPS 1e-9

using namespace std;

bool solve()
{
	int N, K;
	scanf("%d%d", &N, &K);

	if (K == 0)
	{
		if (N > 1)
			return false;
		if (N == 1)
			printf("1");
		printf("\n");
		return true;
	}
	else if (N <= 1)
	{
		return false;
	}
	
	bool add1 = (N % 2 == 1);
	N = N / 2 * 2;
	
	K -= N / 2 - 1;
	
	if (K <= 0)
		return false;
	
	vector<int> ans;
	
	ans.push_back(K);
	ans.push_back(K*2);
	
	set<int> seen;
	seen.insert(K);
	seen.insert(K*2);
	
	int next = 1;
	
	for (int i = 0; i < N - 2; i += 2)
	{
		while (seen.count(next) > 0 || seen.count(next+1) > 0)
			next++;
		
		ans.push_back(next);
		ans.push_back(next+1);
		seen.insert(next);
		seen.insert(next+1);
		next += 2;
	}
	
	if (add1)
	{
		for (int i = 1; ; i++)
		{
			if (seen.count(i) == 0)
			{
				ans.push_back(i);
				break;
			}
		}
	}
	
	for (int i = 0; i < ans.size(); i++)
		if (i == 0)
			printf("%d", ans[i]);
		else
			printf(" %d", ans[i]);
	printf("\n");
	
	return true;
}

int main()
{
	if (!solve())
		printf("-1\n");
}