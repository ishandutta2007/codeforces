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
	deque<int> a(n);
	vi ans(n+2,0);
	int mini=int(1e9);
	map<int,int> S;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; a[i]--; S[a[i]]++;
		mini=min(mini,a[i]);
	}
	if(mini>0)
	{
		for(int i=0;i<n;i++)
		{
			cout<<ans[i];
		}
		cout<<'\n';
		return ;
	}
	if(S.size()==n) ans[0]=1;
	//ans[n-1]=1; //(n-compression => 1)
	int mn = 0; 
	while(!a.empty())
	{
		int minS = -1;
		if(!S.empty()) minS = (*S.begin()).fi;
		if(minS<mn)
		{
			break; //bye bye this is too scary, i'm out
		}
		/*
		if(S.size()==a.size())
		{
			ans[n-a.size()]=1;
		}
		*/
		if(mn==minS) ans[int(a.size())-1]=1;
		if(a[0]==mn)
		{
			S[mn]--;
			if(S[mn]==0) S.erase(mn);
			a.pop_front();
		}
		else if(a.back()==mn)
		{
			S[mn]--;
			if(S[mn]==0) S.erase(mn);
			a.pop_back();
		}
		else
		{
			break; //die le
		}
		mn++;
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i];
	}
	cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		solve();
	}
}