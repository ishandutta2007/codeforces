#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int MOD = 1e9 + 7;
const int N = 1e6 + 1;

int par[N];
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y)))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
bool same(int x, int y)
{
	return (root(x) == root(y));
}

int group[N];
vector<int> vec[N];
int counter[N];
int a[N];

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0);
	memset(par, -1, sizeof(par));
	int u, v;
	int n, m; scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
	}
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &u, &v);
		u--; v--;
		merge(u, v);
	}
	int r;
	for(int i = n - 1; i >= 0; i--)
	{
		r = root(i);
		vec[r].pb(a[i]);
		group[i] = r;
	}
	for(int i = 0; i < n; i++)
	{
		if(!vec[i].empty())
		{
			sort(vec[i].begin(), vec[i].end());
			reverse(vec[i].begin(), vec[i].end());
		}
	}
	for(int i = 0; i < n; i++)
	{
		r = group[i];
		printf("%d ", vec[r][counter[r]]);
		counter[r]++;
	}
	return 0;
}