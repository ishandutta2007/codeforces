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
	int n,k; cin>>n>>k;
	string s; cin>>s;
	vi cnt(26,0);
	for(int i=0;i<n;i++) cnt[s[i]-'a']++;
	string ans;
	int sum=0; int lastchar = 0;
	for(int i=0;i<26;i++)
	{
		sum+=cnt[i];
		if(sum>=k)
		{
			lastchar = i; break;
		}
	}
	if(cnt[lastchar]==n)
	{
		for(int i=0;i<(n+k-1)/k;i++)
		{
			cout<<char('a'+lastchar);
		}
		cout<<'\n'; return ;
	}
	int sumpre=0;
	for(int i=0;i<lastchar;i++)
	{
		sumpre+=cnt[i];
	}
	if(sumpre>0)
	{
		ans+=string(1,char('a'+lastchar));
		cout<<ans<<'\n'; return ;
	}
	else
	{
		cnt[lastchar]-=k;
		ans+=string(1,char('a'+lastchar));
		/*
		for(int i=0;i<26;i++)
		{
			while(cnt[i]>0)
			{
				ans+=string(1,char('a'+i));
				cnt[i]--;
			}
		}
		*/
		if(cnt[lastchar]>0)
		{
			for(int i=0;i<26;i++)
			{
				while(cnt[i]>0)
				{
					ans+=string(1,char('a'+i));
					cnt[i]--;
				}
			}
		}
		else
		{
			vector<pair<int,char> > vec;
			for(int i=0;i<26;i++)
			{
				if(cnt[i]>0)
				{
					vec.pb({cnt[i],'a'+i});
				}
			}
			if(vec.size()==1)
			{
				int ct = vec[0].fi; char c = vec[0].se;
				for(int i=0;i<(ct+k-1)/k;i++)
				{
					ans+=string(1,c);
				}
			}
			else if(vec.size()>1)
			{
				for(int i=0;i<26;i++)
				{
					while(cnt[i]>0)
					{
						ans+=string(1,char('a'+i));
						cnt[i]--;
					}
				}
			}
		}
	}
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}