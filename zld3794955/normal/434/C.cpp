#include<bits/stdc++.h>
using namespace std;
const int Base=22,mod=1000000007,L=202,N=202,V=505,root=0;
struct node
{
	int to[Base],fail,val;
}t[N]={};
int n,m,k,l[L]={},r[L]={},tot=0;
long long f[2][N][V][2][2]={};
void init()
{
	scanf("%d%d%d%d",&n,&m,&k,&l[0]);
	for(int i=1;i<=l[0];++i)
		scanf("%d",&l[i]);
	for(int i=l[0];i && (--l[i])<0;--i)
		l[i]=m-1;
	scanf("%d",&r[0]);
	for(int i=1;i<=r[0];++i)
		scanf("%d",&r[i]);
	for(int i=1;i<=n;++i)
	{
		int l=0,now=root,x=0;
		scanf("%d",&l);
		while(l--)
		{
			scanf("%d",&x);
			if(t[now].to[x]==0)
				t[now].to[x]=++tot;
			now=t[now].to[x];
		}
		scanf("%d",&x);
		t[now].val+=x;
	}
}
void get_fail()
{
	int q[N]={},head=0,tail=0;
	for(int i=0;i<m;++i)
		if(t[root].to[i])
			q[++tail]=t[root].to[i];
	while(head!=tail)
		for(int s=q[++head],i=0;i<m;++i)
			if(int j=t[s].to[i])
			{
				t[j].fail=t[t[s].fail].to[i];
				q[++tail]=j;
				t[j].val+=t[t[j].fail].val;
			}
			else
				t[s].to[i]=t[t[s].fail].to[i];
}
long long dp(int l,int *a)
{
	int pre=1,now=0;
	for(int i=0;i<=tot;++i)
		for(int j=0;j<=k;++j)
		{
			f[now][i][j][0][0]=f[now][i][j][0][1]=0;
			f[now][i][j][1][0]=f[now][i][j][1][1]=0;
		}
	f[now][root][0][1][1]=1;
	for(int p=1;p<=l;++p)
	{
		swap(pre,now);
		for(int i=0;i<=tot;++i)
			for(int j=0;j<=k;++j)
			{
				f[now][i][j][0][0]=f[now][i][j][0][1]=0;
				f[now][i][j][1][0]=f[now][i][j][1][1]=0;
			}
		for(int i=0;i<=tot;++i)
			for(int j=0;j<=k;++j)
			{
				f[pre][i][j][0][0]%=mod;
				f[pre][i][j][0][1]%=mod;
				f[pre][i][j][1][0]%=mod;
				f[pre][i][j][1][1]%=mod;
				for(int d=0;d<=a[p];++d)
				{
					int next=t[i].to[d],v=j+t[next].val;
					if(d==0)
					{
						f[now][i][j][1][d==a[p]]+=f[pre][i][j][1][1];
						f[now][i][j][1][0]+=f[pre][i][j][1][0];
					}
					if(v>k)
						continue;
					if(d)
					{
						f[now][next][v][0][d==a[p]]+=f[pre][i][j][1][1];
						f[now][next][v][0][0]+=f[pre][i][j][1][0];
					}
					f[now][next][v][0][d==a[p]]+=f[pre][i][j][0][1];
					f[now][next][v][0][0]+=f[pre][i][j][0][0];
				}
				for(int d=a[p]+1;d<m;++d)
				{
					int next=t[i].to[d],v=j+t[next].val;
					if(v>k)
						continue;
					f[now][next][v][0][0]+=f[pre][i][j][0][0];
					f[now][next][v][0][0]+=f[pre][i][j][1][0];
				}
			}
	}
	long long s=0;
	for(int i=0;i<=tot;++i)
		for(int j=0;j<=k;++j)
		{
			s+=f[now][i][j][0][0];
			s+=f[now][i][j][0][1];
			s+=f[now][i][j][1][0];
			s+=f[now][i][j][1][1];
		}
	return s%mod;
}
void work()
{
	long long sr=dp(r[0],r),sl=dp(l[0],l);
	cout<<(sr-sl+mod)%mod<<endl;
}
int main()
{	
	init();
	get_fail();
	work();
	return 0;
}