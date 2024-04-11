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

bool used[27];
int cnt[27];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	string s; cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]>='a'&&s[i]<='z') used[s[i]-'a']=1;
	}
	int m; cin>>m;
	int res=0;
	for(int i=0;i<m;i++)
	{
		string y; cin>>y;
		bool pos=1;
		for(int j=0;j<n;j++)
		{
			if(s[j]!='*')
			{
				if(s[j]!=y[j])
				{
					pos=0;
					break;
				}
			}
			else
			{
				if(used[y[j]-'a'])
				{
					pos=0;
					break;
				}
			}
		}
		if(pos)
		{
			res++;
			for(int k=0;k<26;k++)
			{
				bool ex=0;
				for(int j=0;j<n;j++)
				{
					if(s[j]=='*'&&y[j]-'a'==k)
					{
						ex=1;
						break;
					}
				}
				if(ex) cnt[k]++;
			}
		}
	}
	int ans=0;
	for(int i=0;i<26;i++)
	{
		if(cnt[i]==res)
		{
			ans++;
		}
	}
	cout<<ans<<'\n';
}