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

int get()
{
	int x; cin>>x; return x;
}

void out(int x)
{
	cout<<x+1<<'\n'; fflush(stdout);
}

int a[1111];

int main()
{
	memset(a,-1,sizeof(a));
	int n,m,c; cin>>n>>m>>c;
	for(int z=0;z<m;z++)
	{
		int x = get();
		if(x<=c/2)
		{
			int pos=-1;
			for(int i=0;i<n;i++)
			{
				if(a[i]==-1)
				{
					pos=i; break;
				}
				if(x>=a[i]) continue;
				pos=i; break;
			}
			out(pos); a[pos]=x;
		}
		else
		{
			int pos=-1;
			for(int i=n-1;i>=0;i--)
			{
				if(a[i]==-1)
				{
					pos=i; break;
				}
				if(x<=a[i]) continue;
				pos=i; break;
			}
			out(pos); a[pos]=x;
		}
		bool pos=1;
		for(int i=0;i+1<n;i++)
		{
			if(a[i]==-1){pos=0; break;}
			if(a[i]>a[i+1])
			{
				pos=0; break;
			}
		}
		if(pos) return 0;
	}
}