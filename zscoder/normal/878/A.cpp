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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int bit[10][2];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<2;j++)
		{
			bit[i][j]=j;
		}
	}
	for(int i=0;i<n;i++)
	{
		char c; cin>>c;
		int x; cin>>x;
		for(int j=0;j<10;j++)
		{
			for(int k=0;k<2;k++)
			{
				if(c=='^')
				{
					if(x&(1<<j))
					{
						bit[j][k]^=1;
					}
				}
				else if(c=='&')
				{
					if(!(x&(1<<j)))
					{
						bit[j][k]=0;
					}
				}
				else
				{
					if(x&(1<<j))
					{
						bit[j][k]=1;
					}
				}
			}
		}
	}
	int O=0;
	int A=(1<<10)-1;
	int X=0;
	for(int i=0;i<10;i++)
	{
		if(bit[i][0]&&bit[i][1])
		{
			O|=(1<<i);
		}
		else if(!bit[i][0]&&!bit[i][1])
		{
			A^=(1<<i);
		}
		else if(bit[i][0])
		{
			X^=(1<<i);
		}
	}
	cout<<3<<'\n';
	cout<<"^ "<<X<<'\n';
	cout<<"& "<<A<<'\n';
	cout<<"| "<<O<<'\n';
}