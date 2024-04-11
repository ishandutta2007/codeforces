#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define SQR 1000
#define SM 105

using namespace std;

int A[SIZE];
bool use[SIZE];
int ans[SIZE];
int n;

int solve(int c)
{
	int ret=0,now=0;
	while(now<n)
	{
		ret++;
		int f=now;
		int nm=0;
		while(now<n&&nm+(1-use[A[now]])<=c)
		{
			if(!use[A[now]])
			{
				use[A[now]]=true;
				nm++;
			}
			now++;
		}
		for(int i=f;i<now;i++) use[A[i]]=false;
	}
	return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	for(int i=1;i<=n;i++) ans[i]=n;
	for(int i=1;i<=min(n,SQR);i++) ans[i]=solve(i);
	for(int i=1;i<SM;i++)
	{
		int l=0,r=n;
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(solve(m)>i) l=m;
			else r=m;
		}
		ans[r]=min(ans[r],i);
	}
	for(int i=1;i+1<=n;i++) ans[i+1]=min(ans[i+1],ans[i]);
	for(int i=1;i<=n;i++)
	{
		if(i!=1) printf(" ");
		printf("%d",ans[i]);
	}puts("");
	return 0;
}