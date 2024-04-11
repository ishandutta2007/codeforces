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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q; cin>>q;
	while(q--)
	{
		int n; cin>>n;
		if(n<4)
		{
			cout<<-1<<'\n';
		}
		else
		{
			if(n%4==0)
			{
				cout<<n/4<<'\n';
			}
			else if(n%4==2)
			{
				cout<<n/4<<'\n';
			}
			else if(n%4==1)
			{
				if(n<=5) cout<<-1<<'\n';
				else cout<<(n-5)/4<<'\n';
			}
			else
			{
				if(n<=11) cout<<-1<<'\n';
				else cout<<(n-7)/4<<'\n';
			}
		}
	}
}