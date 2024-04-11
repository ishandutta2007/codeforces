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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll cnt[28];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++) cnt[s[i]-'a']++;
	ll ans=0;
	for(int i=0;i<26;i++) 
	{
		ans=max(ans,cnt[i]);
		ans=max(ans,((cnt[i]-1)*cnt[i])/2);
	}
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(i!=j)
			{
				ll cur=0;
				ll S=0;
				for(int k=0;k<n;k++)
				{
					if(s[k]-'a'==j) S+=cur;
					if(s[k]-'a'==i) cur++;
				}
				ans=max(ans,S);
			}
		}
	}
	cout<<ans<<'\n';
}