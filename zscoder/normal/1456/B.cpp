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

int a[111111];
int X[111111];

int getxor(int l, int r)
{
	if(l==0) return X[r];
	else return X[r]^X[l-1];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	int ans=int(1e9);
	X[0]=a[0];
	for(int i=1;i<n;i++) X[i]=X[i-1]^a[i];
	for(int i=0;i<n;i++)
	{
		for(int len=2;len<=65;len++)
		{
			int l=i; int r=i+len-1;
			if(r>=n) continue;
			int xr=getxor(l,r);
			if(l>0&&a[l-1]>xr) ans=min(ans,len-1);
			if(r+1<n&&a[r+1]<xr) ans=min(ans,len-1);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int len=2;len<=5;len++)
		{
			for(int len2=2;len2<=5;len2++)
			{
				int l1=i; int r1=i+len-1;
				int l2=r1+1; int r2=l2+len2-1;
				if(r2>=n) continue;
				int xr1=0; int xr2=0;
				for(int j=l1;j<=r1;j++)
				{
					xr1^=a[j];
				}
				for(int j=l2;j<=r2;j++)
				{
					xr2^=a[j];
				}
				if(xr1>xr2) ans=min(ans,len-1+len2-1);
			}
		}
	}
	if(ans>=int(1e9)) ans=-1;
	cout<<ans<<'\n';
}