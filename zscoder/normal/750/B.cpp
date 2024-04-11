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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	ll pos = 0;
	for(int i = 0; i < n; i++)
	{
		ll t; cin>>t;
		string s; cin>>s;
		int dir = 0;
		if(s[0]=='S') dir=0;
		else if(s[0]=='E') dir=1;
		else if(s[0]=='N') dir=2;
		else dir=3; //W
		if(pos==0)
		{
			if(dir!=0)
			{
				cout<<"NO";
				return 0;
			}
			else
			{
				pos+=t;
				if(pos>20000)
				{
					cout<<"NO";
					return 0;
				}
			}
		}
		else if(pos==20000)
		{
			if(dir!=2)
			{
				cout<<"NO";
				return 0;
			}
			else
			{
				pos-=t;
				if(!(pos>=0&&pos<=20000))
				{
					cout<<"NO";
					return 0;
				}
			}
		}
		else
		{
			if(dir==0)
			{
				pos+=t;
			}
			else if(dir==2)
			{
				pos-=t;
			}
			if(!(pos>=0&&pos<=20000))
			{
				cout<<"NO"; return 0;
			}
		}
	}
	if(pos==0)
	{
		cout<<"YES"; 
	}
	else
	{
		cout<<"NO";
	}
}