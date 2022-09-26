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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

double calc(int x)
{
	return sqrt(double(abs(x)))+5.0*double(x)*x*x;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int x;
	stack<int> S;
	while(scanf("%d",&x)==1)
	{
		S.push(x);
	}
	while(!S.empty())
	{
		int x=S.top();
		double res = calc(S.top()); S.pop();
		if(res>=400.0) printf("f(%d) = MAGNA NIMIS!\n",x);
		else printf("f(%d) = %.2f\n",x,res);
	}
}