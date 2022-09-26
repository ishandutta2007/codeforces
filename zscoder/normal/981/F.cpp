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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<int> a,b;
int n,LEN; 

bool check(int mid)
{
	vector<ii> intervals;
	//int curl = -1;
	for(int i=0;i<n;i++)
	{
		int L = a[i] - mid; int R = a[i] + mid;
		/*
		if(R>=L)
		{
			int lb = lower_bound(b.begin(),b.end(),L)-b.begin();
			int rb = upper_bound(b.begin(),b.end(),R-LEN)-b.begin();
			rb--;
			if(rb<0) rb+=n;
			if(lb<curl)
			{
				lb+=n; rb+=n;
			}
			intervals.pb(mp(lb,rb));
		}
		else if(L<0)
		{
			int lb = lower_bound(b.begin(),b.end(),L+LEN)-b.begin();
			int rb = upper_bound(b.begin(),b.end(),R)-b.begin();
			rb--;
			if(rb<0) rb+=n;
			if(lb<curl)
			{
				lb+=n; rb+=n;
			}
			intervals.pb(mp(lb,rb));
		}
		else
		{
		*/
		int lb = lower_bound(b.begin(),b.end(),L)-b.begin();
		int rb = upper_bound(b.begin(),b.end(),R)-b.begin();
		rb--;
		/*
			if(lb<curl)
			{
				lb+=n; rb+=n;
			}
			intervals.pb(mp(lb,rb));
		}
		curl=intervals.back().fi;
		*/
		intervals.pb(mp(lb,rb));
	}
	//[l,r] l<=r
	int mini = int(1e9);
	for(int i=0;i<intervals.size();i++)
	{
		int l=intervals[i].fi; int r=intervals[i].se;
		//cerr<<mid<<' '<<i<<' '<<"COVER "<<l<<' '<<r<<'\n';
		mini = min(mini, i-l);
		int curr = i-r;
		if(curr-mini>0) return false;
	}
	vector<ii> intervals2 = intervals;
	int curl = intervals.back().se;
	for(int i=0;i<n;i++)
	{
		//while(intervals[i].se<curl)
		//{
			intervals[i].fi+=n; intervals[i].se+=n;
		//}
		curl=intervals[i].se;
	}
	//[l,r] l>r
	int maxi = -int(1e9);
	for(int i=0;i<n;i++)
	{
		int l=intervals2[i].fi; int r=intervals[i].se;
		//cerr<<mid<<' '<<i<<' '<<"COVER "<<l<<' '<<r<<'\n';
		int curr = i-l;
		if(maxi-curr>0) return false;
		maxi = max(maxi, i+n-r);
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>LEN;
	a.resize(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) 
	{
		int x; cin>>x;
		b.pb(x-LEN); b.pb(x); b.pb(x+LEN);
	}
	sort(a.begin(),a.end()); sort(b.begin(),b.end());
	int lo = 0; int hi = LEN/2;
	int ans = 0;
	while(lo<=hi)
	{
		int mid=(lo+hi)>>1;
		bool pos = check(mid);
		if(pos)
		{
			ans = mid; hi = mid-1;
		}
		else
		{
			lo = mid+1;
		}
	}
	cout<<ans<<'\n';
}