#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,l[4000001],r[4000001],k,v[1000001],li[1000001],ri[1000001],fir[1000001],nex[2000021],c[1000001];
long long sum[4000001],ans,sz[4000001];
void built(int num,int x,int y)
{
	l[num]=x;
	r[num]=y;
	sum[num]=0;
	sz[num]=0;
	if(x==y)return;
	int mid=(x+y)/2;
	built(num*2,x,mid);
	built(num*2+1,mid+1,y);
}
long long ask(int num,long long dbd)
{
	if(dbd>=sz[num])return(sum[num]);
	if(l[num]==r[num])return(1ll*dbd*l[num]);
	if(sz[num*2]>=dbd)return(ask(num*2,dbd));
	else return(ask(num*2+1,dbd-sz[num*2])+sum[num*2]);
}
void gai(int num,int x,long long dbd)
{
	if(l[num]==r[num])
	{
		sz[num]=sz[num]+dbd;
		sum[num]=1ll*sz[num]*l[num];
		return;
	}
	int mid=(l[num]+r[num])/2;
	if(x<=mid)gai(num*2,x,dbd);
	else gai(num*2+1,x,dbd);
	sum[num]=sum[num*2]+sum[num*2+1];
	sz[num]=sz[num*2]+sz[num*2+1];
}
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d%d",&li[i],&ri[i],&c[i],&v[i]);
	for(int i=1;i<=m;i++)
	{
		nex[2*i]=fir[li[i]];
		fir[li[i]]=2*i;
		if(ri[i]<n)
		{
			nex[2*i+1]=fir[ri[i]+1];
			fir[ri[i]+1]=2*i+1;
		}
	}
	built(1,1,1000000);
	ans=0;
	for(int i=1;i<=n;i++)
	{
		int aa=fir[i];
		while(aa!=0)
		{
			int cc=aa/2; 
			if((aa%2)==0)gai(1,v[cc],c[cc]);
			else gai(1,v[cc],0-c[cc]);
			aa=nex[aa];
		}
		ans=ans+ask(1,k);
	}
	printf("%I64d\n",ans);
}