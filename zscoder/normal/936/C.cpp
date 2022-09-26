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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int cnt[27];
vi moves;

string shift(string s, int id)
{
	int n=s.length();
	moves.pb(id);
	string t;
	for(int i=n-1;i>=n-id;i--)
	{
		t+=s[i];
	}
	for(int i=0;i<n-id;i++)
	{
		t+=s[i];
	}
	return t;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	string s,t;
	cin>>s>>t;
	for(int i=0;i<n;i++)
	{
		cnt[s[i]-'a']++; cnt[t[i]-'a']--;
	}
	for(int i=0;i<26;i++)
	{
		if(cnt[i]!=0){cout<<-1<<'\n'; return 0;}
	}
	for(int i=0;i<s.length();i++)
	{
		//fix i-th character
		int idx=i;
		for(int j=i;j<s.length();j++)
		{
			if(s[j]==t[i])
			{
				idx=j; break;
			}
		}
		if(i%2==0)
		{
			s = shift(s, n - i);
			s = shift(s, idx);
			s = shift(s, 1);
		}
		else
		{
			s = shift(s, n - idx - 1);
			s = shift(s, idx + 1 - i);
			s = shift(s, i);
		}
	}
	if(s!=t) s=shift(s,n);
	cout<<moves.size()<<'\n';
	for(int i=0;i<moves.size();i++)
	{
		cout<<moves[i];
		if(i+1<moves.size()) cout<<' ';
	}
	cout<<'\n';
}