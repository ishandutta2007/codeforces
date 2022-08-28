#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 505

using namespace std;
typedef pair <int,int> P;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
char mp[SIZE][SIZE];
int cmb[SIZE][SIZE];
int nd[SIZE*SIZE];
int cnt[SIZE*SIZE];
int n,k;

int pl(int x,int y)
{
	int ret=0;
	for(int i=0;i<2;i++)
	{
		int px=i==0?x-1:x+k;
		if(0<=px&&px<n)
		{
			for(int j=y;j<y+k;j++)
			{
				if(mp[px][j]!='X')
				{
					int c=cmb[px][j];
					if(cnt[c]==0) ret+=nd[c];
					cnt[c]++;
				}
			}
		}
	}
	for(int i=0;i<2;i++)
	{
		int py=i==0?y-1:y+k;
		if(0<=py&&py<n)
		{
			for(int j=x;j<x+k;j++)
			{
				if(mp[j][py]!='X')
				{
					int c=cmb[j][py];
					if(cnt[c]==0) ret+=nd[c];
					cnt[c]++;
				}
			}
		}
	}
	for(int i=0;i<2;i++)
	{
		int px=i==0?x-1:x+k;
		if(0<=px&&px<n) for(int j=y;j<y+k;j++) if(mp[px][j]!='X') cnt[cmb[px][j]]--;
	}
	for(int i=0;i<2;i++)
	{
		int py=i==0?y-1:y+k;
		if(0<=py&&py<n) for(int j=x;j<x+k;j++) if(mp[j][py]!='X') cnt[cmb[j][py]]--;
	}
	return ret;
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%s",&mp[i]);
	memset(cmb,-1,sizeof(cmb));
	int sz=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(mp[i][j]=='X')
			{
				cmb[i][j]=sz;
				nd[sz++]=1;
			}
			else if(cmb[i][j]==-1)
			{
				queue <P> que;
				que.push(P(i,j));
				cmb[i][j]=sz;
				nd[sz]=1;
				while(!que.empty())
				{
					P p=que.front();que.pop();
					int x=p.first,y=p.second;
					for(int t=0;t<4;t++)
					{
						int nx=x+dx[t],ny=y+dy[t];
						if(0<=nx&&nx<n&&0<=ny&&ny<n&&mp[nx][ny]=='.'&&cmb[nx][ny]==-1)
						{
							cmb[nx][ny]=sz;
							nd[sz]++;
							que.push(P(nx,ny));
						}
					}
				}
				sz++;
			}
		}
	}
	int ret=0;
	//Hv...
	//O(k)Aok
	for(int i=0;i+k<=n;i++)
	{
		int now=0;
		memset(cnt,0,sizeof(cnt));
		for(int p=0;p<k;p++)
		{
			for(int j=i;j<i+k;j++)
			{
				int c=cmb[j][p];
				if(cnt[c]==0) now+=nd[c];
				cnt[c]++;
			}
		}
		ret=max(ret,now+pl(i,0));
		//printf("%d %d : %d %d\n",i,0,now,pl(i,0));
		for(int p=1;p+k<=n;p++)
		{
			for(int j=i;j<i+k;j++)
			{
				int c=cmb[j][p-1];
				if(cnt[c]==1) now-=nd[c];
				cnt[c]--;
				c=cmb[j][p+k-1];
				if(cnt[c]==0) now+=nd[c];
				cnt[c]++;
			}
			ret=max(ret,now+pl(i,p));
			//printf("%d %d : %d %d\n",i,p,now,pl(i,p));
		}
	}
	printf("%d\n",ret);
	return 0;
}