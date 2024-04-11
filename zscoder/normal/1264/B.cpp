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

int dp[51][51][51][51][4];

int solve(int a, int b, int c, int d, int e)
{
	if(dp[a][b][c][d][e]!=-1) return dp[a][b][c][d][e];
	if(a+b+c+d==0) return 1;
	int cnt[4]={a,b,c,d};
	for(int i=-1;i<=1;i+=2)
	{
		if(e+i>=0&&e+i<=3&&cnt[e+i]>0)
		{
			cnt[e+i]--;
			if(solve(cnt[0],cnt[1],cnt[2],cnt[3],e+i)) return (dp[a][b][c][d][e]=1);
			cnt[e+i]++;
		}
	}
	return (dp[a][b][c][d][e]=0);
}

vi ans;
int solve_fast(int a, int b, int c, int d) //assume sum is even
{
	ans.clear();
	int cnt[4] = {a,b,c,d};
	if(cnt[2]==0&&cnt[3]==0)
	{
		if(abs(a-b)>1)
		{
			return 0;
		}
		else
		{
			if(cnt[0]-cnt[1]>=1)
			{
				int cur=0;
				while(cnt[0]+cnt[1]>0)
				{
					ans.pb(cur); cnt[cur]--; cur^=1;
				}
			}
			else
			{
				int cur=1;
				while(cnt[0]+cnt[1]>0)
				{
					ans.pb(cur); cnt[cur]--; cur^=1;
				}
			}
		}
		return 1;
	}
	if(cnt[0]+cnt[1]==0)
	{
		if(abs(cnt[2]-cnt[3])>1)
		{
			return 0;
		}
		else
		{
			if(cnt[2]-cnt[3]>=1)
			{
				int cur=2;
				while(cnt[2]+cnt[3]>0)
				{
					ans.pb(cur); cnt[cur]--; cur^=1;
				}
			}
			else
			{
				int cur=3;
				while(cnt[2]+cnt[3]>0)
				{
					ans.pb(cur); cnt[cur]--; cur^=1;
				}
			}
		}
		return 1;
	}
	deque<int> L;
	for(int i=0;i<cnt[0];i++)
	{
		L.pb(0); L.pb(1); cnt[1]--;
	}
	deque<int> R;
	for(int i=0;i<cnt[3];i++)
	{
		R.pb(3); R.pb(2); cnt[2]--;
	}
	if(cnt[1]<0||cnt[2]<0) return 0;
	while(cnt[1]>0&&cnt[2]>0)
	{
		cnt[1]--; cnt[2]--;
		L.pb(2); L.pb(1);
	}
	if(cnt[1]+cnt[2]>1)
	{
		return 0;
	}
	if(cnt[1]>=1) L.push_front(1);
	if(cnt[2]>=1) R.push_front(2);
	reverse(R.begin(),R.end());
	for(int x:L) ans.pb(x);
	for(int x:R) ans.pb(x);
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a,b,c,d; cin>>a>>b>>c>>d;
	int tmp = solve_fast(a,b,c,d);
	if(tmp)
	{
		cout<<"YES\n";
		for(int x:ans)
		{
			cout<<x<<' ';
		}
		cout<<'\n';
	}
	else
	{
		cout<<"NO\n";
	}
	return 0;
	memset(dp,-1,sizeof(dp));
	int n; cin>>n;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=n;k++)
			{
				for(int l=0;l<=n;l++)
				{
					if(i+k!=j+l) continue;
					int tmp = (solve(i,j,k,l,0)||solve(i,j,k,l,1)||solve(i,j,k,l,2)||solve(i,j,k,l,3));
					assert(solve_fast(i,j,k,l)==tmp);
					if(tmp)
					{
						//cout<<i<<' '<<j<<' '<<k<<' '<<l<<' ';
						//cout<<solve_fast(i,j,k,l)<<'\n';
					}
				}
			}
		}
	}
}