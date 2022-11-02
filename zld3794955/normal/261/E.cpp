#include<bits/stdc++.h>
using namespace std;
const int N=3000030,prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,
61,67,71,73,79,83,89,97},Inf=1<<20;
int l,r,p,a[N]={},tot=0,f[N]={},g[N]={};
void tryy(int t,int l)
{
	a[++tot]=t;
	for(int i=l;i<25;++i)
		if(r/prime[i]>=t)
			tryy(t*prime[i],i);
}
int main()
{	
	cin>>l>>r>>p;
	tryy(1,0);
	sort(a+1,a+tot+1);
	fill(f+1,f+tot+1,Inf);
	fill(g+1,g+tot+1,Inf);
	g[1]=0,f[1]=1;
	for(int j=2;j<=p;++j)
		for(int i=1,l=1;i<=tot;++i)
		{
			while(a[l]*j<a[i])
				++l;
			++f[i];
			if(a[l]*j==a[i])
				f[i]=min(f[i],f[l]+1);
			g[i]=min(g[i],f[i]); 
		}
	int ans=0;
	for(int i=1;i<=tot;++i)
		ans+=(a[i]>=l && a[i]<=r && g[i]<=p);
	cout<<ans<<endl;
	return 0;
}