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

void solve()
{
	int n; cin>>n;
	vi a(n);
	map<int,int> freq;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i]; freq[a[i]]++;
	}
	for(ii x:freq)
	{
		if(x.se>(n+1)/2){cout<<-1<<'\n'; return ;}
	}
	vi fixable;
	vi bad;
	int free=0;
	int l=0;
	int seg=1;
	vector<ii> segments;
	for(int i=0;i+1<n;i++)
	{
		if(a[i]==a[i+1])
		{
			seg++;
			if(i==l)
			{
				bad.pb(a[i]);
			}
			else
			{
				if(a[l]==a[i]) fixable.pb(a[i]);
				else free++;
			}
			segments.pb({l,i});
			l=i+1;
		}
	}
	segments.pb({l,n-1});
	if(l==n-1)
	{
		bad.pb(a[l]);
	}
	else if(a[l]==a[n-1])
	{
		fixable.pb(a[l]);
	}
	else
	{
		free++;
	}
	map<int,int> fixi;
	map<int,int> ma;
	for(int x:bad) ma[x]++;
	for(int x:fixable) 
	{
		fixi[x]++; ma[x]++;
	}
	int mxnum = 0; int mxid=-1;
	for(auto x:ma)
	{
		if(x.se>mxnum)
		{
			mxnum=x.se; mxid=x.fi;
		}
	}
	if(mxid==-1)
	{
		cout<<seg-1<<'\n'; return ;
	}
	int S=0;
	for(ii seg:segments)
	{
		int l=seg.fi; int r=seg.se;
		int cl=a[l]; int cr=a[r];
		if(cl==mxid&&cr==mxid)
		{
			S++;
		}
		else if(cl!=mxid&&cr!=mxid)
		{
			S--;
		}
	}
	//if S>1, we die
	if(S<=1)
	{
		cout<<seg-1<<'\n'; return ;
	}
	/*
	while(fixi[mxid]>0&&mxnum*2-1>seg)
	{
		mxnum--; seg++; fixi[mxid]--;
	}
	int breakable_segments=0;
	for(ii x:fixi) breakable_segments+=x.se;
	while(breakable_segments>0&&mxnum*2-1>seg)
	{
		seg++; breakable_segments--;
	}
	if(mxnum*2-1>seg) cout<<-1<<'\n';
	else cout<<seg-1<<'\n';
	*/
	//segment break either decreases S by 2 or 1 in optimal i hope
	/*
	int can_die = 0;
	for(ii seg:segments)
	{
		int l=seg.fi; int r=seg.se;
		if(a[l]==mxid&&a[r]==mxid)
		{
			for(int i=l;i<r;i++)
			{
				if(a[i]!=mxid&&a[i+1]!=mxid)
				{
					can_die++; break;
				}
			}
		}
	}	
	while(S>1&&can_die>0)
	{
		can_die--; S-=2; seg++;
	}
	*/
	while(S>1)
	{
		S--; seg++;
	}
	cout<<seg-1<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}