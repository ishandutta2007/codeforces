#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005

using namespace std;
typedef long long int ll;

bool dp[SIZE];
int A[SIZE],back[SIZE];
ll sum[SIZE];

int main()
{
	int n,C;
	scanf("%d",&C);
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	sort(A,A+n);
	for(int i=0;i<n;i++)
	{
		sum[i]=A[i];
		if(i>0) sum[i]+=sum[i-1];
	}
	dp[0]=true;
	back[0]=-2*SIZE;
	for(int i=1;i<=C;i++)
	{
		int r=lower_bound(A,A+n,i+1)-A-1;
		if(r==-1||(r>=0&&sum[r]<i)) dp[i]=false;
		else if(sum[r]==i) dp[i]=true;
		else
		{
			int back=lower_bound(sum,sum+n,sum[r]-i)-sum;
			dp[i]=dp[i-sum[r]+sum[back]];
		}
		back[i]=!dp[i]?i:back[i-1];
	}
	//for(int i=1;i<=C;i++) printf("%d",dp[i]);puts("");
	if(!dp[C])
	{
		puts("0");
		return 0;
	}
	//L
	int to=n-1,zan=C;
	int bef=C;
	int ret=C+1;
	while(zan>0)
	{
		while(to>=0&&A[to]>zan) to--;
		int nb;
		while(to>=0)
		{
			//A[to] g <=> zan-U<A[to] , U<=bef , U>=A[to] <=> max(A[to],zan-A[to]+1)<=U<=bef
			int low=max(A[to],zan-A[to]+1);
			if(low<=zan&&low<=bef)
			{
				if(back[zan-low]>=zan-bef)
				{
					ret=min(ret,zan-back[zan-low]);
				}
			}
			if(zan<A[to]) break;
			zan-=A[to];
			nb=A[to--];
		}
		bef=nb;
	}
	if(ret>=C+1) puts("Greed is good");
	else printf("%d\n",ret);
	return 0;
}