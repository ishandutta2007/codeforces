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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
ll A[10];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int x = (a*8)+(b*4)+(c*2)+d;
	if(x==6) 
	{
		cout<<0;
		return 0;
	}
	if(x==0)
	{
		cout<<0;
		return 0;
	}
	if(x==8)
	{
		cout<<1;
		return 0;
	}
	if(x==4)
	{
		cout<<0;
		return 0;
	}
	if(x==12)
	{
		cout<<1;
		return 0;
	}
	if(x==2)
	{
		cout<<0;
		return 0;
	}
	if(x==10)
	{
		cout<<0;
		return 0;
	}
	if(x==14)
	{
		cout<<1;
		return 0;
	}
	if(x==1)
	{
		cout<<1;
		return 0;
	}
	if(x==9)
	{
		cout<<1;
		return 0;
	}
	if(x==5)
	{
		cout<<0;
		return 0;
	}
	if(x==13)
	{
		cout<<0;
		return 0;
	}
	if(x==11)
	{
		cout<<1;
		return 0;
	}
	if(x==7)
	{
		cout<<0;
		return 0;
	}
	if(x==3)
	{
		cout<<1;
		return 0;
	}
	if(x==15)
	{
		cout<<1;
		return 0;
	}
	for(int i = 0; i < x; i++)
	{
		A[0]=1;A[1]=2;
		for(ll j = 0; j < ll(7e7); j++)
		{
			swap(A[0],A[1]);
		}
	}
}