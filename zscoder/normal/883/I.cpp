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
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

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

template<typename TT, int MX, int LG, ll INF> struct SparseTable2 //Warning : Change query return value manually if needed. INF is the dummy val
{
	TT st[LG][MX];
	TT initial[MX];
	
	TT combine(TT a, TT b) //warning : change if neccesary
	{
		return max(a,b);
	}
	
	SparseTable2()
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

int a[300111];

int cost(int l, int r)
{
	return a[r]-a[l];
}

int best[300111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int ans=-1;
	int n,k; cin>>n>>k;
	vector<int> vec;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		vec.pb(a[i]);
	}
	sort(a,a+n);
	sort(vec.begin(),vec.end());
	int lo=0; int hi=int(1e9)+1;
	while(lo<=hi)
	{
		int mid=(lo+hi)>>1;
		for(int i=0;i<n;i++)
		{
			best[i]=-1;
		}
		for(int i=n-1;i>=0;i--)
		{
			int lo2=i+k-1;
			int mid2=lower_bound(vec.begin(),vec.end(),a[i]+mid+1)-vec.begin();
			mid2--;
			if(mid2>=lo2)
			{
				best[i]=mid2;
			}
			/*
			while(lo2<=hi2)
			{
				int mid2=(lo2+hi2)>>1;
				if(cost(i,mid2)<=mid)
				{
					best[i]=mid2;
					lo2=mid2+1;
				}
				else
				{
					hi2=mid2-1;
				}
			}
			*/
			//cerr<<mid<<' '<<i<<' '<<best[i]<<'\n';
		}
		set<int> S;
		S.insert(n);
		for(int i=n-1;i>=0;i--)
		{
			int r = best[i];
			if(r<0) continue;
			auto it = S.lower_bound(i+k);
			if(it==S.end()) continue;
			int tmp=(*it);
			if(tmp<=r+1)
			{
				S.insert(i);
			}
		}
		if(S.find(0)==S.end())
		{
			lo=mid+1;
		}
		else
		{
			ans=mid;
			hi=mid-1;
		}
	}
	cout<<ans<<'\n';
	
}