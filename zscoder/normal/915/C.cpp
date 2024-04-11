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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

ll convert(string s)
{
	ll ans=0;
	for(int i=0;i<s.length();i++)
	{
		ans*=10;
		ans+=s[i]-'0';
	}
	return ans;
}

string res;
ll target;

bool good(string prefix, string nw)
{
	sort(nw.begin(),nw.end());
	prefix+=nw;
	ll cur=convert(prefix);
	return cur<=target;
}

void solve(string s, bool tmp = 1)
{
	if(s.length()==1)
	{
		res+=s[0];
		return ;
	}
	sort(s.rbegin(),s.rend());
	string s2;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='0'&&tmp) continue;
		string r;
		for(int j=0;j<s.length();j++)
		{
			if(j!=i) r+=s[j];
		}
		if(good(res+s[i],r))
		{
			res+=s[i];
			s2=r;
			break;
		}
	}
	solve(s2, 0);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string a; cin>>a;
	cin>>target;
	solve(a);
	assert(res.length()==a.length());
	cout<<res<<'\n';
}