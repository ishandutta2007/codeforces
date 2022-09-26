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

ll num(string s)
{
	if(s.empty()) return -1;
	if(s.length()>1&&s[0]=='0') return -1;
	if(s.length()>7) return -1;
	ll ans=0;
	for(int i=0;i<s.length();i++)
	{
		ans*=10; ans+=s[i]-'0';
	}
	if(ans>1000000) return -1;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	ll best=-1;
	for(int i=0;i<s.length();i++)
	{
		for(int j=i+1;j<s.length();j++)
		{
			//[0,i]
			//[i+1,j]
			//[j+1,
			string a = s.substr(0,i+1);
			string b = s.substr(i+1,j-i);
			string c = s.substr(j+1,int(s.length())-j);
			ll A=num(a); ll B=num(b); ll C=num(c);
			if(A!=-1&&B!=-1&&C!=-1)
			{
				best=max(best,A+B+C);
			}
		}
	}
	cout<<best<<'\n';
}