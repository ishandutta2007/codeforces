#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 105
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll fr[SIZE][SIZE];
ll mul[SIZE][SIZE];
ll mul2[SIZE][SIZE];
ll cur[SIZE][SIZE];
ll A[SIZE];
int n;

void make(ll S[SIZE][SIZE],ll T[SIZE][SIZE])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cur[i][j]=0;
			for(int k=0;k<n;k++)
			{
				cur[i][j]+=S[i][k]*T[k][j]%MOD;
				if(cur[i][j]>=MOD) cur[i][j]-=MOD;
			}
		}
	}
}
void dfs(ll L)
{
	if(L==1)
	{
		for(int i=0;i<n;i++) mul[i][i]=1;
		return;
	}
	dfs(L/2);
	make(mul,fr);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) mul2[i][j]=cur[i][j];
	make(mul2,mul);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) mul[i][j]=cur[i][j];
	if(L%2==1)
	{
		make(mul,fr);
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) mul[i][j]=cur[i][j];
	}
}
int main()
{
	ll L;
	scanf("%d %lld",&n,&L);
	for(int i=0;i<n;i++) scanf("%lld",&A[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ll x=A[i]^A[j];
			int cnt=0;
			while(x>0)
			{
				if(x%2==1) cnt++;
				x/=2;
			}
			fr[i][j]=cnt%3==0?1:0;
			//printf("%d ",(int) fr[i][j]);
		}
		//puts("");
	}
	dfs(L);
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ret+=mul[i][j];
			if(ret>=MOD) ret-=MOD;
		}
	}
	printf("%lld\n",ret);
	return 0;
}