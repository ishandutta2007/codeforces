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
typedef bitset<1001> bit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 3;

bit line[N];
int pos[N][1001];
int ans[N];

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	//line[0] is reset
	for(int i = 1; i <= q; i++)
	{
		int t;
		scanf("%d", &t);
		int x, y;
		if(t == 1 || t == 2)
		{
			scanf("%d %d", &x, &y);
		}
		else
		{
			scanf("%d", &x);
		}
		for(int j = 1; j <= n; j++)
		{
			pos[i][j] = pos[i-1][j];
		}
		ans[i] = ans[i-1];
		if(t == 1)
		{
			line[i] = line[pos[i][x]];
			if(!line[i][y]) ans[i]++;
			line[i].set(y, 1);
			pos[i][x] = i;
		}
		else if(t == 2)
		{
			line[i] = line[pos[i][x]];
			if(line[i][y]) ans[i]--;
			line[i].set(y, 0);
			pos[i][x] = i;
		}
		else if(t == 3)
		{
			line[i] = line[pos[i][x]];
			int l = line[i].count();
			ans[i] += (m - 2*l);
			for(int j = 1; j <= m; j++)
			{
				line[i].flip(j);
			}
			pos[i][x] = i;
		}
		else
		{
			for(int j = 1; j <= n; j++)
			{
				pos[i][j] = pos[x][j];
			}
			ans[i] = ans[x];
		}
		
	}
	for(int i = 0; i < q; i++)
	{
		printf("%d\n", ans[i+1]);
	}
}