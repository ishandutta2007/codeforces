#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int F[6] = {4,8,15,16,23,42};
int a[6];

int main()
{
	map<int,ii> ma;
	for(int i=0;i<6;i++)
	{
		for(int j=i+1;j<6;j++)
		{
			ma[F[i]*F[j]]=mp(i,j);
		}
	}
	{
		cout<<"? 1 2\n"; fflush(stdout);
		int x; cin>>x;
		ii tmp = ma[x];
		cout<<"? 1 3\n"; fflush(stdout);
		cin>>x;
		ii tmp2 = ma[x];
		if(tmp.fi==tmp2.fi)
		{
			a[0]=F[tmp.fi];
			a[1]=F[tmp.se];
			a[2]=F[tmp2.se];
		}
		else if(tmp.fi==tmp2.se)
		{
			a[0]=F[tmp.fi];
			a[1]=F[tmp.se];
			a[2]=F[tmp2.fi];
		}
		else if(tmp.se==tmp2.fi)
		{
			a[0]=F[tmp.se];
			a[1]=F[tmp.fi];
			a[2]=F[tmp2.se];
		}
		else
		{
			a[0]=F[tmp.se];
			a[1]=F[tmp.fi];
			a[2]=F[tmp2.fi];
		}
	}
	{
		cout<<"? 4 5\n"; fflush(stdout);
		int x; cin>>x;
		ii tmp = ma[x];
		cout<<"? 4 6\n"; fflush(stdout);
		cin>>x;
		ii tmp2 = ma[x];
		if(tmp.fi==tmp2.fi)
		{
			a[3]=F[tmp.fi];
			a[4]=F[tmp.se];
			a[5]=F[tmp2.se];
		}
		else if(tmp.fi==tmp2.se)
		{
			a[3]=F[tmp.fi];
			a[4]=F[tmp.se];
			a[5]=F[tmp2.fi];
		}
		else if(tmp.se==tmp2.fi)
		{
			a[3]=F[tmp.se];
			a[4]=F[tmp.fi];
			a[5]=F[tmp2.se];
		}
		else
		{
			a[3]=F[tmp.se];
			a[4]=F[tmp.fi];
			a[5]=F[tmp2.fi];
		}
	}
	
	cout<<"! ";
	for(int i=0;i<6;i++)
	{
		cout<<a[i];
		if(i+1<6) cout<<' ';
	}
	cout<<'\n'; fflush(stdout);
}