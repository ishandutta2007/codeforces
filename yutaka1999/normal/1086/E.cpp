#include <bits/stdc++.h>
#define SIZE 2005
#define MOD 998244353

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct BIT
{
	int bit[SIZE];
	
	void init()
	{
		memset(bit,0,sizeof(bit));
	}
	void add(int k,int x)
	{
		k++;
		while(k<SIZE)
		{
			bit[k]+=x;
			k+=k&-k;
		}
	}
	int get(int k)
	{
		k++;
		int ret=0;
		while(k>0)
		{
			ret+=bit[k];
			k-=k&-k;
		}
		return ret;
	}
	int get(int s,int t)
	{
		return get(t)-get(s-1);
	}
};
BIT bit1,bit2;
ll dp[SIZE][SIZE];
ll rt[SIZE];
int A[SIZE][SIZE];
bool ux[SIZE],vy[SIZE];
int cnt[SIZE];

void make()
{
	for(int i=0;i<SIZE;i++)
	{
		if(i==0) dp[i][0]=1;
		else if(i==1) dp[i][0]=0;
		else if(i==2) dp[i][0]=1;
		else dp[i][0]=(ll) (i-1)*(dp[i-1][0]+dp[i-2][0])%MOD;
		for(int j=1;j<SIZE;j++)
		{
			dp[i][j]=((i==0?0:dp[i-1][j])*(ll) i+dp[i][j-1]*(ll) j)%MOD;
		}
	}
}
void insX(int v)
{
	ux[v]=true;
	if(vy[v]) bit1.add(v,-1);
	else bit2.add(v,-1);
}
void rmY(int v)
{
	vy[v]=false;
	if(!ux[v])
	{
		bit1.add(v,-1);
		bit2.add(v,1);
	}
}
int main()
{
	make();
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&A[i][j]),A[i][j]--;
	rt[0]=1;
	for(int i=1;i<SIZE;i++) rt[i]=rt[i-1]*dp[n][0]%MOD;
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		bit1.init();
		bit2.init();
		for(int j=0;j<n;j++) ux[j]=vy[j]=false;
		if(i>0)
		{
			for(int j=0;j<n;j++) vy[j]=true,bit1.add(j,1);
		}
		else
		{
			for(int j=0;j<n;j++) bit2.add(j,1);
		}
		for(int j=0;j<n;j++)
		{
			if(i>0)
			{
				rmY(A[i-1][j]);
			}
			if(A[i][j]>0)
			{
				int a=bit1.get(0,n);
				int b=bit2.get(0,n);
				int c=bit1.get(0,A[i][j]-1);
				int d=bit2.get(0,A[i][j]-1);
				if(i>0&&A[i-1][j]<A[i][j]&&!ux[A[i-1][j]]) d--;
				if(a>0) ret+=(ll) c*(ll) dp[a-1][b]%MOD*rt[n-i-1]%MOD;
				if(b>0) ret+=(ll) d*(ll) dp[a][b-1]%MOD*rt[n-i-1]%MOD;
				ret%=MOD;
				//printf("%d %d : %d %d : %d %d\n",i,j,a,b,c,d);
			}
			insX(A[i][j]);
		}
	}
	printf("%lld\n",ret);
	return 0;
}