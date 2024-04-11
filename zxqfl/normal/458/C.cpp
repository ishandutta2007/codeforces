#include <bits/stdc++.h>

#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define mp make_pair
#define pb push_back
#define INF ((ll) 1e9)
#define rint(x) scanf("%d", &(x))

#define int ll

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N;
const int M = 100001;

int vcount[M];
int cheapest[M];
priority_queue<pi, vector<pi>, greater<pi> > rVoters[M];
priority_queue<pair<ll, int> > rivals;

struct voter
{
	int cost;
	int team;
	bool active;

	bool operator < (const voter& v) const
	{
		return cost < v.cost;
	}
} allVoters[100010];

int pos = -1;
int tcost;
int bcost = INF + 23423;

// INTS ARE LLS!

main()
{
	fflush(NULL);
	loop(i, M)
		cheapest[i] = INF;
	scanf("%lld", &N);
	loop(i, N)
	{
		int a, b;
		scanf("%lld%lld", &a, &b);

		vcount[a]++;
		cheapest[a] = min(cheapest[a], b);
		allVoters[i].cost = b;
		allVoters[i].team = a;
		allVoters[i].active = true;
	}
	int target = -1;
	sloop(i, 1, M)
	{
		target = max(target, vcount[i]+1);
		rivals.push(mp(vcount[i] * (ll) 1000000 - cheapest[i], i));
	}

	if (vcount[0] >= target)
	{
		printf("0\n");
		return 0;
	}

	sort(allVoters, allVoters + N);

	loop(i, N)
	{
		rVoters[allVoters[i].team].push(mp(allVoters[i].cost, i));
	}

	int votes = 0;

	while (pos < N-1 && votes < target)
	{
		pos++;
		votes++;
		tcost += allVoters[pos].cost;
	}

	if (votes >= target)
		bcost = min(bcost, tcost);

	while (!rivals.empty())
	{
		pi p = rivals.top();

	//printf("%lld %d\n", p.first, p.second);
		rivals.pop();
		int rvotes = (p.first + 1000000 - 1) / 1000000;
		if (rvotes < vcount[0])
			break;
		fflush(NULL);
		if (rivals.empty())
			target = rvotes;
		else
			target = max(rvotes, (rivals.top().first + 1000000 - 1) / 1000000 + 1);
		fflush(NULL);
		pi p2 = rVoters[p.second].top();
		rVoters[p.second].pop();

		int idx = p2.second;
		if (idx <= pos)
		{
			allVoters[idx].active = false;
		}
		else
		{
			tcost += allVoters[idx].cost;
			allVoters[idx].active = false;
			votes++;
		}
		while (pos >= 0 && votes > target)
		{
			if (allVoters[pos].active)
			{
				votes--;
				tcost -= allVoters[pos].cost;
			}
			pos--;
		}
		//printf("%d %d %d %d\n", tcost, pos, votes, target);
		bcost = min(bcost, tcost);
		if (!rVoters[p.second].empty())
			rivals.push(mp((rvotes-1) * (ll) 1000000 - rVoters[p.second].top().first, p.second));
	}

	printf("%I64d\n", bcost);
}