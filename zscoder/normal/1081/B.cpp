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

int a[222222];
vi V[222222];
int cnt[222222];
int ans[222222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i]; a[i]=n-a[i];
	}
	for(int i=0;i<n;i++)
	{
		V[a[i]].pb(i);
	}
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		if(int(V[i].size())%i==0)
		{
			for(int j=0;j<V[i].size();j+=i)
			{
				for(int k=j;k<j+i;k++)
				{
					ans[V[i][k]]=cnt;
				}
				cnt++;
			}
		}
		else{cout<<"Impossible\n"; return 0;}
	}
	cout<<"Possible\n";
	for(int i=0;i<n;i++)
	{
		cout<<ans[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}