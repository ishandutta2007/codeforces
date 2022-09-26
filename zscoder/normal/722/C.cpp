#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

struct node
{
	int p; ll sum;
};

node par[100011];
ll a[101001];
int perm[100101];
ll answer[100011];
ll ans = 0;
bool visited[100011];

ll rt(int u)
{
	if(par[u].p == u) return u;
	else
	{
		par[u].p = rt(par[u].p);
		return par[u].p;
	}
}

void merge(int u, int v)
{
	if(rt(u) == rt(v)) return ;
	u = rt(u); v = rt(v);
	if(rand()%2) swap(u, v);
	par[v].p = u;
	par[u].p = u;
	par[u].sum += par[v].sum;
}

ll findsum(int u)
{
	return par[rt(u)].sum;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(1);
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		par[i].p = i;
		par[i].sum = 0;
	}
	for(int i = 0; i < n; i++)
	{
		cin >> perm[i];
	}
	ans = 0;
	answer[n-1] = 0;
	for(int i = n - 1; i >= 1; i--)
	{
		int pos = perm[i];
		par[pos].sum = a[pos];
		if(pos > 0 && visited[pos-1]) merge(pos - 1, pos);
		if(visited[pos+1]) merge(pos, pos + 1);
		ans = max(ans, findsum(pos));
		answer[i-1] = ans;
		visited[pos] = true;
	}
	for(int i = 0; i < n; i++)
	{
		cout << answer[i] << '\n';
	}
}