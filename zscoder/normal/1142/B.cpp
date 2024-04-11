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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int R[222222];
int a[222222];
int p[222222];
vi pos[222222];
int nxt[222222];
int st[19][222222];
int fnl[222222];

template<typename TT, int MX, int LG, ll INF> struct SparseTable //Warning : Change query return value manually if needed. INF is the dummy val
{
	TT st[LG][MX];
	TT initial[MX];
	
	TT combine(TT a, TT b) //warning : change if neccesary
	{
		return min(a,b);
	}
	
	SparseTable()
	{
		for(int i = 0; i < MX; i++) initial[i] = INF;
	}
	
	void init()
	{
		for(ll j = 0; j < LG; j++)
		{
			for(ll i = 0; i < MX; i++)
			{
				st[j][i] = INF;
				if(i + (1<<j) - 1 < MX)
				{
					if(j == 0) st[j][i] = initial[i];
					else st[j][i] = combine(st[j-1][i], st[j-1][i + (1<<(j-1))]);
				}
			}
		}
	}
	
	TT query(int l, int r)
	{
		int k = 31 - __builtin_clz(r-l);
		if(l==r) k=0;
		return combine(st[k][l], st[k][r - (1<<k) + 1]);
	}
};

SparseTable<int,222222,19,int(1e9)> S;
int besto[222222];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,q; cin>>n>>m>>q;
	for(int i=0;i<n;i++)
	{
		cin>>p[i]; p[i]--;
	}
	for(int i=0;i<m;i++)
	{
		cin>>a[i]; a[i]--; pos[a[i]].pb(i);
	}
	for(int i=0;i<n;i++) nxt[p[i]]=p[(i+1)%n];
	for(int i=0;i<n;i++) pos[i].pb(m); //m is safety
	for(int i=0;i<m;i++)
	{
		int nt = nxt[a[i]];
		R[i]=(*lower_bound(pos[nt].begin(),pos[nt].end(),i));
		st[0][i]=R[i];
		//cerr<<"R: "<<i<<' '<<R[i]<<'\n';
	}
	st[0][m]=m;
	for(int i=1;i<19;i++)
	{
		for(int j=0;j<=m;j++)
		{
			st[i][j]=st[i-1][st[i-1][j]];
		}	
	}
	for(int i=0;i<m;i++)
	{
		//go n-1 steps forward sia
		int cur=i;
		for(int j=18;j>=0;j--)
		{
			if((n-1)&(1<<j))
			{
				cur=st[j][cur];
			}
		}
		fnl[i]=cur;
		//cerr<<"GG: "<<i<<' '<<fnl[i]<<'\n';
	}
	fnl[m]=besto[m]=m;
	for(int i=m-1;i>=0;i--)
	{
		besto[i]=min(besto[i+1],fnl[i]);
	}
	for(int i=0;i<m;i++) S.initial[i]=fnl[i];
	S.init();
	for(int i=0;i<q;i++)
	{
		int l,r; cin>>l>>r; l--; r--;
		if(n==1){cout<<1; continue;}
		/*
		int res = S.query(l,r);
		*/
		int res=besto[l];
		if(res<=r)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	cout<<'\n';
}