#include<cstdio>
#include<cstring>

using namespace std;

#define minn(a,b)((a)<(b)?(a):(b))

struct jui
{
	int prc;
	bool a,b,c;
}all[1001]={};

char tmp[4]={};

const long long MAXN=1e15;

long long ans[2][2][2]={};

int main()
{
	int n=0;
	scanf("%d",&n);
	for(int i=1,len=0;i<=n;i++)
	{
		scanf("%d%s",&all[i].prc,tmp);
		len=strlen(tmp);
		for(int j=0;j<len;j++)
		{
			switch(tmp[j])
			{
				case 'A':
					all[i].a=true;
					break;
				case 'B':
					all[i].b=true;
					break;
				case 'C':
					all[i].c=true;
					break;
			}
		}
	}
	
	ans[0][0][0]=0;
	ans[0][0][1]=ans[0][1][0]=ans[1][0][0]
	=ans[0][1][1]=ans[1][0][1]=ans[1][1][0]
	=ans[1][1][1]=MAXN;
	for(int i=1;i<=n;i++)
	{
		for(int A=1;A>=0;A--)
		{
			for(int B=1;B>=0;B--)
			{
				for(int C=1;C>=0;C--)
				{
					ans[A][B][C]=
					minn(ans[A][B][C],
					ans[A&&!all[i].a][B&&!all[i].b][C&&!all[i].c]+all[i].prc);
				}
			}
		}
	}
	if(ans[1][1][1]>=MAXN)
	{
		printf("-1");
	}
	else
	{
		printf("%lld",ans[1][1][1]);
	}
	return 0;
}