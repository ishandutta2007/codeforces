#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ii INF={-int(1e9),-int(1e9)};
template<typename TT, int MX, int LG> struct SparseTable //Warning : Change query return value manually if needed. INF is the dummy val
{
	ii st[LG][MX];
	ii initial[MX];
	
	TT combine(TT a, TT b) //warning : change if neccesary
	{
		return max(a,b);
	}
	
	SparseTable()
	{
		for(int i = 0; i < MX; i++) initial[i] = INF;
	}
	
	void init(int n)
	{
		for(int j = 0; j < LG; j++)
		{
			for(int i = 0; i < n; i++)
			{
				st[j][i] = INF;
				if(i + (1<<j) - 1 < n)
				{
					if(j == 0) st[j][i] = initial[i];
					else st[j][i] = combine(st[j-1][i], st[j-1][i + (1<<(j-1))]);
				}
			}
		}
	}
	
	void reset(int n)
	{
		for(ll j = 0; j < LG; j++)
		{
			for(ll i = 0; i < n; i++)
			{
				st[j][i]=INF;
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
SparseTable<ii,555555,20> st;
int a[555555];
bool pos=1;

void solve(int l, int r, int mx)
{
	//cerr<<l<<' '<<r<<' '<<mx<<'\n';
	if(l>r) return ;
	ii tmp = st.query(l,r);
	if(tmp.fi<0)
	{
		for(int i=l;i<=r;i++)
		{
			a[i]=mx; mx--;
		}
		return ;
	}
	int pos=-tmp.se; int nt=tmp.fi;
	//cerr<<pos<<' '<<nt<<'\n';
	if(nt>r)
	{
		a[pos]=mx;
		mx--;
		solve(l,pos-1,mx);
		mx-=pos-l;
		solve(pos+1,r,mx);
	}
	else
	{
		pos=nt;
		a[pos]=mx;
		mx--;
		solve(l,pos-1,mx);
		mx-=pos-l;
		solve(pos+1,r,mx);
	}
}

void solve_case()
{
	int n; cin>>n;
	vi nxt(n);
	for(int i=0;i<n;i++) 
	{
		cin>>nxt[i];
		if(nxt[i]>=0) nxt[i]--;
	}
	for(int i=0;i<n;i++)
	{
		st.initial[i]=mp(nxt[i],-i);
	}
	st.init(n);
	pos=1;
	solve(0,n-1,n-1);
	st.reset(n);
	set<int> S;
	vi posi(n,0);
	if(!pos){cout<<-1<<'\n'; return ;}
	for(int i=0;i<n;i++) posi[a[i]]=i;
	for(int i=n-1;i>=0;i--)
	{
		int nt = n;
		auto lb = S.upper_bound(posi[i]);
		if(lb!=S.end()) nt=(*lb);
		if(nxt[posi[i]]!=-1&&nxt[posi[i]]!=nt){cout<<-1<<'\n'; return ;}
		S.insert(posi[i]);
	}
	for(int i=0;i<n;i++){cout<<a[i]+1; if(i+1<n)cout<<' ';} cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		solve_case();
	}
}