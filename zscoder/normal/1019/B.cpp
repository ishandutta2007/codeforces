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

void out(int x)
{
	cout<<"! "<<x<<'\n'; fflush(stdout); exit(0);
}
int ma[333333];
int query(int x)
{
	if(ma[x]>=-int(1e9)) return ma[x];
	cout<<"? "<<x+1<<'\n';
	fflush(stdout);
	int z; cin>>z; return (ma[x]=z);
}
int n;
int getdiff(int x)
{
	int res = query(x)-query((x+n/2)%n);
	if(res==0)
	{
		out(x+1);
	}
	return res;
}
int sign(int x)
{
	if(x<=0) return -1;
	else return 1;
}
int main()
{
	cin>>n; 
	for(int i=0;i<n;i++)
	{
		ma[i] = -int(1e9)-1000000;
	}
	if(n%4==2)
	{
		out(-1);
	}
	int lo = 0; int hi = n/2; getdiff(hi);
	while(lo<=hi)
	{
		int mid = (lo+hi)>>1;
		int x = getdiff(mid);
		if(sign(x)==sign(getdiff(hi)))
		{
			hi=mid-1;
		}
		else
		{
			lo=mid+1;
		}
	}
}