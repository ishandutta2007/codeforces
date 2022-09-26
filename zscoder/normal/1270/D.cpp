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

ii query(vi v)
{
	cout<<"? ";
	for(int x:v)
	{
		cout<<x+1<<' ';
	}
	cout<<'\n';
	fflush(stdout);
	int x,y; cin>>x>>y;
	return {x,y};
}

void answer(int m)
{
	cout<<"! "<<m<<'\n';
	fflush(stdout);
}

int main()
{
	int n,k; cin>>n>>k;
	vi V;
	for(int i=0;i<k+1;i++)
	{
		vi v;
		for(int j=0;j<k+1;j++)
		{
			if(j==i) continue;
			v.pb(j);
		}
		ii tmp = query(v);
		V.pb(tmp.se);
	}
	sort(V.begin(),V.end());
	int ans=0;
	for(int i=0;i<V.size();i++)
	{
		if(V[i]==V.back()) ans++;
	}
	answer(ans);
}