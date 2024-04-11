#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,d,s,len[2500001],b[2500001],pre[2500001],cnt0,cnt1,zhan[2500001],ans[5001];
long long f[10000001];
int getmin(int aa,int bb)
{
	if(aa<bb)return(aa);
	else return(bb);
}
int main()
{
	scanf("%d%d",&d,&s);
	for(int i=1;i<=d*s;i++)
	{
		len[i]=10000000; 
		pre[i]=-1;
	}
	cnt0=cnt1=0;
	for(int i=1;i<=9;i++)if(i<=s)
	{
		int x=i%d;
		len[x*s+i]=1;
		cnt1++;
		b[cnt1]=x*s+i;
		pre[x*s+i]=0;
	}
	for(int i=1;i<=10000000;i++)
	{
		cnt0=cnt1;
		if(cnt0==0)break;
		for(int j=1;j<=cnt0;j++)zhan[j]=b[j];
		cnt1=0;
		for(int j=1;j<=cnt0;j++)
		{
			int x=(zhan[j]-1)%s,c,posx,posy;
			x++;
			c=(zhan[j]-x)/s;
			for(int ii=0;ii<=9;ii++)if(x+ii<=s)
			{
				posx=(c*10+ii)%d;
				posy=x+ii;
				posx=posx*s+posy;
				if(len[posx]>i+1)
				{
					pre[posx]=zhan[j];
					len[posx]=i+1;
					cnt1++;
					b[cnt1]=posx;
				}
			}
		}
	}
	if(pre[s]==-1)printf("-1\n");
	else
	{
		int nw=s;
		cnt0=0;
		while(nw!=0)
		{
			if(pre[nw]==0)
			{
				nw=(nw-1)%s;
				nw++;
				cnt0++;
				ans[cnt0]=nw;
				break;
			}
			int cc=(pre[nw]-1)%s,dd=(nw-1)%s;
			cnt0++;
			ans[cnt0]=dd-cc;
			nw=pre[nw];
		}
		for(int i=cnt0;i>=1;i--)printf("%d",ans[i]);
	}
}