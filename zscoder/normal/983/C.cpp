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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int dp[2][(1<<16)][10];
int S[2111];
int E[2111];

void amin(int &a, int b)
{
	if(b<a) a=b;
}

int cntbit[(1<<18)];

const int INF = int(1e9);
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>S[i]>>E[i]; 
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<(1<<16);j++)
		{
			for(int k=1;k<10;k++)
			{
				dp[i][j][k]=INF;
			}
		}
	}
	vi valid;
	for(int i=0;i<10;i++)
	{
		for(int j=i;j<10;j++)
		{
			for(int k=j;k<10;k++)
			{
				for(int l=k;l<10;l++)
				{
					int bit = ((l<<12)^(k<<8)^(j<<4)^i);
					if(i!=0) cntbit[bit]++;
					if(j!=0) cntbit[bit]++;
					if(k!=0) cntbit[bit]++;
					if(l!=0) cntbit[bit]++;
					//cerr<<bit<<' '<<cntbit[bit]<<'\n';
					valid.pb(bit);
				}
			}
		}
	}
	sort(valid.rbegin(),valid.rend());
	for(int i=1;i<10;i++) dp[0][0][i] = i-1;
	for(int i=1;i<=n;i++)
	{
		int cur = (i&1); int pre = cur^1;
		for(int v:valid)
		{
			for(int j=1;j<10;j++) dp[cur][v][j] = INF;
		}
		for(int v:valid)
		{
			int j = S[i];
			if(dp[pre][v][j]<INF)
			{
				if(cntbit[v]>=4) continue;
				int freq[10]={}; int cb = v;
				for(int k=0;k<4;k++)
				{
					freq[cb&15]++;
					cb>>=4;
				}
				freq[E[i]]++;int newbit=0; int ct=0;
				for(int k=9;k>=1;k--)
				{
					for(int z=0;z<freq[k];z++)
					{
						newbit<<=4;
						newbit^=k;
						ct++;
					}
				}
				while(ct<4)
				{
					ct++; newbit<<=4;
				}
				//cerr<<newbit<<' '<<j<<' '<<v<<' '<<dp[pre][v][j]<<'\n';
				for(int k=1;k<10;k++)
				{
					amin(dp[cur][newbit][k], dp[pre][v][j] + 1 + abs(j-k));
				}
			}
		}
		//push down
		for(int v:valid)
		{
			for(int j=1;j<10;j++)
			{
				/*
				if(dp[pre][v][j]<INF)
				{
					int val = dp[pre][v][j];
					if(j+1<10) amin(dp[cur][v][j+1], val+1);
					if(j>1) amin(dp[cur][v][j-1],val+1);
					
				}
				*/
				if(cntbit[v]<4)
				{
					int freq[10]={}; int cb = v;
					for(int k=0;k<4;k++)
					{
						freq[cb&15]++;
						cb>>=4;
					}
					freq[j]++; int newbit=0; int ct=0;
					for(int k=9;k>=1;k--)
					{
						for(int z=0;z<freq[k];z++)
						{
							newbit<<=4;
							newbit^=k;
							ct++;
						}
					}
					while(ct<4)
					{
						ct++; newbit<<=4;
					}
					//cerr<<newbit<<' '<<j<<' '<<v<<' '<<dp[pre][v][j]<<'\n';
					for(int k=1;k<10;k++)
					{
						amin(dp[cur][v][k], dp[cur][newbit][j]+1+abs(k-j));
					}
				}
				//if(dp[cur][v][j]<INF) cerr<<"DP "<<i<<' '<<v<<' '<<j<<' '<<dp[cur][v][j]<<'\n';
			}
			/*
			for(int j=1;j<10;j++)
			{
				if(j+1<10) amin(dp[cur][v][j], dp[cur][v][j+1]+1);
				if(j>1) amin(dp[cur][v][j],dp[cur][v][j-1]+1);
			}
			*/
		}
	}
	int ans=INF;
	for(int i=1;i<10;i++) ans=min(ans,dp[n&1][0][i]);
	cout<<ans<<'\n';
}