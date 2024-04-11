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

int dp[1055][4111];
int cost[4];
int a[4][1234];
int prebit[1234];
int F[4] = {2,3,4,4};

void out(int bit)
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(bit&(1<<(j*4+i))) cout<<'*';
			else cout<<'.';
		}
		cout<<'\n';
	}
}

int solve(int cur, int bit)
{
	if(cur<0) return 0;
	if(dp[cur][bit]!=-1) return dp[cur][bit];
	//cerr<<"SOLVE : "<<cur<<' '<<bit<<'\n';
	int ans = int(2e9);
	if(cur-4<0) ans = min(ans, cost[3]);
	else ans = min(ans, cost[3] + solve(cur-4, prebit[cur-4]));
	//all are <= 3 
	for(int i = 0; i < 96; i++)
	{
		int cnt[4] = {};
		int curr=i;
		bool pos=1;
		int cos=0;
		for(int j=0;j<4;j++)
		{
			cnt[j]=curr%F[j];
			curr/=F[j];
			if(cnt[j]>0) cos+=cost[cnt[j]-1];
			//if(cnt[j]>cur+1){pos=0; break;}
		}
		if(!pos) continue;
		int tmpbit = bit;
		int all=(1<<12)-1;
		if(cnt[0]==1)
		{
			tmpbit&=(all^(1<<8));
		}
		if(cnt[1]==1)
		{
			tmpbit&=(all^(1<<9));
		}
		if(cnt[1]==2)
		{
			tmpbit&=(all^(1<<8));
			tmpbit&=(all^(1<<9));
			tmpbit&=(all^(1<<5));
			tmpbit&=(all^(1<<4));
		}
		if(cnt[2]==1)
		{
			tmpbit&=(all^(1<<10));
		}
		if(cnt[2]==2)
		{
			tmpbit&=(all^(1<<10));
			tmpbit&=(all^(1<<9));
			tmpbit&=(all^(1<<5));
			tmpbit&=(all^(1<<6));
		}
		if(cnt[2]==3)
		{
			tmpbit&=(all^(1<<0));
			tmpbit&=(all^(1<<1));
			tmpbit&=(all^(1<<2));
			tmpbit&=(all^(1<<4));
			tmpbit&=(all^(1<<5));
			tmpbit&=(all^(1<<6));
			tmpbit&=(all^(1<<8));
			tmpbit&=(all^(1<<9));
			tmpbit&=(all^(1<<10));
		}
		if(cnt[3]==1)
		{
			tmpbit&=(all^(1<<11));
		}
		if(cnt[3]==2)
		{
			tmpbit&=(all^(1<<6));
			tmpbit&=(all^(1<<10));
			tmpbit&=(all^(1<<11));
			tmpbit&=(all^(1<<7));
		}
		if(cnt[3]==3)
		{
			tmpbit&=(all^(1<<1));
			tmpbit&=(all^(1<<2));
			tmpbit&=(all^(1<<5));
			tmpbit&=(all^(1<<6));
			tmpbit&=(all^(1<<9));
			tmpbit&=(all^(1<<10));
			tmpbit&=(all^(1<<11));
			tmpbit&=(all^(1<<7));
			tmpbit&=(all^(1<<3));
		}
		if(pos)
		{
			int newbit = tmpbit;
			newbit&=((1<<8)-1);
			if(newbit==tmpbit)
			{
				newbit<<=4;
				for(int j=0;j<4;j++)
				{
					if(cur-3>=0)
					{
						if(a[j][cur-3]) newbit|=(1<<j);
					}
				}
				////cerr<<cos<<' '<<cur-1<<' '<<newbit<<'\n';
				int res = cos+solve(cur-1,newbit);
				//if(res<ans)
				//{
					//cerr<<"NEW : "<<cur<<' '<<bit<<' '<<res<<'\n';
					//out(newbit);
				//}
				ans=min(ans, res);
			}
		}
	}
	//cerr<<"ANS : "<<cur<<' '<<bit<<' '<<ans<<'\n';
	//out(bit);
	return (dp[cur][bit]=ans);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp,-1,sizeof(dp));
	int n; cin>>n;
	for(int i=0;i<4;i++) cin>>cost[i];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<n;j++)
		{
			char c; cin>>c;
			if(c=='.') a[i][j]=0;
			else a[i][j]=1;
		}
	}
	for(int z=0;z<n;z++)
	{
		for(int i=0;i<4;i++)
		{
			for(int j=z-2;j<=z;j++)
			{
				if(j>=0&&a[i][j]) prebit[z]|=(1<<(i+(j-z+2)*4));
			}
		}
	}
	cout<<solve(n-1,prebit[n-1])<<'\n';
}