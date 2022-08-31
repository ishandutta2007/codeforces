#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 100005
#define MP 105
#define INF 1000000000

using namespace std;
typedef long long int ll;

ll dst[SIZE];
ll in[SIZE];
ll dp[SIZE][MP];
ll rui[SIZE];

ll nx(ll k)
{
	return -k;
}
ll ny(ll k,int p)
{
	return dp[k-1][p-1]+rui[k-1];
}
ll f(ll j,ll x,int p)
{
	return nx(j)*x+ny(j,p);
}
bool check(ll f1,ll f2,ll f3,int p)//f1 <= f2 <= f3
{
	return (nx(f2)-nx(f1))*(ny(f3,p)-ny(f2,p))>=(ny(f2,p)-ny(f1,p))*(nx(f3)-nx(f2));
}
struct getmin
{
	ll deq[SIZE];
	int s,e,p;
	
	getmin(int p=-1):p(p)
	{
		s=0;
		e=0;
	}
	void push_back(ll x)
	{
		while(s+1<e&&check(deq[e-2],deq[e-1],x,p)) e--;
		deq[e++]=x;
	}
	ll front(ll x)
	{
		while(s+1<e&&f(deq[s],x,p)>=f(deq[s+1],x,p)) s++;
		return f(deq[s],x,p);
	}
};
getmin gt[MP];

int main()
{
	int n,m,p;
	scanf("%d %d %d",&n,&m,&p);
	in[0]=0;
	for(int i=1;i<n;i++)
	{
		scanf("%I64d",&dst[i]);
		dst[i]+=dst[i-1];
	}
	for(int i=0;i<m;i++)
	{
		int h,t;
		scanf("%d %d",&h,&t);h--;
		t-=dst[h];
		in[i]=t;
	}
	sort(in,in+m);
	for(int i=0;i<m;i++)
	{
		rui[i]=in[i];
		if(i>0) rui[i]+=rui[i-1];
		dp[i][0]=INF;
		for(int j=1;j<=p;j++) dp[i][j]=INF;
	}
	dp[0][1]=0;
	for(int i=1;i<=p;i++) gt[i].p=i;
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<=p;j++)
		{
			if(j==1) dp[i][j]=in[i]*(i+1)-rui[i];
			else
			{
				gt[j].push_back(i);
				dp[i][j]=gt[j].front(in[i])-rui[i]+in[i]*(i+1);
				/*
				dp[i][j]=in[i]*(i+1)-rui[i];
				for(int k=1;k<=i;k++)
				{
					dp[i][j]=min(dp[i][j],dp[k-1][j-1]+in[i]*(i-k+1)-(rui[i]-rui[k-1]));
				}
				*/
			}
		}
	}
	printf("%I64d\n",dp[m-1][p]);
	return 0;
}