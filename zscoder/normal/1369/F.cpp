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
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

bool is_win(ll s, ll e) //can player 2 win
{
	if(s>e) return 0;
	if(e%2==1)
	{
		return (s<=e&&(s%2==1));
	}
	if(e%4==2)
	{
		if(s==e) return 1;
		return is_win(s,e-2);
	}
	if(e/2<s&&s<=e&&s%2==0) return 1;
	else return is_win(s,e/4);
}

bool is_lose(ll s, ll e) //can player 2 lose?
{
	if(s>e) return 0;
	if(e%2==1) return is_lose(s,e-1);
	if(e%4==2)
	{
		return (s<=e/2&&(s%2==1));
	}
	if(s%2==0&&(s>e/4)&&(s<=e/2))
	{
		return 1;
	}
	return is_lose(s,e/4);
}

/*
bool win[511][511];

void naive_win()
{
	win[1][1]=0;
	for(int i=2;i<=60;i++)
	{
		cout<<"FOR "<<i<<": ";
		win[i][i]=0;
		for(int j=i-1;j>=1;j--)
		{
			//can P1 win if (j,i)?
			if(j*2<=i&&(!win[j*2][i])) win[j][i]=1;
			if(j+1<=i&&(!win[j+1][i])) win[j][i]=1;
		}
		for(int j=1;j<=i;j++)
		{
			assert(win[j][i]!=is_lose(j,i));
			if(!win[j][i])
			{
				cout<<j<<' ';
			}
		}
		cout<<'\n';
	}
}

void naive_lose()
{
	win[1][1]=1;
	for(int i=2;i<=60;i++)
	{
		cout<<"FOR "<<i<<": ";
		win[i][i]=1;
		for(int j=i-1;j>=1;j--)
		{
			//can P1 lose if (j,i)?
			if(j*2>i||(j+1>i))
			{
				win[j][i]=1; continue;
			}
			if(!win[j+1][i]) win[j][i]=1;
			if(!win[j*2][i]) win[j][i]=1;
		}
		for(int j=1;j<=i;j++)
		{
			assert(win[j][i]!=is_lose(j,i));
			if(!win[j][i])
			{
				cout<<j<<' ';
			}
		}
		cout<<'\n';
	}
}
*/

int dp[111111][2]; //can P1 lose

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//naive_lose();
	int n; cin>>n;
	vector<ii> vec;
	for(int i=0;i<n;i++)
	{
		ll x,y; cin>>x>>y;
		vec.pb({x,y});
	}
	dp[n][1]=0; dp[n][0]=1;
	for(int i=n-1;i>=0;i--)
	{
		int canwin = (is_win(vec[i].fi,vec[i].se)==0);
		int canlose = (is_lose(vec[i].fi,vec[i].se)==0);
		if(canwin)
		{
			for(int j=0;j<2;j++)
			{
				if(!dp[i+1][j]) dp[i][j]=1;
			}
		}
		if(canlose)
		{
			for(int j=0;j<2;j++)
			{
				if(dp[i+1][j]) dp[i][j]=1;
			}
		}
	}
	cout<<dp[0][1]<<' '<<dp[0][0]<<'\n';
}