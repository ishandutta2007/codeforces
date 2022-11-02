#include<bits/stdc++.h>
using namespace std;
const int N=22,Inf=1<<28;
int n,a[N][N]={},b[N][N]={},day[N]={},v[N][N]={},ans=0,state[200000]={};
int match[N]={},nx[N]={},ny[N]={},now=0,vx[N]={},vy[N]={},slack[N]={};
int calctime=0; 
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&b[i][j]);
}
int dfs(int s)
{
	if(nx[s]==now)
		return 0;
	nx[s]=now;
	for(int i=1;i<=n;++i)
		if(vx[s]+vy[i]==v[s][i])
		{
			if(match[i]==0 || dfs(match[i]))
			{
				match[i]=s;
				return 1;
			}
			ny[i]=now;
		}
		else
			slack[i]=min(slack[i],vx[s]+vy[i]-v[s][i]);
	return 0;
}
int calc()
{
	fill(match+1,match+n+1,0);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			v[i][j]=day[i]==1 ? a[i][j] : b[i][j];
	if(rand()%2)
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				swap(v[i][j],v[j][i]);
	fill(vx+1,vx+n+1,0);
	fill(vy+1,vy+n+1,0);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			vx[i]=max(vx[i],v[i][j]),vy[j]=max(vy[j],v[i][j]);
	if(accumulate(vy+1,vy+n+1,0)<=ans)
		return 0;
	fill(vy+1,vy+n+1,0);
	int sum=accumulate(vx+1,vx+n+1,0);
	if(sum<=ans)
		return 0;
	calctime+=8;
	for(int i=1;i<=n;++i)
	{
		fill(slack+1,slack+n+1,Inf);
		while(++now && !dfs(i))
		{
			int d=Inf;
			for(int j=1;j<=n;++j)
				if(ny[j]!=now)
					d=min(d,slack[j]);
			for(int j=1;j<=n;++j)
				if(nx[j]==now)
					vx[j]-=d,sum-=d;
			for(int j=1;j<=n;++j)
				if(ny[j]==now)
					vy[j]+=d,sum+=d;
				else
					slack[j]-=d;
			if(sum<=ans)
				return 0;
			calctime+=6;
		}
	}
	return sum;
}
void work()
{
	int tot=0;
	for(int i=0;i<(1<<n);++i)
	{
		int t=0;
		for(int x=i;x;x-=x&(-x))
			++t;
		if(t==n/2)
			state[++tot]=i;
	}
	random_shuffle(state+1,state+tot+1);
	for(int i=1;i<=tot;++i)
	{
		for(int d=0;d<n;++d)
			day[d+1]=!!(state[i]&(1<<d))+1;
		ans=max(ans,calc());
		if(calctime>=10000000)
			break;
	}
	printf("%d\n",ans);
}
int main()
{	
	//freopen("C.in","r",stdin);
	//freopen("C.ans","w",stdout);
	srand(time(0));
	init();
	cerr<<clock()<<endl;
	work();
	cerr<<clock()<<endl;
	cerr<<"calc="<<calctime<<endl;
	return 0;
}