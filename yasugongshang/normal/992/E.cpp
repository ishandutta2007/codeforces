#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
long long maxv[1000005],sumv[1000005];
void update(int o,int l,int r,int p,int a)
{
	if(l==r)
	{
		maxv[o]=a;
		sumv[o]=a;
		return;
	}
	int m=(l+r)/2;
	if(p<=m)update(o*2,l,m,p,a);
	else update(o*2+1,m+1,r,p,a);
	maxv[o]=max(maxv[o*2],maxv[o*2+1]);
	sumv[o]=sumv[o*2]+sumv[o*2+1];
}
int getmax(int o,int l,int r,int ql,int qr)
{
	//printf("%d %d %d %d %d %lld\n",o,l,r,ql,qr,maxv[o]);
	if(ql<=l&&qr>=r)return maxv[o];
	int res=0;
	int m=(l+r)/2;
	if(ql<=m)res=max(res,getmax(o*2,l,m,ql,qr));
	if(qr>m)res=max(res,getmax(o*2+1,m+1,r,ql,qr));
	return res;
}
int find(int o,int l,int r,int a,int maxp)
{
	if(l==r)return l;
	int m=(l+r)/2;
	if(m>=maxp)return find(o*2,l,m,a,maxp);
	if(maxv[o*2]==a)return find(o*2,l,m,a,maxp);
	else return find(o*2+1,m+1,r,a,maxp);
}
int finds(int o,int l,int r,long long sum,int maxp)
{
	if(l==r)return l;
	int m=(l+r)/2;
	if(m>=maxp||sum<sumv[o*2])return finds(o*2,l,m,sum,maxp);
	else return finds(o*2+1,m+1,r,sum-sumv[o*2],maxp);
}
int get(int o,int l,int r,int p)
{
	if(l==r)return maxv[o];
	int m=(l+r)/2;
	if(p<=m)return get(o*2,l,m,p);
	else return get(o*2+1,m+1,r,p);
}
long long sum(int o,int l,int r,int ql,int qr)
{
	if(ql<=l&&qr>=r)return sumv[o];
	long long res=0;
	int m=(l+r)/2;
	if(ql<=m)res=res+sum(o*2,l,m,ql,qr);
	if(qr>m)res=res+sum(o*2+1,m+1,r,ql,qr);
	return res;
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		update(1,0,n,i,a);
	}
	for(int i=1;i<=q;i++)
	{
		int p,x;
		scanf("%d%d",&p,&x);
		update(1,0,n,p,x);
		int maxp=n,ok=0;
		while(!ok&&maxp)
		{
			//printf("%d:maxp:%d\n",i,maxp);
			int maxm=getmax(1,0,n,0,maxp);
			int p1=find(1,0,n,maxm,maxp);
			//printf("%d:%d\n",p1,maxm);
			if(p1==0)
			{
				ok=1;
				printf("1\n");
				break;
			}
			long long sum1=sum(1,0,n,0,p1-1);
			if(sum1==maxm)
			{
				ok=1;
				printf("%d\n",p1);
				break;
			}
			if(sum1==0)
			{
				//printf("**\n");
				int p2=finds(1,0,n,maxm,maxp);
				int m=get(1,0,n,p2);
				long long sum2=sum(1,0,n,0,p2-1);
				if(sum2==m)
				{
					ok=1;
					printf("%d\n",p2);
					break;
				}
			}
			int next=finds(1,0,n,maxm,p1);
			if(next==maxp)next--;
			maxp=next;
		}
		if(!ok)printf("-1\n");
	}
	return 0;
}
/*
sb 
*/