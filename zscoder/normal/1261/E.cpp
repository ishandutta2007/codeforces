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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef bitset<1030> b100;
int a[1111];
b100 b[1111];

void solve(vi vec, int l) //solve for the columns in vec
{
	int n=vec.size();
	if(n==0) return ;
	vi nw,cur;
	int mx=0; int mxid=vec[0];
	for(int x:vec)
	{
		if(a[x]>=n) cur.pb(x);
		else nw.pb(x);
	}
	for(int i=0;i<vec.size();i++)
	{
		if(a[vec[i]]>mx)
		{
			mx=a[vec[i]];
			mxid=vec[i];
		}
	}
	//0000000 (if any) appears at the bottom
	if(mx<n)
	{
		vi nw;
		nw.clear();
		for(int x:vec)
		{
			if(x==mxid) continue;
			nw.pb(x);
		}
		solve(nw,l+1);
		for(int i=l;i<l+mx;i++) 
		{
			b[i][mxid]=1;
		}
		return ;
	}
	for(int x:vec)
	{
		if(a[x]==n)
		{
			a[x]--; b[l][x]=1;
		}
	}
	nw.clear();
	for(int x:vec)
	{
		if(x==mxid) continue;
		nw.pb(x);
	}
	solve(nw,l+1);
	bool pos=0;
	for(int i=l+1;i<=l+n;i++)
	{
		b[i][mxid]=1;
		if(b[l]==b[i]) 
		{
			pos=1; b[i][mxid]=0;
		}
	}
	if(!pos)
	{
		b[l+n][mxid]=0;
	}
	return ;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	 vi v;
	for(int i=0;i<n;i++) v.pb(i);
	solve(v,0);
	vector<string> res;
	for(int i=0;i<=n;i++)
	{
		string s="";
		int pos=0;
		for(int j=0;j<n;j++)
		{
			s+=b[i][j]+'0';
			if(b[i][j]) pos=1;
		}
		if(pos) res.pb(s);
	}
	cout<<res.size()<<'\n';
	for(string &s:res) cout<<s<<'\n';
}