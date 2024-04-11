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
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin>>s;
	int cur = 0;
	int sum = 0;
	int sign = 1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='+')
		{
			sum+=cur*sign;
			sign=1;
			cur=0;
		}
		else if(s[i]=='-')
		{
			sum+=cur*sign;
			cur=0;
			sign=-1;
		}
		else
		{
			cur*=10;
			cur+=s[i]-'0';
		}
	}
	sum+=cur*sign;
	vi dig;
	if(sum==0) dig.pb(0);
	while(sum>0)
	{
		dig.pb(sum%10);
		sum/=10;
	}
	reverse(dig.begin(),dig.end());
	for(int i=0;i<dig.size();i++)
	{
		for(int j=0;j<int('0')+dig[i];j++)
		{
			cout<<"+";
		}
		cout<<".";
		for(int j=0;j<int('0')+dig[i];j++)
		{
			cout<<"-";
		}
	}
	cout<<'\n';
}