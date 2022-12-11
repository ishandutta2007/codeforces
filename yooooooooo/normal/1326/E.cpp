#include<cstdio>
#include<algorithm> 
using namespace std;
int tr[1200005],tg[1200005],pos[300005],n,q[300005],p[300005],ans[300005],gl,gr,v;
const int inf=1e9;
void build(int p,int l,int r)
{
	tr[p]=inf;
	if(l==r)return;
	int mid=(l+r)/2;
	build(2*p,l,mid);
	build(2*p+1,mid+1,r);
}
void act(int p,int v)
{
	tr[p]+=v;
	tg[p]+=v;
}
void push(int p)
{
	if(!tg[p])return;
	act(2*p,tg[p]);
	act(2*p+1,tg[p]);
	tg[p]=0; 
}
void upd(int p,int l,int r)
{
	int mid;
	if(l>gr||r<gl)return;
	if(l>=gl&&r<=gr)
	{
		act(p,v);
		return;
	}
	push(p);
	mid=(l+r)/2;
	upd(2*p,l,mid);
	upd(2*p+1,mid+1,r);
	tr[p]=min(tr[2*p],tr[2*p+1]);
}
int main()
{
	scanf("%d",&n);
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		pos[p[i]]=i;
	}
	for(int i=1;i<=n;i++)scanf("%d",&q[i]);
	ans[0]=n;
	int j=0;
	for(int i=n;i>1;i--)
	{
		v=-inf;gl=pos[i];gr=pos[i];
		upd(1,1,n);
		v=-1;gl=1;gr=pos[i];
		upd(1,1,n);
		while(tr[1]<0)
		{
			j++;
			v=1;gl=1;gr=q[j];
			upd(1,1,n);
		}
		ans[j]=i-1;
		//printf("%d %d\n",j,i-1);
	}
	ans[0]=n;printf("%d ",n);
	for(int i=1;i<n;i++)
	{
		if(ans[i]==0)ans[i]=ans[i-1];
		printf("%d ",ans[i]); 
	}
	return 0;
}