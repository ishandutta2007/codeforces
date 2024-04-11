#include<bits/stdc++.h>
#include<time.h>
#include<stdlib.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#define pb push_back
#define mp make_pair
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pll pair<ll,ll>
#define vll vector<ll,ll>
#define all(a) (a).begin(),(a).end()
#define ff first
#define ss second
#define sz(x) (ll)x.size()
#define hell 1000000007
#define repf(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>b;i--)
#define lbnd lower_bound
#define ubnd upper_bound
#define bs binary_search
#define gcd(a,b) __gcd((a),(b))
#define EPS 1e-12
#define lcm(a,b) ((a)*(b))/__gcd((a),(b))
using namespace std;


int32_t main()
{
	string s,t;
	cin>>s>>t;
	ll i,j;
	sort(all(s));
	sort(all(t));
	reverse(all(t));
	char ans[s.length()+5];
	i=0;j=0;
	ll p=1;
	ll k1=0,k2=s.length()-1;
	ll e1=((s.length()+1)/2)-1;
	ll e2=t.length()/2-1;
		while(k1<=k2)
	{
		if(p==1)
		{
			if(s[i]<t[j])
			{
				ans[k1++]=s[i];
				i++;
			}
			else
			{
				ans[k2]=s[e1--];
				k2--;
			}
			p=-1;
		}
		else
		{
			if(t[j]>s[i])
			{
				ans[k1++]=t[j];
				j++;
			}
			else
			{
				ans[k2--]=t[e2--];
			}
			p=1;
		}
	}	
	ans[s.length()]='\0';
	cout<<ans;
	return 0;
}