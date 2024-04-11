#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#define SIZE 2005
#define MOD 1000000007
#define B1 89793
#define M1 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int dp[SIZE][2][SIZE];
char mp[2][SIZE];
char A[SIZE];
ll hash1[SIZE];
ll back1[SIZE];
bool use[2][SIZE];
int n,m;

ll solve()//tAsscount
{
	for(int i=0;i<m;i++)
	{
		hash1[i]=A[i]-'a'+1;
		if(i>0)
		{
			hash1[i]+=hash1[i-1]*B1%M1;
			if(hash1[i]>=M1) hash1[i]-=M1;
		}
	}
	for(int i=m-1;i>=0;i--)
	{
		back1[i]=A[i]-'a'+1;
		if(i+1<m)
		{
			back1[i]+=back1[i+1]*B1%M1;
			if(back1[i]>=M1) back1[i]-=M1;
		}
	}
	memset(dp,0,sizeof(dp));
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		memset(use,false,sizeof(use));
		for(int t=0;t<2;t++)
		{
			//[i,t]
			if(A[0]==mp[t][i])
			{
				dp[i][t][0]++;
				if(dp[i][t][0]>=MOD) dp[i][t][0]-=MOD;
			}
			ll h1=0,g1=0,mt=1;
			for(int j=i;j>=0;j--)
			{
				h1*=B1;
				h1+=mp[t][j]-'a'+1;
				g1+=(ll) (mp[1-t][j]-'a'+1)*mt;
				mt*=B1;
				h1%=M1,g1%=M1,mt%=M1;
				int L=2*(i-j+1);
				if(j==i) continue;
				if(L<m&&(h1*mt+g1)%M1==hash1[L-1]&&i+1<n&&mp[1-t][i+1]==A[L])
				{
					dp[i+1][1-t][L]++;
					if(dp[i+1][1-t][L]>=MOD) dp[i+1][1-t][L]-=MOD;
				}
			}
			h1=g1=0,mt=1;
			for(int j=i;j<n;j++)
			{
				g1*=B1;
				g1+=mp[1-t][j]-'a'+1;
				h1+=(ll) (mp[t][j]-'a'+1)*mt;
				mt*=B1;
				h1%=M1,g1%=M1,mt%=M1;
				int L=2*(j-i+1);
				if(L<=m&&(g1*mt+h1)%M1==back1[m-L]) use[t][L]=true;
			}
		}
		for(int t=0;t<2;t++)
		{
			for(int j=0;j<m;j++)
			{
				if(dp[i][t][j]==0) continue;
				if(j+1<m&&mp[t][i+1]==A[j+1])
				{
					dp[i+1][t][j+1]+=dp[i][t][j];
					if(dp[i+1][t][j+1]>=MOD) dp[i+1][t][j+1]-=MOD;
				}
				if(j+2<m&&mp[1-t][i]==A[j+1]&&mp[1-t][i+1]==A[j+2])
				{
					dp[i+1][1-t][j+2]+=dp[i][t][j];
					if(dp[i+1][1-t][j+2]>=MOD) dp[i+1][1-t][j+2]-=MOD;
				}
				//[i,t][i,1-t]
				if(j==m-1||((m-j)%2==0&&use[t][m-j]))
				{
					ret+=dp[i][t][j];
					if(ret>=MOD) ret-=MOD;
				}
			}
		}
	}
	return ret;
}
int main()
{
	for(int i=0;i<2;i++) scanf("%s",&mp[i]);
	n=strlen(mp[0]);
	scanf("%s",&A);
	m=strlen(A);
	ll ret=solve();
	for(int l=0,r=n-1;l<r;l++,r--)
	{
		swap(mp[0][l],mp[0][r]);
		swap(mp[1][l],mp[1][r]);
	}
	//return 0;
	//printf("%lld %lld\n",ret,solve());
	if(m>1)
	{
		ret+=solve();
		if(ret>=MOD) ret-=MOD;
	}
	if(m==2)
	{
		for(int i=0;i<n;i++)
		{
			if(mp[0][i]==A[0]&&mp[1][i]==A[1])
			{
				ret--;
				if(ret<0) ret+=MOD;
			}
			if(mp[1][i]==A[0]&&mp[0][i]==A[1])
			{
				ret--;
				if(ret<0) ret+=MOD;
			}
		}
	}
	printf("%lld\n",ret);
	return 0;
}