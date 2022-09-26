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

char a[2001][2001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char f[4] = {'^', 'v', '<', '>'};

queue<ii> q;
int n, m;
bool valid(int x, int y)
{
	return (x>=0&&x<n&&y>=0&&y<m&&a[x][y]=='.');
}

int deg(int x, int y)
{
	int cnt = 0; 
	for(int i = 0; i < 4; i++)
	{
		if(valid(x+dx[i], y+dy[i]))
		{
			cnt++;
		}
	}
	return cnt;
}

void yes()
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << '\n';
	}
}

void no()
{
	cout << "Not unique\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(deg(i, j) == 1 && valid(i, j))
			{
				q.push(ii(i, j));
			}
		}
	}
	while(!q.empty()) //assign those deg 1 vertices the dominos
	{
		int x = q.front().fi; int y = q.front().se; q.pop();
		for(int i = 0; i < 4; i++)
		{
			if(valid(x+dx[i], y+dy[i]))
			{
				a[x][y] = f[i];
				a[x+dx[i]][y+dy[i]] = f[(i^1)];
				for(int j = 0; j < 4; j++)
				{
					if(valid(x+dx[i]+dx[j], y+dy[i]+dy[j]) && deg(x+dx[i]+dx[j], y+dy[i]+dy[j]) == 1)
					{
						q.push(ii(x+dx[i]+dx[j], y+dy[i]+dy[j]));
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(a[i][j] == '.') {no(); return 0;}
		}
	}
	yes();
}