#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x[6005],y[6005],cnt[2][2];
ll ans0=0,ans1=0;
int cnte(int u1,int v1,int u2,int v2)
{
	int u=abs(u1-u2)&1,v=abs(v1-v2)&1;
	if(u||v)return 1;
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++)x[i]=(x[i]/2)&1,y[i]=(y[i]/2)&1;
	for(int i=1;i<=n;i++)cnt[x[i]][y[i]]++;
	//printf("@@%d\n",cnt[1][1]);
	for(int u1=0;u1<2;u1++)
	{
		for(int v1=0;v1<2;v1++)
		{
			for(int u2=0;u2<2;u2++)
			{
				for(int v2=0;v2<2;v2++)
				{
					//printf("#%d %d %d %d %d\n",u1,v1,u2,v2,cnt[1][1]);
					if(!cnt[u1][v1]||!cnt[u2][v2])continue;
					if(u1==u2&&v1==v2&&cnt[u1][v1]<2)continue;
					//printf("#%d %d %d %d\n",u1,v1,u2,v2);


					int u=abs(u1-u2)&1,v=abs(v1-v2)&1;

					if(u||v)continue;
					cnt[u1][v1]--;
					cnt[u2][v2]--;
					for(int i=0;i<2;i++)
					{
						for(int j=0;j<2;j++)
						{
							if(!cnt[i][j])continue;
							//printf("!%d %d %d\n",i,j,cnt[i][j]);
							int a=cnte(u1,v1,i,j),b=cnte(u2,v2,i,j);
							ll tmp;
							if(u1!=u2||v1!=v2)tmp=1ll*(cnt[u1][v1]+1)*(cnt[u2][v2]+1)*cnt[i][j];
							else tmp=1ll*(cnt[u1][v1]+2)*(cnt[u1][v1]+1)*cnt[i][j];
							if(a==1&&b==1)ans1+=tmp;
							else if(a==0&&b==0)ans0+=tmp;
						}
					}
					cnt[u1][v1]++;
					cnt[u2][v2]++;
				}
			}
		}
	}
	//printf("%lld %lld\n",ans0,ans1);
	printf("%lld\n",ans1/2ll+ans0/6ll);
	return 0;
}