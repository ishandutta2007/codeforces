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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

template<typename TT, int MX, int LG, ll INF> struct SparseTable //Warning : Change query return value manually if needed. INF is the dummy val
{
	TT st[LG][MX];
	TT initial[MX];
	
	TT combine(TT a, TT b) //warning : change if neccesary
	{
		if(a<b) return a;
		return b;
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

SparseTable<int,222222,19,int(1e9)+100> st;
int a[222222];
int nxt[222222];
int dp[222222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<ii> vec;
	int mn=int(1e9); int mx=-1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; a[n+i]=a[i]; vec.pb({a[i],i});
		mn=min(mn,a[i]); mx=max(mx,a[i]);
	}
	if(mn*2>=mx)
	{
		for(int i=0;i<n;i++)
		{
			cout<<-1;
			if(i+1<n) cout<<' ';
		}
		cout<<'\n';
		return 0;
	}
	for(int i=0;i<2*n;i++) st.initial[i]=a[i];
	st.init();
	for(int i=0;i<2*n;i++)
	{
		int lo=i; int hi=2*n-1;
		int ans=2*n;
		while(lo<=hi)
		{
			int mid=(lo+hi)>>1;
			if(st.query(i,mid)*2<a[i])
			{
				ans=mid; hi=mid-1;
			}
			else lo=mid+1;
		}
		nxt[i]=ans;
	}
	sort(vec.rbegin(),vec.rend());
	set<int> S;
	for(int z=0;z<n;z++)
	{
		int i=vec[z].se;
		int nxtdeath=nxt[i];
		int nxtlarger=2*n+1;
		auto it = S.lower_bound(i+1);
		if(it!=S.end())
		{
			nxtlarger=(*it);
		}
		if(nxtlarger<nxtdeath)
		{
			dp[i]=nxtlarger-i+dp[nxtlarger];
		}
		else
		{
			dp[i]=nxtdeath-i;
		}
		dp[n+i]=dp[i];
		S.insert(i); S.insert(n+i);
	}
	for(int i=0;i<n;i++)
	{
		cout<<dp[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}