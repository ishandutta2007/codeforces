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

char a[5][5];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			cin>>a[i][j];
		}
	}
	bool pos=0;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(a[i][j]=='.')
			{
				a[i][j]='x';
				for(int k = 0; k < 4; k++)
				{
					for(int l = 0; l < 2; l++)
					{
						bool tmp=1;
						for(int p = l; p <= l + 2; p++)
						{
							if(a[k][p]!='x')
							{
								tmp=0;break;
							}
						}
						if(tmp)
						{
							pos=1;
						}
					}
				}
				for(int k = 0; k < 4; k++)
				{
					for(int l = 0; l < 2; l++)
					{
						bool tmp=1;
						for(int p = l; p <= l + 2; p++)
						{
							if(a[p][k]!='x')
							{
								tmp=0;break;
							}
						}
						if(tmp)
						{
							pos=1;
						}
					}
				}
				for(int k = 1; k <= 2; k++)
				{
					for(int l = 1; l <= 2; l++)
					{
						if(a[k][l]=='x')
						{
							if(a[k-1][l-1]=='x'&&a[k+1][l+1]=='x')
							{
								pos=1;
							}
							if(a[k-1][l+1]=='x'&&a[k+1][l-1]=='x')
							{
								pos=1;
							}
						}
					}
				}
				a[i][j]='.';
			}
			if(pos) break;
		}
	}
	if(pos)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
}