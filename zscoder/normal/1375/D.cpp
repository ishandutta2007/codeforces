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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

bool issorted(vi &v)
{
	for(int i=0;i+1<v.size();i++)
	{
		if(v[i]>v[i+1]) return false;
	}
	return true;
}

int mex(vi &v)
{
	set<int> S;
	for(int x:v) S.insert(x);
	for(int i=0;;i++)
	{
		if(S.find(i)==S.end()) return i;
	}
}

void solve()
{
	int n; cin>>n;
	vi a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vi ans;
	/*
	int diu = mex(a);
	int cnt = 0;
	while(diu==cnt)
	{
		ans.pb(cnt);
		a[cnt] = diu;
		cnt++;
		diu = mex(a);
		if(issorted(a))
		{
			assert(int(ans.size())<=2*n);
			cout<<ans.size()<<'\n';
			for(int i=0;i<ans.size();i++)
			{
				cout<<ans[i]+1<<' ';
			}
			cout<<'\n';
			return ;
		}
	}
	//start from cnt sia
	set<int> sacred;
	diu = mex(a);
	for(int i=cnt;i<n;i++)
	{
		if(a[i]<diu)
		{
			sacred.insert(i);
		}
	}
	for(int i=cnt;i<n;i++)
	{
		if(sacred.find(i)==sacred.end())
		{
			diu = mex(a);
			a[i]=diu;
			ans.pb(i);
		}
	}
	*/
	/*
	for(int x:a)
	{
		cerr<<x<<' ';
	}
	cerr<<'\n';
	*/
	while(!issorted(a))
	{
		int diu = mex(a);
		if(diu>=n)
		{
			int id=0;
			for(int i=0;i<n;i++)
			{
				if(a[i]!=i)
				{
					id=i; break;
				}
			}
			ans.pb(id);
			a[id]=diu;
		}
		else
		{
			ans.pb(diu);
			a[diu] = diu;
		}
	}
	assert(int(ans.size())<=2*n);
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]+1<<' ';
	}
	cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}