#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	int x,id;
	node(int nx=0,int nid=0){x=nx;id=nid;}
}y[600005];
int cnt=0,a[7],n,x,sum=0,l,r,tot[100005],ans;
bool cmp(node a,node b){return a.x<b.x;}
int main()
{
	ans=1000000000;
	for(int i=1;i<=6;i++)scanf("%d",&a[i]);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for(int j=1;j<=6;j++)y[++cnt]=node(x-a[j],i);
	}
	sort(y+1,y+6*n+1,cmp);
	r=0;
	for(int i=1;i<=6*n;i++)
	{
		while(r<6*n&&sum<n)
		{
			r++;
			tot[y[r].id]++;
			if(tot[y[r].id]==1)sum++;
		}
		if(sum==n)ans=min(ans,y[r].x-y[i].x);
		tot[y[i].id]--;
		if(tot[y[i].id]==0)sum--;
	}
	printf("%d\n",ans);
	return 0;
}