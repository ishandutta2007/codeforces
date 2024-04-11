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
	ll x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	ll x=abs(x1-x2); ll y=abs(y1-y2);
	if(x>y) swap(x,y);
	if(x==0)
	{
		cout<<2*(y+3)<<'\n';
	}
	else
	{
		cout<<2*(x+y+2)<<'\n';
	}
}