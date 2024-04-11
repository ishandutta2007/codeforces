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

ll a[111111];
ll tmp[111111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,d; ll b;
	cin>>n>>d>>b;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; tmp[i]=a[i];
	}
	int lo=0; int hi=n;
	int ans=0;
	while(lo<=hi)
	{
		int mid=(lo+hi)>>1;
		//is mid possible
		//this means that I want at most mid rooms checked from both sides
		//[0, mid - 1] and [n - mid, n - 1] ignored
		//[mid, n - mid - 1] is the god interval
		if(mid>n-mid-1)
		{
			ans=mid;
			hi=mid-1;
			continue;
		}
		int ptr = 0;
		bool pos=1;
		
		for(int i=mid;i<=(n-1)/2;i++) //left side
		{
			ll cd = i + 1;
			ll cur = b;
			while(ptr<n&&cur>0)
			{
				if(a[ptr]>=cur)
				{
					a[ptr]-=cur; cur=0;
					break;
				}
				else
				{
					cur-=a[ptr];
					a[ptr]=0;
					ptr++;
				}
			}
			int distance = ptr - i;
			if(distance>cd*d)
			{
				pos=0; break;
			}
		}
		
		ptr = n - 1;
		
		for(int i=n-mid-1;i>=(n+1)/2;i--) //right side
		{
			ll cd=n-i;
			ll cur=b;
			while(ptr>=0&&cur>0)
			{
				if(a[ptr]>=cur)
				{
					a[ptr]-=cur; cur=0;
					break;
				}
				else
				{
					cur-=a[ptr];
					a[ptr]=0;
					ptr--;
				}
			}
			int distance = i - ptr;
			if(distance>cd*d)
			{
				pos=0; break;
			}
		}
		
		for(int i=0;i<n;i++)
		{
			a[i]=tmp[i];
		}
		if(pos)
		{
			ans=mid; hi=mid-1;
		}
		else
		{
			lo=mid+1;
		}
	}
	cout<<ans<<'\n';
}