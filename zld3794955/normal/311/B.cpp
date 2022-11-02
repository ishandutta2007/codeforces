#include<bits/stdc++.h>
using namespace std;
const int N=100010,M=100010,P=105;
int n,m,p,d[N]={},h[M]={},q[M]={};
long long s[M]={},f[M]={},g[M]={};
inline long long getf(int i,int j)
{
	return g[j]+s[j]-s[i]+(long long)h[i]*(i-j);
}
inline bool check(int j1,int j2,int i)
{
	return (g[j2]+s[j2]-g[j1]-s[j1])*(i-j2)<(g[i]+s[i]-g[j2]-s[j2])*(j2-j1);
}
int main()
{	
	scanf("%d%d%d",&n,&m,&p);
	
	for(int i=2;i<=n;++i)
		scanf("%d",&d[i]);
	for(int i=2;i<=n;++i)
		d[i]+=d[i-1];
	for(int i=1,t;i<=m;++i)
	{
		scanf("%d%d",&h[i],&t);
		h[i]=t-d[h[i]];
	}
	
	//for(int i=1;i<=m;++i)
	//	cin>>h[i];
	sort(h+1,h+m+1);
	for(int i=1;i<=m;++i)
		s[i]=s[i-1]+h[i];
	for(int i=1;i<=m;++i)
		f[i]=(long long)h[i]*i-s[i];
	for(int t=2;t<=p;++t)
	{
		fill(q,q+m+1,0);
		copy(f,f+m+1,g);
		int head=1,tail=0;
		q[++tail]=0;
		for(int i=1;i<=m;++i)
		{
			//if(h[i]<0)
			//	continue;
			while(head<tail && getf(i,q[head])>getf(i,q[head+1]))
				++head;
			f[i]=getf(i,q[head]);
			while(head<tail && !check(q[tail-1],q[tail],i))
				--tail;
			q[++tail]=i;
		}
	}
	cout<<f[m]<<endl;
	return 0;
}