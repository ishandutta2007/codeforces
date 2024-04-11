#include <cstdio>
#include <cassert>

using namespace std;

bool use[100005];
bool pr[100005];
int left[100005];
int right[100005];

int main()
{
	int n;
	scanf("%d",&n);
	int sz=0;
	for(int i=2;i<=n;i++)
	{
		if(!pr[i])
		{
			for(int j=i*2;j<=n;j+=i) pr[j]=true;
		}
	}
	//int all=n;
	//for(int i=n/2+1;i<=n;i++) if(!pr[i]) all--;
	//printf("%d\n",all/2);
	for(int i=n/2;i>=2;i--)
	{
		if(!pr[i])
		{
			int cnt=0;
			for(int j=i;j<=n;j+=i)
			{
				if(!use[j])
				{
					cnt++;
				}
			}
			//if(i!=2) assert(cnt>1);
			if(cnt%2==0)
			{
				int bef=-1;
				for(int j=i;j<=n;j+=i)
				{
					if(!use[j])
					{
						use[j]=true;
						if(bef==-1) bef=j;
						else
						{
							left[sz]=bef;
							right[sz]=j;
							bef=-1;
							sz++;
						}
					}
				}
			}
			else
			{
				int bef=i;
				use[i]=true;
				for(int j=i*(i==2?2:3);j<=n;j+=i)
				{
					if(!use[j])
					{
						use[j]=true;
						if(bef==-1) bef=j;
						else
						{
							left[sz]=bef;
							right[sz]=j;
							bef=-1;
							sz++;
						}
					}
				}
				//if(bef!=-1) printf("%d\n",bef);
			}
		}
	}
	printf("%d\n",sz);
	for(int i=0;i<sz;i++) printf("%d %d\n",left[i],right[i]);
	//int cnt=0;
	//for(int i=2;i<=n;i++) if(!use[i]&&!(i>=n/2+1&&!pr[i])) printf("%d\n",i);
	//for(int i=2;i<=n;i++) if(use[i]) cnt++;
	//printf("%d\n",cnt/2);
	return 0;
}