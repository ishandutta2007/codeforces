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

string reduce(string s)
{
	string oris=s;
	string t="";
	for(int i=0;i<s.length();i++)
	{
		if(i+1<s.length()&&s[i]=='k'&&s[i+1]=='h')
		{
			t+=s[i+1];
			i++;
			continue;
		}
		else
		{
			t+=s[i];
		}
	}
	if(oris==t) return t;
	else return reduce(t);
}

string reduce2(string s)
{
	string oris = s;
	string t="";
	int cnt=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='u')
		{
			cnt+=2;
		}
		else if(s[i]=='o')
		{
			cnt++;
		}
		else
		{
			for(int j=0;j<cnt;j++) t+='o';
			t+=s[i];
			cnt=0;
		}
	}
	for(int j=0;j<cnt;j++) t+='o';
	return t;
}

string a[411];
set<string> vec;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; string ori=a[i];
		a[i]=reduce(a[i]);
		a[i] = reduce2(a[i]);
		vec.insert(a[i]);
		//cerr<<ori<<' '<<a[i]<<'\n';
	}
	cout<<vec.size()<<'\n';
}