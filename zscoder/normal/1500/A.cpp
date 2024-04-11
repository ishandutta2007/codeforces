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
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ii cnt[5000011];
vi a;
int b[5000011];
bool bad[222222];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n; a.resize(n);
	map<int,int> ma;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ma[a[i]]++;
		b[a[i]]=i+1;
	}
	vector<int> vec;
	for(auto X:ma)
	{
		if(X.se>=2)
		{
			vec.pb(X.fi);
		}
		if(vec.size()>=2) break;
	}
	if(vec.size()>=2)
	{
		vi F[2];
		for(int i=0;i<n;i++)
		{
			if(a[i]==vec[0]) F[0].pb(i+1);
			if(a[i]==vec[1]) F[1].pb(i+1);
		}
		cout<<"YES\n";
		cout<<F[0][0]<<' '<<F[1][0]<<' '<<F[0][1]<<' '<<F[1][1]<<'\n';
		return 0;
	}
	//only one guy has >= 1 distinct
	if(!vec.empty())
	{
		int val = vec[0];
		vi F;
		for(int i=0;i<n;i++)
		{
			if(a[i]==vec[0]) F.pb(i+1);
		}
		if(F.size()>=4)
		{
			cout<<"YES\n";
			cout<<F[0]<<' '<<F[1]<<' '<<F[2]<<' '<<F[3]<<'\n';
			return 0;
		}
		for(int i=1;i<F.size();i++) bad[F[i]-1]=1;
		int x=-1; int y=-1;
		for(int i=0;i<n;i++)
		{
			if(a[i]==val) continue;
			int diff = 2*val - a[i];
			if(diff>=0&&b[diff]>0)
			{
				x=i+1;
				y=b[diff];
			}
		}
		if(x>-1) 
		{
			cout<<"YES\n"; cout<<F[0]<<' '<<F[1]<<' '<<x<<' '<<y<<'\n'; return 0;
		}
	}
	vector<ii> v;
	for(int i=0;i<n;i++)
	{
		if(bad[i]) continue;
		v.pb({a[i],i+1});
	}
	n=v.size();
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(cnt[v[i].fi+v[j].fi].fi==0)
			{
				cnt[v[i].fi+v[j].fi]={v[i].se,v[j].se};
			}
			else
			{
				cout<<"YES\n";
				cout<<v[i].se<<' '<<v[j].se<<' '<<cnt[v[i].fi+v[j].fi].fi<<' '<<cnt[v[i].fi+v[j].fi].se<<'\n';
				return 0;
				
			}
		}
	}
	cout<<"NO\n";
}