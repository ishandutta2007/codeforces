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
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	int C[2] = {0,0};
	for(int i=0;i<s.length();i++)
	{
		int c = s[i]-'0';
		C[c]++;
		if(c==0)
		{
			if(C[c]==1)
			{
				cout<<3<<' '<<4<<'\n';
			}
			else
			{
				cout<<1<<' '<<4<<'\n';
			}
		}
		else
		{
			if(C[c]==1)
			{
				cout<<1<<' '<<1<<'\n';
			}
			else
			{
				cout<<1<<' '<<3<<'\n';
			}
		}
		C[c]%=2;
	}
}