#include<bits/stdc++.h>
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 2010
using namespace std;

int m,n,dir[4][2]={0,1,0,-1,1,0,-1,0},ds[N][N],cnt;
char mm[N][N];
queue<P>que;

inline void GG()
{
	puts("Not unique");
	exit(0);
}

inline bool hf(int u,int v)
{
	if(u<=0||u>m||v<=0||v>n) return 0;
	return 1;
}

inline void gx(int u,int v)
{
	int p,q,i;
	for(i=0;i<4;i++)
	{
		p=u+dir[i][0];
		q=v+dir[i][1];
		if(!hf(p,q)) continue;
		if(mm[p][q]=='.')
		{
			ds[p][q]--;
			if(ds[p][q]==1)
			{
				que.push(mp(p,q));
			}
		}
	}
}

inline void lj(int u,int v,int p,int q)
{
	if(u==p)
	{
		if(v>q) swap(v,q);
		mm[u][v]='<';
		mm[u][q]='>';
	}
	else
	{
		if(u>p) swap(u,p);
		mm[u][v]='^';
		mm[p][q]='v';
	}
}

int main()
{
	int i,j,k,p,q,np,nq;
	cin>>m>>n;
	for(i=1;i<=m;i++)
	{
		scanf("%s",mm[i]+1);
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(mm[i][j]=='*') continue;
			cnt++;
			for(k=0;k<4;k++)
			{
				p=i+dir[k][0];
				q=j+dir[k][1];
				if(!hf(p,q)) continue;
				if(mm[p][q]=='.')
				{
					ds[i][j]++;
				}
			}
			if(!ds[i][j]) GG();
			if(ds[i][j]==1) que.push(mp(i,j));
		}
	}
	for(;!que.empty();)
	{
		p=que.front().fi;
		q=que.front().se;
		que.pop();
		for(i=0;i<4;i++)
		{
			np=p+dir[i][0];
			nq=q+dir[i][1];
			if(!hf(np,nq)) continue;
			{
				if(mm[np][nq]=='.')
				{
					cnt-=2;
					lj(p,q,np,nq);
					gx(np,nq);
					break;
				}
			}
		}
	}
	if(cnt) GG();
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%c",mm[i][j]);
		}
		puts("");
	}
}