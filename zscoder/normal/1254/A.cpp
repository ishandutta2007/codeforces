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

char a[111][111];

void solve()
{
	int n,m,k; cin>>n>>m>>k;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='R') cnt++;
		}
	}
	int q = cnt/k;
	int r = cnt%k;
	vector<char> C;
	for(int i=0;i<26;i++)
	{
		C.pb('a'+i); C.pb('A'+i);
	}
	for(int i=0;i<10;i++) C.pb('0'+i);
	int cur=0;
	vi v(k);
	for(int i=0;i<k;i++)
	{
		if(i<r) v[i]=q+1;
		else v[i]=q;
		//cerr<<v[i]<<' ';
	}
	//cerr<<'\n';
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<m;j++)
			{
				if(a[i][j]=='R')
				{
					if(v[cur]<=0) cur++;
					v[cur]--;
				}
				a[i][j]=C[cur];
			}
		}
		else
		{
			for(int j=m-1;j>=0;j--)
			{
				if(a[i][j]=='R')
				{
					if(v[cur]<=0) cur++;
					v[cur]--;
				}
				a[i][j]=C[cur];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<a[i][j];
		}
		cout<<'\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}