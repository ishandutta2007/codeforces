#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define ever ;;
#define foreach(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)
#define LINF ((ll) 1e16)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rlong(x);
#define rfloat(x) scanf("%lf", &(x))

const int MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N, K, S;

const int MX = 500005;
const int TMX = MX * 4;
vector<int> edges[MX];
vector<int> children[MX];
int height[MX];
int originalContribution[MX];
int currentAnswer;
map<int, int> minerMap;
set<pi, greater<pi> > minerMapSet;

int getIndexInTree(int h)
{
	auto it = minerMapSet.lower_bound({h, INF});
	// printf("getIndexInTree(%d) = %d\n", h, it == minerMapSet.end() ? S : it->second);
	if (it == minerMapSet.end())
		return S;
	else
		return it->second;
}

int minPrefix[TMX], sum[TMX];

void add(int idx, int a, int b, int pos, int val)
{
	if (pos < a || pos > b)
		return;
	if (a == b)
	{
		sum[idx] += val;
		minPrefix[idx] = min(sum[idx], 0);
	}
	else
	{
		int l = idx * 2 + 1;
		int r = idx * 2 + 2;
		int mid = (a + b) / 2;
		add(l, a, mid, pos, val);
		add(r, mid+1, b, pos, val);
		sum[idx] = sum[l] + sum[r];
		minPrefix[idx] = minPrefix[l];
		minPrefix[idx] = min(minPrefix[idx], sum[l] + minPrefix[r]);
	}
}

void add(int pos, int val)
{
	// printf("add(%d, %d)\n", pos, val);
	add(0, 0, S-1, pos, val);
}

void init(int x, int parent)
{
	foreach(o, edges[x]) if (o != parent)
	{
		children[x].pb(o);
		init(o, x);
	}
}

void dfs1(int x, int limit)
{
	int h = min(height[x], limit);
	originalContribution[x] = getIndexInTree(h);
	add(originalContribution[x], 1);
	foreach(o, children[x])
		dfs1(o, h);
}

void dfs2(int x, int limit, int direction)
{
	int h = min(height[x], limit);
	int idx = getIndexInTree(h);
	add(originalContribution[x], -direction);
	add(idx, direction);
	foreach(o, children[x])
		dfs2(o, h, direction);
}

int main()
{
	rint(N);
	ji(N) rint(height[i]);
	jk(N-1)
	{
		nrint(a); nrint(b);
		a--; b--;
		edges[a].pb(b);
		edges[b].pb(a);
	}
	init(0, -1);
	rint(K);
	int miners[K];
	ji(K) rint(miners[i]);
	sort(miners, miners + K);
	reverse(miners, miners + K);
	priority_queue<pi> Q;
	Q.push({height[0], 0});
	ji(K)
	{
		int x = Q.top().second;
		if (height[x] < miners[i])
		{
			set<int, greater<int> > minerSet;
			jjs(j, i, K) minerSet.insert(miners[j]);
			S = minerSet.size();
			int crnt = 0;
			foreach(v, minerSet) minerMap[v] = crnt++;
			foreach(p, minerMap)
			{
				minerMapSet.insert(p);
			}
			jjs(j, i, K) add(minerMap[miners[j]], -1);
			vector<int> V;
			while (!Q.empty())
			{
				x = Q.top().second;
				V.pb(x);
				Q.pop();
			}
			foreach(n, V)
				dfs1(n, INF);
			foreach(n, V)
			{
				int change = miners[i] - height[n];
				height[n] = miners[i];
				dfs2(n, INF, 1);
				// printf("%d %d\n", n, minPrefix[0]);
				if (minPrefix[0] == 0)
				{
					printf("%d\n", change);
					return 0;
				}
				dfs2(n, INF, -1);
			}
			printf("-1\n");
			return 0;
		}
		else
		{
			Q.pop();
			foreach(v, children[x])
				Q.push({height[v], v});
		}
	}
	printf("0\n");
}