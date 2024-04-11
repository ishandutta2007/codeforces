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

int a[555];

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
	sort(vec.rbegin(),vec.rend());
	int lo = 0; int hi = n-2; //# of vertices in the middle sia
	vector<ii> res;
	int ans=-1;
	while(lo<=hi)
	{
		int mid=(lo+hi)>>1;
		//is it possible
		//use [0,mid-1] as middle, use mid as front, use mid+1 as end
		vector<ii> G;
		vector<ii> tmp = vec;
		bool pos=1;
		for(int i=0;i<=mid-1;i++)
		{
			if(vec[i].fi<2)
			{
				pos=0; break;
			}
			vec[i].fi-=2;
			G.pb({vec[i].se,vec[i+1].se});
		}
		vec[mid].fi--; vec[mid+1].fi--;
		G.pb({vec[mid+1].se,vec[0].se});
		int ptr=0;
		for(int i=mid+2;i<n;i++)
		{
			while(ptr<i&&vec[ptr].fi<=0)
			{
				ptr++;
			}
			if(ptr>=i){pos=0; break;}
			G.pb({vec[i].se,vec[ptr].se});
			vec[ptr].fi--; vec[i].fi--;
		}
		vec=tmp;
		if(!pos)
		{
			hi=mid-1;
		}
		else
		{
			lo=mid+1;
			ans=mid;
			res=G;
		}
	}
	if(ans!=-1)
	{
		cout<<"YES "<<ans+1<<'\n';
		cout<<res.size()<<'\n';
		for(ii x:res)
		{
			cout<<x.fi+1<<' '<<x.se+1<<'\n';
		}
	}
	else
	{
		cout<<"NO\n";
	}
}