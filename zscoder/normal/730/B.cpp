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

void flush()
{
	fflush(stdout);
}

bool query(int x, int y)
{
	x++; y++;
	cout << "? " << x << ' ' << y << endl;
	flush();
	char c; cin >> c;
	if(c == '>') return 1;
	else return 0;
}	

void out(int x, int y)
{
	x++; y++;
	cout << "! " << x << ' ' << y << endl;
	flush();
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		if(n == 1)
		{
			out(0,0);
			continue;
		}
		ii minmax;
		int i;
		if(n%2==0)
		{
			if(query(0, 1))
			{
				minmax.se = 0;
				minmax.fi = 1;
			}
			else
			{
				minmax.fi = 0;
				minmax.se = 1;
			}
			i = 2;
		}
		else
		{
			minmax.se = 0;
			minmax.fi = 0;
			i = 1;
		}
		while(i < n - 1)
		{
			if(query(i,i+1))
			{
				if(query(i,minmax.se))
				{
					minmax.se = i;
				}
				if(query(minmax.fi, i+1))
				{
					minmax.fi = i+1;
				}
			}
			else
			{
				if(query(i+1,minmax.se))
				{
					minmax.se = i+1;
				}
				if(query(minmax.fi, i))
				{
					minmax.fi = i;
				}
			}
			i+=2;
		}
		out(minmax.fi, minmax.se);
	}
}