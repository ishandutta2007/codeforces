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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int dist(string s, string t)
{
	int ans=0;
	for(int i=0;i<s.length();i++)
	{
		ans+=(s[i]!=t[i]);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	vector<string> vec(n);
	for(int i=0;i<n;i++) cin>>vec[i];
	vector<char> C = {'A','C','G','T'};
	int mn = int(1e9);
	vector<string> ans;
	sort(C.begin(),C.end());
	do
	{
		{
			vector<string> res(n); int r=0;
			for(int i=0;i<n;i++)
			{
				string s1,s2;
				for(int j=0;j<m;j++)
				{
					if(j&1){s1+=C[(i%2)*2+1]; s2+=C[(i%2)*2];}
					else{s2+=C[(i%2)*2+1]; s1+=C[(i%2)*2];}
				}
				int d1=dist(s1,vec[i]); int d2=dist(s2,vec[i]);
				if(d1<d2)
				{
					res[i]=s1;
				}
				else
				{
					res[i]=s2;
				}
				r+=min(d1,d2);
			}
			if(r<mn)
			{
				mn=r; ans=res;
			}
		}
		{
			vector<string> res(n); int r=0;
			for(int j=0;j<n;j++) 
			{
				for(int k=0;k<m;k++) res[j]+=" ";
			}
			for(int j=0;j<m;j++)
			{
				string s1,s2;
				for(int i=0;i<n;i++)
				{
					if(i&1){s1+=C[(j%2)*2+1]; s2+=C[(j%2)*2];}
					else{s2+=C[(j%2)*2+1]; s1+=C[(j%2)*2];}
				}
				string c="";
				for(int i=0;i<n;i++) c+=vec[i][j];
				int d1=dist(s1,c); int d2=dist(s2,c);
				if(d1<d2)
				{
					for(int i=0;i<n;i++) res[i][j]=s1[i];
				}
				else
				{
					for(int i=0;i<n;i++) res[i][j]=s2[i];
				}
				r+=min(d1,d2);
			}
			if(r<mn)
			{
				mn=r; ans=res;
			}
		}
	}while(next_permutation(C.begin(),C.end()));
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<'\n';
	}
}