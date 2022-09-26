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
	int n, k, g, b;
	cin>>n>>k>>g>>b;
	char c = 'G'; char d = 'B';
	if(g<b)
	{
		swap(c,d);
		swap(g,b);
	}
	int tmp = (g+b)/(b+1);
	if(tmp>k)
	{
		cout<<"NO";
		return 0;
	}
	int rem = g%(b+1);
	if(rem==0) rem = b+1;
	for(int i = 0; i < b + 1; i++)
	{
		if(i<rem)
		{
			for(int j = 0; j < tmp; j++)
			{
				cout<<c;
			}
		}
		else
		{
			for(int j = 0; j < tmp-1; j++)
			{
				cout<<c;
			}
		}
		if(i<b) cout<<d;
	}
}