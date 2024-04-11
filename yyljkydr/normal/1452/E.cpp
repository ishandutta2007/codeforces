#include<bits/stdc++.h>
using namespace std;

const int N=2e3+1e2+7;

int n,m,k;

struct P{
	int l,r,w;
}p[N];

bool operator <(const P &a,const P &b)
{
	return a.w<b.w;
}

int pre[N][N],suf[N][N];

int cal(int a,int b,int c,int d)
{
	return max(0,min(b,d)-max(a,c)+1);
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&p[i].l,&p[i].r),p[i].w=p[i].l+p[i].r;
	sort(p+1,p+m+1);
	for(int i=1;i<=n-k+1;i++)
	{
		for(int j=1;j<=m;j++)
			pre[i][j]=pre[i][j-1]+cal(i,i+k-1,p[j].l,p[j].r);
		for(int j=m;j>=1;j--)
			suf[i][j]=suf[i][j+1]+cal(i,i+k-1,p[j].l,p[j].r);
	}
	int ans=0;
	for(int i=1;i<=n-k+1;i++)
		for(int j=i;j<=n-k+1;j++)
		{
			int mi=i+i+k-1,mj=j+j+k-1;
			int d=(mi+mj)>>1;
			int x=upper_bound(p+1,p+m+1,P{0,0,d})-p;
			ans=max(ans,pre[i][x-1]+suf[j][x]);
		}
	printf("%d\n",ans);
}