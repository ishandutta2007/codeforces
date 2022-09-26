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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char a[51][51];
int n, m, k;
bool visited[51][51];

bool valid(int x, int y)
{
	if(x>=0&&x<n&&y>=0&&y<m&&a[x][y]=='.') return true;
	return false;
}

const int shift = 50;
int ccnt = 0;
vector<ii> vec;
int ans2 = 0;
void dfs(int x, int y, bool mode)
{
	//cerr << ccnt << ' ' << x << ' ' << y << '\n';
	//a[x][y] = shift + ccnt; 
	if(mode) a[x][y] = '*';
	visited[x][y] = true;
	vec[ccnt].fi++;
	for(int i = 0; i < 4; i++)
	{
		int x1 = x + dx[i]; int y1 = y + dy[i];
		if(valid(x1, y1) && !visited[x1][y1])
		{
			dfs(x1, y1, mode);
		}
	}
}

void clr(int x)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(a[i][j] == shift + x) 
			{
				ans2++; a[i][j] = '*';
			}
		}
	}
}

void noclr(int x)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(a[i][j] == shift + x) a[i][j] = '.';
		}
	}
}

void pr()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout << a[i][j];
		}
		cout << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	queue<ii> q;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && a[i][j] == '.')
			{
				q.push(mp(i, j)); visited[i][j] = true;
				//cerr << i << ' ' << j << '\n';
			}
		}
	}
	while(!q.empty())
	{
		int x = q.front().fi; int y = q.front().se; q.pop();
		//cerr << x << ' ' << y << '\n';
		//a[x][y] = shift - 1;
		for(int i = 0; i < 4; i++)
		{
			int x2 = x+dx[i]; int y2 = y+dy[i];
			if(valid(x2, y2) && !visited[x2][y2])
			{
				visited[x2][y2] = true;
				q.push(ii(x2, y2));
			}				
		}
	}
	//pr();
	//cout <<"HER"<<endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(a[i][j] == '.' && !visited[i][j])
			{
				vec.pb(mp(0, ccnt));
				dfs(i, j, 0);
				ccnt++;
			}
		}
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	int ans = 0;
	//assert(vec.size()==ccnt);
	//assert(ccnt>=k);
	vi c;
	for(int i = 0; i < vec.size(); i++)
	{
		if(i >= k)
		{
			c.pb(vec[i].se);
			ans += vec[i].fi;
		}
	}
	if(!c.empty()) sort(c.begin(), c.end());
	memset(visited, 0, sizeof(visited));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && a[i][j] == '.')
			{
				q.push(mp(i, j)); visited[i][j] = true;
				//cerr << i << ' ' << j << '\n';
			}
		}
	}
	while(!q.empty())
	{
		int x = q.front().fi; int y = q.front().se; q.pop();
		//cerr << x << ' ' << y << '\n';
		//a[x][y] = shift - 1;
		for(int i = 0; i < 4; i++)
		{
			int x2 = x+dx[i]; int y2 = y+dy[i];
			if(valid(x2, y2) && !visited[x2][y2])
			{
				visited[x2][y2] = true;
				q.push(ii(x2, y2));
			}				
		}
	}
	//pr();
	//cout <<"HER"<<endl;
	int ptr = 0; ccnt = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(a[i][j] == '.' && !visited[i][j])
			{
				if(ptr < c.size() && ccnt == c[ptr]) 
				{
					dfs(i, j, 1);
					ptr++;
				}
				else dfs(i, j, 0);
				ccnt++;
			}
		}
	}
	memset(visited, 0, sizeof(visited));
	//assert(ans==ans2);
	cout << ans << '\n';
	pr();
}