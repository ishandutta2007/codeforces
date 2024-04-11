#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#define SIZE 100005
#define INF 1000000005
#define SQR 90
#define BT 7

using namespace std;
typedef pair <int,int> P;

int dpx[BT][SIZE],dpn[BT][SIZE];
int A[SIZE],ans[SIZE];
P query[SIZE];
int mn[SIZE/SQR+5];
int to[SIZE],cnt[SIZE],now[SIZE];
int low[SIZE],up[SIZE];
int n,W,q;

void build()
{
	for(int i=0;i<n;i++) dpx[0][i]=dpn[0][i]=A[i];
	for(int i=0;i+1<BT;i++)
	{
		for(int j=0;j<n;j++)
		{
			dpx[i+1][j]=dpx[i][j];
			dpn[i+1][j]=dpn[i][j];
			if(j+(1<<i)<n)
			{
				dpx[i+1][j]=max(dpx[i+1][j],dpx[i][j+(1<<i)]);
				dpn[i+1][j]=min(dpn[i+1][j],dpn[i][j+(1<<i)]);
			}
		}
	}
}
void calc(int x,int lim)
{
	int l=x*SQR,r=(x+1)*SQR;
	r=min(r,n);
	mn[x]=INF;
	for(int i=r-1;i>=l;i--)
	{
		if(cnt[i]>0)
		{
			int t=now[i];
			int a=low[i],b=up[i];
			while(t<r&&max(b,A[t])-min(a,A[t])<=lim)
			{
				b=max(b,A[t]);
				a=min(a,A[t]);
				t++;
			}
			if(t==r) to[i]=i,now[i]=r,cnt[i]=0,low[i]=a,up[i]=b;
			else
			{
				to[i]=to[t],now[i]=t,cnt[i]=cnt[t]+1,low[i]=a,up[i]=b;
				mn[x]=min(mn[x],max(b,A[t])-min(a,A[t]));
			}
		}
	}
}
int go(int v,int lim,int a,int b)
{
	for(int i=BT-1;i>=0;i--)
	{
		if(max(b,dpx[i][v])-min(a,dpn[i][v])<=lim)
		{
			b=max(b,dpx[i][v]);
			a=min(a,dpn[i][v]);
			int t=v+(1<<i);
			if(t>=n) return n;
			v=t;
		}
	}
	return v;
}
int main()
{
	scanf("%d %d %d",&n,&W,&q);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	for(int i=0;i<q;i++)
	{
		int k;
		scanf("%d",&k);
		query[i]=P(W-k,i);
	}
	for(int i=0;i<n;i++) cnt[i]=1,low[i]=up[i]=A[i],now[i]=i;
	int sz=(n-1)/SQR+1;
	for(int i=0;i<sz;i++) calc(i,0);
	build();
	//for(int i=0;i<n;i++) printf("[%d %d]\n",to[i],cnt[i]);
	sort(query,query+q);
	for(int i=0;i<q;i++)
	{
		int lim=query[i].first;
		for(int j=0;j<sz;j++)
		{
			if(mn[j]<=lim)
			{
				calc(j,lim);
			}
		}
		int a=A[0],b=A[0];
		int ret=0;
		for(int j=0;j<sz;j++)
		{
			if(cnt[j*SQR]==0&&max(b,up[j*SQR])-min(a,low[j*SQR])<=lim)
			{
				b=max(b,up[j*SQR]);
				a=min(a,low[j*SQR]);
			}
			else
			{
				int pos=go(j*SQR,lim,a,b);
				ret+=cnt[pos];
				pos=to[pos];
				a=low[pos],b=up[pos];
				ret++;
			}
		}
		ans[query[i].second]=ret;
	}
	for(int i=0;i<q;i++) printf("%d\n",ans[i]);
	return 0;
}