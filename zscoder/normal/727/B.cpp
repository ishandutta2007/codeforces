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

const int MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s; s += "z";
	ll sum = 0; ll cur = 0; int ct = 0; bool ex = false;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i]>='a'&&s[i]<='z') 
		{
			//cerr<<cur<<'\n';
			if(ct != 2 || !ex) cur*=100LL;
			sum += cur;
			cur = 0;
			ex = false;
			continue;
		}
		if(s[i]=='.')
		{
			ex = true;
			ct = 0;
			continue;
		}
		cur*=10LL;
		cur+=(s[i]-'0');
		ct++;
	}
	int t = sum%100;
	sum/=100;
	string b = ".";
	if(t<10&&t>=1)
	{
		b += "0";
		b += char(t+'0');
	}
	else if(t == 0)
	{
		b = "";
	}
	else
	{
		b += char(t/10 + '0');
		b += char(t%10 + '0');
	}
	string a = "";
	vector<int> digits;
	if(sum == 0) digits.pb(0);
	else
	{
		while(sum)
		{
			digits.pb(sum%10);
			sum/=10;
		}
		reverse(digits.begin(), digits.end());
	}
	int cnt = 0;
	for(int i = digits.size() - 1; i >= 0; i--)
	{
		if(cnt >= 3 && cnt%3 == 0)
		{
			a += ".";
		}
		a += char(digits[i]+'0');
		cnt++;
	}
	reverse(a.begin(),a.end());
	cout << a << b;
}