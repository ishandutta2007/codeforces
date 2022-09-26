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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int a[1001][5];
int b[1001][1001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<5;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<5;k++)
			{
				b[i][j]+=a[i][k]*a[j][k];
			}
		}
	}
	vi vec;
	for(int i=0;i<n;i++)
	{
		int s1=0;
		for(int j=0;j<5;j++) s1+=a[i][j]*a[i][j];
		bool pos=0;
		for(int j=0;j<n;j++)
		{
			if(j==i) continue;
			for(int k=0;k<n;k++)
			{
				if(j==k||i==k) continue;
				int s=s1+b[j][k];
				for(int l=0;l<5;l++)
				{
					s-=a[i][l]*(a[j][l]+a[k][l]);
				}
				if(s>0) pos=1;
				if(pos) break;
			}
			if(pos) break;
		}
		if(!pos) vec.pb(i);
	}
	cout<<vec.size()<<'\n';
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i]+1;
		if(i+1<vec.size()) cout<<' ';
	}
	if(!vec.empty()) cout<<'\n';
}