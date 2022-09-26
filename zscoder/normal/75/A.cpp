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

int rem0(string s)
{
	int ans=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='0') continue;
		ans*=10; ans+=s[i]-'0';
	}
	return ans;
}

int norem0(string s)
{
	int ans=0;
	for(int i=0;i<s.length();i++)
	{
		ans*=10; ans+=s[i]-'0';
	}
	return ans;
}

string tostr(int n)
{
	if(n==0) return "0";
	string s;
	while(n)
	{
		s+=char('0'+n%10);
		n/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string A,B;
	cin>>A>>B;
	int a=rem0(A); int b=rem0(B);
	int c = rem0(tostr(norem0(A)+norem0(B)));
	cout<<(a+b==c?"YES":"NO")<<'\n';
}