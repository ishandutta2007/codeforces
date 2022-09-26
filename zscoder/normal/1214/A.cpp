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
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi a = {1,2,5,10,20,50,100};
vi b = {5,10,20,50,100,200};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; 
	int d,e; cin>>n>>d>>e;
	int A = a[0]*d;
	int B = b[0]*e;
	set<int> S;
	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<1000;j++)
		{
			S.insert(A*i+B*j);
		}
	}
	int mx=A*999+B*999;
	for(int i=0;i<d;i++)
	{
		int rem = n-i;
		if(rem%__gcd(A,B)==0)
		{
			if(rem>=mx)
			{
				cout<<i<<'\n'; return 0;
			}
			if(S.find(rem)!=S.end())
			{
				cout<<i<<'\n'; return 0;
			}
		}
	}
}