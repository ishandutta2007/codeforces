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

bool visited[51][51];
char a[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m; 
bool valid(int x, int y)
{
	if((x >= 0 && x < n) && (y >= 0 && y < m)) return true;
	else return false;
}

bool dfs(int x, int y, int px, int py)
{
	//cerr << x << ' ' << y << ' ' << px << ' ' << py << '\n';
	if(visited[x][y]) return true;
	visited[x][y] = true;
	bool ans = false;
	for(int i = 0; i < 4; i++)
	{
		int x1 = x + dx[i]; int y1 = y + dy[i];
		if(x1 == px && y1 == py) continue;
		if(valid(x1, y1)) 
		{
			if(a[x1][y1] == a[x][y]) ans|=dfs(x1, y1, x, y);
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(!visited[i][j])
			{
				bool ans = dfs(i, j, -1, -1);
				if(ans) {cout << "Yes"; return 0;}
			}
		}
	}
	cout << "No";
}