#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[111111];
int M[111111];
int b[111111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];b[i]=a[i];
	}
	vector<ii> vec;
	vector<ii> V;
	for(int i=0;i<m;i++)
	{
		int l,r; cin>>l>>r; l--; r--;
		vec.pb({l,r});V.pb({l,r});
	}
	vi ans={};
	int best=-int(1e9);
	for(int i=0;i<vec.size();i++) swap(vec[i].fi,vec[i].se);
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++) swap(vec[i].fi,vec[i].se);
	int ptr=0;
	int mn=int(1e9);
	for(int i=0;i<n;i++)
	{
		//apply only segments before a[i]
		mn=min(mn,a[i]);
		M[i]=mn;
		while(ptr<vec.size()&&vec[ptr].se<=i)
		{
			for(int j=vec[ptr].fi;j<=vec[ptr].se;j++)
			{
				a[j]--; mn=min(mn,a[j]);
			}
			ptr++;
		}
	}
	for(int i=0;i<n;i++) a[i]=b[i];
	sort(vec.rbegin(),vec.rend());
	mn=int(1e9);
	ptr=0;
	for(int i=n-1;i>=0;i--)
	{
		//apply only segments after a[i]
		mn=min(mn,a[i]);
		M[i]=min(M[i],mn);
		while(ptr<vec.size()&&vec[ptr].fi>=i)
		{
			for(int j=vec[ptr].fi;j<=vec[ptr].se;j++)
			{
				a[j]--; mn=min(mn,a[j]);
			}
			ptr++;
		}
	}
	for(int i=0;i<n;i++) a[i]=b[i];
	for(int i=0;i<n;i++)
	{
		if(a[i]-M[i]>best)
		{
			best=a[i]-M[i]; ans.clear();
			for(int j=0;j<m;j++)
			{
				if(V[j].se<i||V[j].fi>i)
				{
					ans.pb(j);
				}
			}
		}
	}
	cout<<best<<'\n';
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]+1;
		if(i+1<ans.size()) cout<<' ';
	}
	cout<<'\n';	
}