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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ll convert(string s)
{
	ll cur = 1; ll ans = 0;
	for(int i = s.length() - 1; i >= 0; i--)
	{
		ans += cur*(s[i]-'0');
		cur*=10;
	}	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int l = int(s.length());
	char c = s[l-1];
	l--;
	s = s.substr(0, l);
	ll n = convert(s);
	ll ans = 0;
	if(c=='f') ans=1;
	else if(c=='e') ans=2;
	else if(c=='d') ans=3;
	else if(c=='a') ans=4;
	else if(c=='b') ans=5;
	else ans = 6;
	ll serve = ((n-1)/4)*2LL;
	//cerr<<serve<<endl;
	if(n%2==0) serve++;
	ans+=serve*6LL;
	if((n%4==1)||(n%4==2))
	{
		ans += (n-1);
	}
	else
	{
		ans+=(n-3);
	}
	cout<<ans;
}