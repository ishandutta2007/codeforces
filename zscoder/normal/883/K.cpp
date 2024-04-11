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

ll a[250001];
ll ans[250001];
ll L[250001];
ll R[250001];

template<typename TT, int MX, int LG, ll INF> struct SparseTable //Warning : Change query return value manually if needed. INF is the dummy val
{
	TT st[LG][MX];
	TT initial[MX];
	TT best[LG][MX];
	
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
				if(j>0) best[j][i] = best[j-1][i];
				if(i + (1<<j) - 1 < MX)
				{
					if(j == 0) 
					{
						st[j][i] = initial[i];
						best[j][i] = i;
					}
					else 
					{
						if(st[j-1][i] < st[j-1][i + (1<<(j-1))])
						{
							best[j][i] = best[j-1][i];
							st[j][i]=st[j-1][i];
						}
						else
						{
							best[j][i] = best[j-1][i+(1<<(j-1))];
							st[j][i]=st[j-1][i+(1<<(j-1))];
						}
					}
				}
			}
		}
	}
	
	TT query(int l, int r)
	{
		int k = 31 - __builtin_clz(r-l);
		if(l==r) k=0;
		if(st[k][l] < st[k][r - (1<<k) + 1]) return best[k][l];
		else return best[k][r - (1<<k) + 1];
	}
};

SparseTable<int,222222,19,int(1e9)> st;
int n; 
void solve(int l, int r, int offl, int offr)
{
	if(l>r) return ;
	/*
	if(l==0)
	{
		int mid = st.query(l,r);
		//we know what mid is now
		int res = R[mid];
		if(off==-1)
		{
			ans[mid]=res;
			solve(0,mid-1,res);
			solve(mid+1,n-1,res);
		}
		else
		{
			int diff = r - mid + 1;
			//maximum possible value of mid is off + diff
			if(res>=off+diff)
			{
				int cnt = off+1;
				for(int j=r;j>=mid;j--)
				{
					ans[j] = cnt++;
				}
			}
			else
			{
				int cnt=off;
				for(int j=r;j>=mid;j--)
				{
					//can i become cnt + 1?
					//if I am cnt+1, then there are j - mid numbers left, so cnt+1-(j-mid)<=res
					if(cnt+1-(j-mid)<=res&&cnt+1<=R[j])
					{
						ans[j]=cnt+1;
						cnt++;
					}
					else if(cnt-(j-mid)<=res&&cnt<=R[j])
					{
						ans[j]=cnt;
					}
					else
					{
						ans[j]=cnt-1;
						cnt--;
					}
					//cerr<<j<<' '<<mid<<' '<<cnt<<'\n';
				}
			}
			solve(0,mid-1,ans[mid]);
		}
	}
	else
	{
		int mid = st.query(l,r);
		//we know what mid is now
		int res = R[mid];
		int diff = mid - l + 1;
		//maximum possible value of mid is off + diff
		if(res>=off+diff)
		{
			int cnt = off+1;
			for(int j=l;j<=mid;j++)
			{
				ans[j] = cnt++;
			}
		}
		else
		{
			int cnt=off;
			for(int j=l;j<=mid;j++)
			{
				//can i become cnt + 1?
				//if I am cnt+1, then there are j - mid numbers left, so cnt+1-(j-mid)<=res
				if(cnt+1-(mid-j)<=res&&cnt+1<=R[j])
				{
					ans[j]=cnt+1;
					cnt++;
				}
				else if(cnt-(mid-j)<=res&&cnt<=R[j])
				{
					ans[j]=cnt;
				}
				else
				{
					ans[j]=cnt-1;
					cnt--;
				}
			}
		}
		solve(mid+1,n-1,ans[mid]);
	}
	*/
	int mid=st.query(l,r);
	int res=R[mid];
	int dl = mid - l + 1;
	int dr = r - mid + 1;
	int maxv = min(res, min(dl+offl, dr+offr));
	//cerr<<mid<<' '<<maxv<<'\n';
	ans[mid] = maxv;
	solve(l,mid-1,offl,ans[mid]);
	solve(mid+1,r,ans[mid],offr);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>L[i]>>R[i];
		R[i]+=L[i];
		st.initial[i]=R[i];
	}
	st.init();
	solve(0,n-1,int(1e9),int(1e9));
	ll res=0;
	for(int i=0;i<n;i++)
	{
		res+=ans[i]-L[i];
		if(ans[i]<L[i]||ans[i]>R[i])
		{
			cout<<-1<<'\n';
			return 0;
		}
		if(i+1<n) 
		{
			if(abs(ans[i]-ans[i+1])>1)
			{
				cout<<-1<<'\n';
				return 0;
			}
		}
		assert(ans[i]>=L[i]&&ans[i]<=R[i]);
	}
	cout<<res<<'\n';
	for(int i=0;i<n;i++)
	{
		cout<<ans[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}