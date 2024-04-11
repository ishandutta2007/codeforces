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

int F[1111111];
bool visited[1111111];

void solve()
{
	vector<ii> P,N,Z;
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
		if(x==0) Z.pb({x,i});
		else if(x>0) P.pb({x,i});
		else N.pb({x,i});
		F[i]=i-x;
	}
	for(int i=0;i<=n;i++) visited[i]=0;
	if(!Z.empty())
	{
		cout<<1<<'\n'<<Z[0].se+1<<'\n'; return ;
	}
	vi vec;
	int cur=0;
	vi C;
	while(!visited[cur])
	{
		visited[cur]=1;
		C.pb(cur);
		cur=F[cur];
	}
	bool p=0;
	for(int i=0;i<C.size();i++)
	{
		if(C[i]==cur) p=1;
		if(p) vec.pb(C[i]);
	}
	cout<<vec.size()<<'\n';
	for(int x:vec)
	{
		cout<<x+1<<' ';
	}
	cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}