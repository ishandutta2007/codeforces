#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#define SIZE 100005

using namespace std;

vector <int> nd[SIZE];
int a[SIZE],b[SIZE];
int tg[SIZE];
int fir[SIZE];

int main()
{
	int n,m,s,e;
	scanf("%d %d %d %d",&n,&m,&s,&e);
	memset(fir,-1,sizeof(fir));
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);a[i]--;
		if(fir[a[i]]==-1) fir[a[i]]=i;
		nd[a[i]].push_back(i);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
		b[i]--;
	}
	memset(tg,-1,sizeof(tg));
	int now=n;
	for(int i=0;i<m;i++)
	{
		if(fir[b[i]]!=-1&&fir[b[i]]<now&&(i+1)+(fir[b[i]]+1)+e<=s)
		{
			tg[i]=fir[b[i]];
			now=fir[b[i]];
		}
	}
	for(int t=1;;t++)
	{
		bool up=false;
		for(int i=0;i<m;i++)
		{
			if(tg[i]!=-1)
			{
				up=true;
				break;
			}
		}
		if(!up)
		{
			printf("%d\n",t-1);
			break;
		}
		int now=m-1;
		for(int i=m-1;i>=0;i--)
		{
			while(now>=0&&(now>=i||tg[now]==-1)) now--;
			if(now==-1) tg[i]=-1;
			else
			{
				int p=upper_bound(nd[b[i]].begin(),nd[b[i]].end(),tg[now])-nd[b[i]].begin();
				if(p<nd[b[i]].size())
				{
					tg[i]=nd[b[i]][p];
					if(s<(t+1)*e+(i+1)+(tg[i]+1)) tg[i]=-1;
				}
				else tg[i]=-1;
			}
		}
		now=n;
		for(int i=0;i<m;i++)
		{
			if(tg[i]!=-1)
			{
				if(now<=tg[i]) tg[i]=-1;
				else now=tg[i];
			}
		}
	}
	return 0;
}