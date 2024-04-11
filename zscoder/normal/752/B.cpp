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

bool adj[28][28];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string a, b; cin>>a>>b;
	int n = a.length();
	for(int i = 0; i < n; i++)
	{
		adj[a[i]-'a'][b[i]-'a']=1;
		adj[b[i]-'a'][a[i]-'a']=1;
	}
	
	vector<ii> ans;
	for(int i = 0; i < 26; i++)
	{
		int cnt=0;
		for(int j =0;j<26;j++)
		{
			if(i==j) continue;
			if(adj[i][j]) cnt++;
		}
		if(cnt>1)
		{
			cout<<-1;
			return 0;
		}
	}
	map<char,char> retard;
	for(int i  =0; i < 26; i++) retard[char('a'+i)]='a'+i;
	for(int i = 0; i < 26; i++)
	{
		for(int j = i + 1; j < 26; j++)
		{
			if(adj[i][j]) 
			{
				ans.pb(mp(i,j));
				retard[char(i+'a')]=char(j+'a');
				retard[char(j+'a')]=char(i+'a');
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		a[i]=retard[a[i]];
	}	
	if(a!=b)
	{
		cout<<-1;
		return 0;
	}
	cout<<ans.size()<<'\n';
	for(int i = 0; i < ans.size(); i++)
	{
		cout<<char('a'+ans[i].fi)<<' '<<char('a'+ans[i].se)<<'\n';
	}
}