#include<bits/stdc++.h>
#define N 110
using namespace std;

int T,n,now,pj,mm[N][N],a[N][N],b[N][N],pp[N],num[N][N],pos[N];
char str[5];
queue<int>que;

inline bool cmp(int u,int v){return a[pj][u]>a[pj][v];}
inline void calc()
{
    memset(pp,0,sizeof(pp));
    int i,j;
    for(pj=1;pj<=n;pj++)
    {
	for(i=1;i<=n;i++)
	{
	    num[pj][i]=i;
	}
	sort(num[pj]+1,num[pj]+n+1,cmp);
	que.push(pj);
	pos[pj]=1;
    }
    for(;!que.empty();)
    {
	int t=que.front();
	que.pop();
	for(int &j=pos[t];j<=n;j++)
	{
	    i=num[t][j];
	    if(!pp[i+n])
	    {
		pp[i+n]=t;
		pp[t]=i+n;
		break;
	    }
	    else if(b[i][t]>b[i][pp[i+n]])
	    {
		int gg=pp[i+n];
		pp[i+n]=t;
		pp[t]=i+n;
		que.push(gg);
		break;
	    }
	}
    }
}

int main()
{
    int i,j;
    cin>>T;
    while(T--)
    {
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	    for(j=1;j<=n;j++)
	    {
		scanf("%d",&mm[i][j]);
	    }
	}
	puts("B");fflush(stdout);
	scanf("%s%d",str+1,&now);
	if(str[1]=='D')
	{
	    for(i=1;i<=n;i++)
	    {
		for(j=1;j<=n;j++)
		{
		    mm[i][j]=-mm[i][j];
		}
	    }
	}
	if(now<=n)
	{
	    for(i=1;i<=n;i++)
	    {
		for(j=1;j<=n;j++)
		{
		    a[i][j]=-mm[i][j];
		    b[j][i]=mm[i][j];
		}
	    }
	}
	else
	{
	    for(i=1;i<=n;i++)
	    {
		for(j=1;j<=n;j++)
		{
		    a[i][j]=mm[i][j];
		    b[j][i]=-mm[i][j];
		}
	    }
	}
	calc();
	for(;now!=-1;)
	{
	    printf("%d\n",pp[now]);
	    fflush(stdout);
	    scanf("%d",&now);
	}
    }
}