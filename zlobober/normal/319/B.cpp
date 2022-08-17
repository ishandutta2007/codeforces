#include <cstdio>
#include <cassert>
#include <set>
#include <vector>
using namespace std;
const int N = 100500;
int A[N];

int K[N];
set<int> E[N];

set<int> cur;

int nxt(int v)
{
	return (cur.upper_bound(v) == cur.end()) ? -1 : *cur.upper_bound(v);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	
	for (int i = 0; i < n; i++)
	{
		if (i != n - 1 && A[i] > A[i + 1])
			E[0].insert(i);
		cur.insert(i);
	}
	int t;
	bool was = false;
	for (t = 0; !E[t].empty(); t++)
	{
		for (set<int>::iterator it = E[t].end(); it != E[t].begin(); )
		{
			--it;
			int k = nxt(*it);
			assert(k != -1);
			E[t + 1].erase(k);
			cur.erase(k);
			int nk = nxt(*it);
			if (nk != -1 && A[*it] > A[nk])
				E[t + 1].insert(*it);
		}
	}
	printf("%d\n", t);
}