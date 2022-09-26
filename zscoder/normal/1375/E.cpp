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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[2222];
int newid[2222];
int pos[2222];
bool isinv[1111][1111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<ii> vec;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		vec.pb({a[i],i});
	}
	int invcnt=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				isinv[i][j]=isinv[j][i]=1;
				invcnt++;
			}
		}
	}
	vector<ii> ans;
	sort(vec.begin(),vec.end());
	for(int i=0;i<n;i++)
	{
		newid[vec[i].se]=i;
	}
	for(int i=0;i<n;i++)
	{
		pos[newid[i]]=i;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j+1<n;j++)
		{
			if(pos[j]>pos[j+1])
			{
				int p1 = pos[j];
				int p2 = pos[j+1];
				swap(pos[j],pos[j+1]);
				if(p1>p2) swap(p1,p2);
				if(isinv[p1][p2])
				{
					ans.pb({p1,p2});
					swap(a[p1],a[p2]);
				}
			}
		}
	}
	/*
	for(int i=0;i<n;i++)
	{
		cerr<<a[i]<<' ';
	}
	cerr<<'\n';
	*/
	cout<<ans.size()<<'\n';
	assert(int(ans.size())==invcnt);
	for(ii x:ans)
	{
		cout<<x.fi+1<<' '<<x.se+1<<'\n';
	}
}