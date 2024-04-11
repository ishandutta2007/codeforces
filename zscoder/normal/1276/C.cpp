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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi A[444444];
int f[444444];
vector<vi> b;
ii way[444444];
int ex[444444];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	map<int,int> ma;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; ma[x]++;
	}
	for(int i=1;i<=400000;i++) way[i]=mp(-int(1e9),-int(1e9));
	for(auto X:ma) 
	{
		f[X.se]++;
	}
	for(int i=1;i<=400000;i++)
	{
		for(int j=1;j*i<=400000;j++)
		{
			A[min(i,j)].pb(i*j);
			if(min(i,j)>=min(way[i*j].fi,way[i*j].se))
			{
				way[i*j]=mp(i,j);
			}
		}
	}
	set<int> S;
	int cnt=n;
	int ans=0;
	int L,R; L=R=0;
	for(int i=n;i>=1;i--)
	{
		//dimensions at least i 
		for(auto x:A[i]) 
		{
			if(ex[x]) continue;
			ex[x]=1;S.insert(x);
		}
		auto it = S.upper_bound(cnt);
		if(it!=S.begin())
		{
			it--;
			int siz = (*it);
			int l = way[siz].fi;
			int r = way[siz].se;
			if(siz>ans)
			{
				L=l; R=r; ans=siz;
			}
		}
		cnt-=f[i];
		f[i-1]+=f[i];
		f[i]=0;
	}	
	cout<<ans<<'\n';
	if(L>R) swap(L,R);
	cout<<L<<' '<<R<<'\n';
	vi V;
	vector<ii> tmp;
	for(auto X:ma)
	{
		tmp.pb({min(L,min(R,X.se)),X.fi});
	}
	sort(tmp.rbegin(),tmp.rend());
	for(ii x:tmp)
	{
		for(int i=0;i<x.fi;i++)
		{
			if(V.size()<ans) V.pb(x.se);
		}
	}
	/*
	for(auto X:ma)
	{
		for(int i=0;i<min(L,min(R,X.se));i++)
		{
			if(V.size()<ans) V.pb(X.fi);
		}
	}
	*/
	b.resize(L);
	for(int i=0;i<L;i++)
	{
		b[i].resize(R);
	}
	for(int i=0;i<V.size();i++)
	{
		b[i%L][(i/L+i%L)%R]=V[i];
	}
	for(int i=0;i<L;i++)
	{
		for(int j=0;j<R;j++)
		{
			cout<<b[i][j]<<' ';
		}
		cout<<'\n';
	}
}