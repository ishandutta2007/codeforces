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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int a[101][101];
int r[101];
int c[101];
int n,m; 

int check()
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(!(r[i]>=0&&r[i]<=500)) return -1;
		cnt+=r[i];
	}
	for(int i=0;i<m;i++)
	{
		if(!(c[i]>=0&&c[i]<=500)) return -1;
		cnt+=c[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(r[i]+c[j]!=a[i][j])
			{
				return -1;
			}
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	int cnt=100000000;
	int idx=-1;
	for(int i=0;i<=500;i++)
	{
		r[0]=i;
		for(int j=0;j<m;j++)
		{
			c[j] = a[0][j] - r[0];
		}
		for(int j=1;j<n;j++)
		{
			r[j] = a[j][0] - c[0];
		}
		int res = check();
		if(res==-1) continue;
		if(res<cnt)
		{
			cnt=res;
			idx=i;
		}
	}
	if(idx==-1)
	{
		cout<<-1<<'\n';
		return 0;
	}
	cout<<cnt<<'\n';
	r[0]=idx;
	for(int j=0;j<m;j++)
	{
		c[j] = a[0][j] - r[0];
	}
	for(int j=1;j<n;j++)
	{
		r[j] = a[j][0] - c[0];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<r[i];j++)
		{
			cout<<"row "<<i+1<<'\n';
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<c[i];j++)
		{
			cout<<"col "<<i+1<<'\n';
		}
	}
}