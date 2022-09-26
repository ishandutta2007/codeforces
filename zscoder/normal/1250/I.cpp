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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

pbds T[222222];
ii F[222222];
vi pos[222222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y; cin>>x>>y;
		T[x].insert({i,y});
		pos[x].pb(i);
		F[i]={x,y};
	}
	int q; cin>>q;
	for(int i=0;i<q;i++)
	{
		int k; cin>>k;
		vi v;
		set<int> S;
		for(int j=0;j<k;j++)
		{
			int x; cin>>x; v.pb(x); S.insert(x);
		}
		int lo=0; int hi=n-1;
		int ans=-1;
		while(lo<=hi)
		{
			int mid=(lo+hi)>>1;
			int cnt=0;
			for(int x:v)
			{
				cnt+=T[x].size()-T[x].order_of_key({mid+1,-1});
			}
			if(cnt>=n-1-mid)
			{
				ans=mid;
				hi=mid-1;
			}
			else
			{
				lo=mid+1;
			}
		}
		//position ans
		while(ans>=0&&S.find(F[ans].fi)!=S.end()) ans--;
		if(ans<0)
		{
			cout<<0<<' '<<0<<'\n';
		}
		else
		{
			int id=F[ans].fi;
			int lo=0; int hi=int(pos[id].size())-1;
			v.pb(id);
			int newans=0;
			while(lo<=hi)
			{
				int mid=(lo+hi)>>1;
				int posno=pos[id][mid];
				int cnt=0;
				for(int x:v)
				{
					cnt+=T[x].size()-T[x].order_of_key({posno+1,-1});
				}
				//cerr<<"POSNO: "<<posno<<' '<<cnt<<' '<<n-1-posno<<'\n';
				if(cnt>=n-1-posno)
				{
					newans=posno;
					hi=mid-1;
				}
				else
				{
					lo=mid+1;
				}
			}
			//cerr<<newans<<'\n';
			cout<<F[newans].fi<<' '<<F[newans].se<<'\n';
		}
	}
}