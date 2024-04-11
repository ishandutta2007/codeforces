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
	//ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("snacktower.txt","r",stdin);
	int n; scanf("%d",&n);
	set<int> s;
	int cur = n;
	for(int i = 0; i < n; i++)
	{
		int x; scanf("%d",&x);
		if(x==cur)
		{
			vi vec;
			vec.pb(x);
			cur--;
			for(sit it = s.begin(); it != s.end(); it++)
			{
				if(-(*it)==cur)
				{
					vec.pb(-(*it));
					cur--;
				}
				else break;
			}
			for(int i = 0; i < vec.size(); i++)
			{
				printf("%d", vec[i]);
				if(i>0) s.erase(-vec[i]);
				if(i+1<vec.size()) printf(" ");
			}
			puts("");
		}
		else 
		{
			puts("");
			s.insert(-x);
		}
	}
}