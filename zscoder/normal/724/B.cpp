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

int g[21][21];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> g[i][j];
			g[i][j]--;
		}
	}
	vi perm; perm.resize(m);
	for(int i = 0; i < m; i++) perm[i] = i;
	for(int i = 0; i < m; i++)
	{
		for(int j = i; j < m; j++)
		{
			swap(perm[i], perm[j]);
			bool pos = true;
			for(int k = 0; k < n; k++)
			{
				bool pos2 = false;
				for(int a = 0; a < m; a++)
				{
					for(int b = a; b < m; b++)
					{
						swap(g[k][a], g[k][b]);
						bool pos3 = true;
						for(int c = 0; c < m; c++)
						{
							if(g[k][c] != perm[c])
							{
								pos3 = false;
								break;
							}
						}
						swap(g[k][a], g[k][b]);
						if(pos3)
						{
							pos2 = true;
							break;
						}
					}
					if(pos2) break;
				}
				if(!pos2)
				{
					pos = false;
					break;
				}
			}
			swap(perm[i], perm[j]);
			if(pos)
			{
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}