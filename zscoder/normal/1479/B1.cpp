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
typedef double ld; 
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi pos[222222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		pos[a[i]].pb(i);
	}
	for(int i=0;i<=n;i++) pos[i].pb(int(1e9));
	/*
		if(i==0||(i>0&&a[i]!=a[i-1]))
		{
			b.pb(a[i]);
		}
		if(i==1&&a[i]==a[i-1])
		{
			cnt++;
		}
		else if(i>1&&a[i]==a[i-1]&&a[i-1]!=a[i-2])
		{
			cnt++;
		}
	}
	cnt+=b.size();
	*/
	vector<int> F[2];
	for(int i=0;i<n;i++)
	{
		vi lul;
		for(int z=0;z<2;z++)
		{
			if(F[z].empty())
			{
				lul.pb(z);
				//F[z].pb(a[i]); break;
			}
			else if(F[z].back()!=a[i])
			{
				lul.pb(z);
				//F[z].pb(a[i]); break;
			}
		}
		if(lul.empty()) continue;
		if(lul.size()==1)
		{
			F[lul[0]].pb(a[i]);
			continue;
		}
		assert(lul.size()==2);
		if(F[0].empty())
		{
			F[1].pb(a[i]);
			continue;
		}
		if(F[1].empty())
		{
			F[0].pb(a[i]);
			continue;
		}
		assert(!F[0].empty());
		assert(!F[1].empty());
		//neither is empty
		int u = F[0].back();
		int v = F[1].back();
		int nxtu = lower_bound(pos[u].begin(),pos[u].end(),i+1)-pos[u].begin();
		int nxtv = lower_bound(pos[v].begin(),pos[v].end(),i+1)-pos[v].begin();
		//cerr<<nxtu<<' '<<nxtv<<endl;
		nxtu=pos[u][nxtu]; nxtv=pos[v][nxtv];
		if(nxtu<nxtv)
		{
			F[0].pb(a[i]);
		}
		else
		{
			F[1].pb(a[i]);
		}
	}
	cout<<F[0].size()+F[1].size()<<'\n';
}