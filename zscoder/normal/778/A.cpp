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

int p[200001];
bool issubseq(string a, string b) //is a inside b
{
	if(a.empty())
	{
		return 1;
	}
	if(b.empty())
	{
		return 0;
	}
	int ptr = 0;
	for(int i=0;i<a.length();i++)
	{
		while(ptr<b.length()&&a[i]!=b[ptr])
		{
			ptr++;
		}
		if(ptr>=b.length()) return 0;
		ptr++;
	}
	return 1;
}

bool used[200001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string a,b; cin>>a>>b;
	int n = a.length();
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
		p[i]--;
	}
	int lo = 0; int hi = n - 1;
	int ans = -1;
	while(lo<=hi)
	{
		int mid = (lo+hi)>>1;
		memset(used,0,sizeof(used));
		for(int i=0;i<mid;i++)
		{
			used[p[i]]=1;
		}
		string t;
		for(int i=0;i<n;i++)
		{
			if(!used[i]) t+=a[i];
		}
		if(issubseq(b,t))
		{
			lo=mid+1;
			ans=mid;
		}
		else
		{
			hi=mid-1;
		}
	}
	cout<<ans;
}