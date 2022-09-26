#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef long double ld;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int MOD = 1e9 + 7;

int a[200001];

int visited[200001];

vi fixedpt;
vi repair;

bool empt;


void dfs(int u)
{
	visited[u] = 2;
	int v = a[u];
	if(v == u){}
	else if(visited[v] == 2)
	{
		repair.pb(v);
	}
	else if(visited[v] == 1)
	{
		
	}
	else
	{
		dfs(v);
	}
	visited[u] = 1;
}

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int n; int cnt = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]); a[i]--;
		if(a[i] == i) fixedpt.pb(i);
	}
	empt = false;
	if(fixedpt.empty()) empt = true;
	if(!fixedpt.empty())
	{
		for(int i = 0; i < fixedpt.size(); i++)
		{
			a[fixedpt[i]] = fixedpt[0];
			if(i > 0) cnt++;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(!visited[i]) dfs(i);
	}
	for(int i = 0; i < repair.size(); i++)
	{
		if(fixedpt.empty())
		{
			a[repair[i]] = repair[0];
		}
		else
		{
			a[repair[i]] = fixedpt[0];
		}
		cnt++;
	}
	printf("%d\n", cnt);
	for(int i = 0; i < n; i++)
	{
		printf("%d ", a[i]+1);
	}
}