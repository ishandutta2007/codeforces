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

ll a[555555];
ll b[555555];

int getbit(int x, int n)
{
	while(x>=n) x-=n;
	while(x<0) x+=n;
	return x;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++) 
	{
		cin>>b[i]; 
		//b[i]=i;
	}
	bool exnonzero=0;
	for(int i=0;i<n;i++)
	{
		if(b[i]!=0)
		{
			exnonzero=1; break;
		}
	}
	if(!exnonzero)
	{
		cout<<"YES\n";
		for(int i=0;i<n;i++)
		{
			cout<<1;
			if(i+1<n) cout<<' ';
		}
		cout<<'\n'; return 0;
	}
	for(int i=0;i<n;i++)
	{
		b[i+n] = b[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i-1]<b[i])
		{
			//set a[i] = b[i]
			a[getbit(i,n)] = b[getbit(i,n)];
			int j=getbit(i-1,n);
			while(j!=getbit(i,n))
			{
				if(j==getbit(i-1,n))
				{
					a[j] = ll(200000)*a[getbit(j+1,n)] + b[j];
				}
				else
				{
					ll rem = b[j];
					ll quo = a[getbit(j+1,n)];
					a[j] = quo + rem;
				}
				j=getbit(j-1,n);
			}			
			for(int i=0;i<n;i++)
			{
				assert(a[i]%a[(i+1)%n]==b[i]);
			}
			cout<<"YES\n";
			for(int i=0;i<n;i++)
			{
				cout<<a[i];
				if(i+1<n) cout<<' ';
			}
			cout<<'\n';
			return 0;
		}
	}
	cout<<"NO\n";
}