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

bool check(string t)
{
	int s=0;
	for(int i=0;i<t.length();i++)
	{
		if(t[i]=='(') s++;
		else s--;
		if(s<0) return false;
	}
	if(s!=0) return false;
	return true;
}

void solve()
{
	int n; cin>>n;
	string s; cin>>s;
	string a,b;
	a=string(n,'(');
	b=string(n,'(');
	vi bad;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			bad.pb(i);
		}
	}
	if(int(bad.size())&1){cout<<"NO\n"; return ;}
	int ct=n/2;
	for(int i=0;i<bad.size();i++)
	{
		if(i%2==0) 
		{
			a[bad[i]]=')';
		}
		else
		{
			b[bad[i]]=')';
		}
	}
	ct-=int(bad.size())/2;
	//a is the worse one
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0') continue;
		if(a[i]=='(') ct--;
		if(ct<0)
		{
			a[i]=')'; b[i]=a[i];
		}
	}
	if(check(a)&&check(b))
	{
		cout<<"YES\n";
		cout<<a<<'\n'<<b<<'\n';
	}
	else
	{
		cout<<"NO\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}