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

bool a[27];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	int ans = 0;
	bool guess = 0;
	for(int i=0;i<26;i++) a[i]=1;
	for(int z=0;z<n;z++)
	{
		char c; cin>>c;
		string s; cin>>s;
		if(z==n-1) break;
		if(c=='?'||c=='!')
		{
			if(guess) ans++;
		}
		if(c=='.')
		{
			for(int i=0;i<s.length();i++)
			{
				a[s[i]-'a']=0;
			}
		}
		else if(c=='!')
		{
			bool cnt[27]={};
			for(int i=0;i<s.length();i++)
			{
				cnt[s[i]-'a']=1;
			}
			for(int i=0;i<26;i++)
			{
				if(!cnt[i]) a[i]=0;
			}
		}
		else
		{
			a[s[0]-'a']=0;
		}
		int ct=0;
		for(int i=0;i<26;i++)
		{
			if(a[i]) ct++;
		}
		if(ct==1) guess=1;
	}
	cout<<ans<<'\n';
}