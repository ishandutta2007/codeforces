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

int a[111111];
int col[555];
int siz[555];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k; k--;
	memset(col,-1,sizeof(col));
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(col[a[i]]>=0)
		{
			a[i]=col[a[i]]; continue;
		}
		int cur = a[i];
		for(int j=a[i];j>=a[i]-k;j--)
		{
			//if(col[j]>=0) break;
			//cur = j;
			if(col[j]==-1) cur=j;
			else if(a[i]-col[j]<=k)
			{
				cur = col[j];
				break;
			}
			else break;
		}
		
		for(int j=cur;j<=a[i];j++)
		{
			col[j] = cur;
		}
		a[i] = cur;
		//col[a[i]] = cur;
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}