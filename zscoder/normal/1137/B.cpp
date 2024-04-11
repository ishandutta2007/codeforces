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
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int z[888888];
int b[2];
int c[2];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	int a[2]={0,0};
	for(int i=0;i<s.length();i++)
	{
		a[s[i]-'0']++;
	}
	string t; cin>>t;
	s=t;
	for(int i=0;i<s.length();i++)
	{
		b[s[i]-'0']++;
	}
	int n=t.length();
	int L = 0, R = 0;
	for (int i = 1; i < n; i++) {
	  if (i > R) {
		L = R = i;
		while (R < n && s[R-L] == s[R]) R++;
		z[i] = R-L; R--;
	  } else {
		int k = i-L;
		if (z[k] < R-i+1) z[i] = z[k];
		else {
		  L = i;
		  while (R < n && s[R-L] == s[R]) R++;
		  z[i] = R-L; R--;
		}
	  }
	}
	int longest_suf=n;
	for(int i=1;i<n;i++)
	{
		if(z[i]>=n-i)
		{
			longest_suf=i; break;
		}
	}
	string additional = t.substr(n-longest_suf,longest_suf);
	for(int i=0;i<additional.length();i++)
	{
		c[additional[i]-'0']++;
	}
	string ans;
	if(a[0]>=b[0]&&a[1]>=b[1])
	{
		a[0]-=b[0]; a[1]-=b[1];
		ans+=t;
		while(a[0]>=c[0]&&a[1]>=c[1])
		{
			a[0]-=c[0]; a[1]-=c[1];
			ans+=additional;
		}
	}
	for(int i=0;i<a[0];i++) ans+='0';
	for(int i=0;i<a[1];i++) ans+='1';
	cout<<ans<<'\n';
}