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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

bool isprefix(string a, string b)
{
	if(a.length()>b.length()) return false;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]!=b[i]) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	string s,t; cin>>s>>t;
	if(s.length()>t.length()+1){cout<<"NO\n"; return 0;}
	int pos=-1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='*') pos=i;
	}
	if(pos==-1)
	{
		cout<<(s==t?"YES":"NO")<<'\n';
		return 0;
	}
	string s1=s.substr(0,pos);
	string s2=s.substr(pos+1,int(s.length())-1-pos);
	if(!isprefix(s1,t))
	{
		cout<<"NO\n"; return 0;
	}
	reverse(t.begin(),t.end()); reverse(s2.begin(),s2.end());
	if(!isprefix(s2,t))
	{
		cout<<"NO\n"; return 0;
	}
	cout<<"YES\n"; return 0;
}