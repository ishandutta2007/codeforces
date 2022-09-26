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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;
typedef bitset<508> b100;

struct gausselim
{
	int rank;
	b100 cyc[511];
	void init()
	{
		for(int i = 0; i < 505; i++)
		{
			cyc[i].reset();
		}
		rank = 0;
	}
	void add(b100 x)
	{
		for(int i =504;i>=0;i--)
		{
			if(x.count()==0) return ;
			if(x[i])
			{
				if(cyc[i].count()==0)
				{
					cyc[i] = x;
					rank++;
					break;
				}
			}
			if(x[i])
			{
				x^=cyc[i];
			}
			//x = min(x, (x^cyc[i]));
		}	
	}
};

int a[555];
int dist[555];
int par[555];
int parmove[555];
int main()
{
	int n,k; cin>>n>>k;
	/*
	gausselim g;
	for(int i=0;i<(1<<n);i++)
	{
		if(__builtin_popcount(i)==k)
		{
			b100 b;
			for(int j=0;j<n;j++)
			{
				if(i&(1<<j)) b.set(j,1);
			}
			g.add(b);
		}
	}
	cerr<<g.rank<<'\n';
	b100 emp; emp.reset();
	for(int i=0;i<n;i++) emp.set(i,1);
	g.add(emp);
	cerr<<g.rank<<'\n';
	*/
	for(int i=0;i<=n;i++) dist[i]=int(1e9);
	dist[0]=0;
	queue<int> q;q.push(0);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<=min(u,k);i++)
		{
			//i from the u 1s are flipped
			//k-i from the (n-u) 0s are flipped
			if(u>=i&&n-u>=k-i)
			{
				int v = (u-i)+(k-i);
				if(dist[v]>dist[u]+1)
				{
					dist[v]=dist[u]+1;
					par[v]=u;
					parmove[v]=i;
					q.push(v);
				}
			}
		}
	}
	if(dist[n]>=int(1e8)){cout<<-1<<'\n'; fflush(stdout); return 0;}
	vi zero,one;
	for(int i=0;i<n;i++) zero.pb(i);
	int ans=0;
	vi path;
	int cur=n;
	while(cur!=0)
	{
		path.pb(parmove[cur]);
		cur=par[cur];
	}
	reverse(path.begin(),path.end());
	//for(int x:path) cerr<<x<<' ';
	//cerr<<'\n';
	//currently start with 0
	for(int v:path)
	{
		//move v guys from one to zero
		//move k-v guys from zero to one
		//cerr<<one.size()<<' '<<zero.size()<<' '<<v<<'\n';
		vi one2,zero2;
		assert(one.size()>=v);
		for(int i=0;i<v;i++) {one2.pb(one.back()); one.pop_back();}
		assert(zero.size()>=k-v);
		for(int i=0;i<k-v;i++) {zero2.pb(zero.back()); zero.pop_back();}
		cout<<"? ";
		vi tot;
		for(int x:one2) tot.pb(x);
		for(int x:zero2) tot.pb(x);
		for(int i=0;i<k;i++)
		{
			cout<<tot[i]+1;
			if(i+1<k) cout<<' ';
		}
		cout<<'\n'; fflush(stdout);
		int x; cin>>x; ans^=x;
		for(int x:one2) zero.pb(x);
		for(int x:zero2) one.pb(x);
	}
	cout<<"! "<<ans<<'\n'; fflush(stdout);
}