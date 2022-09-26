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

set<ii> edges;

void add(int u, int v)
{
	edges.insert(mp(u,v));
}

void print()
{
	cout<<edges.size()<<'\n';
	for(set<ii>::iterator it = edges.begin(); it != edges.end(); it++)
	{
		cout<<(*it).fi<<' '<<(*it).se<<'\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; cin>>n>>k;
	if(n<=3)
	{
		cout<<-1;
		return 0;
	}
	if(n<k+1)
	{
		cout<<-1;
		return 0;
	}
	if(k==1)
	{
		cout<<-1;
		return 0;
	}
	if(k==2)
	{
		if(n==4)
		{
			cout<<-1; return 0;
		}
		cout<<n-1<<'\n';
		for(int i = 2; i <= n; i++)
		{
			cout<<i-1<<' '<<i<<'\n';
		}
		return 0;
	}
	if(k==3)
	{
		for(int i = 1; i <= 3; i++)
		{
			add(i,i+1);
		}
		for(int i = 2; i <= 4; i++)
		{
			for(int j = 5; j <= n; j++)
			{
				add(i, j);
			}
		}	
		print();
		return 0;
	}
	cout<<-1;
}