#include<bits/stdc++.h>
using namespace std;
const int N=102000;
int r,n,t[N]={},x[N]={},y[N]={},f[N]={},ans=0;
int main()
{
	scanf("%d%d",&r,&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d%d",t+i,x+i,y+i);
	t[0]=0,x[0]=1,y[0]=1;
	int v=-n-1;
	for(int i=1;i<=n;++i)
	{
		f[i]=v+1;
		for(int j=max(0,i-r-r);j<i;++j)
			if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])
				f[i]=max(f[i],f[j]+1);
		if(i-r-r>=0)
			v=max(v,f[i-r-r]);
		ans=max(f[i],ans);
	}
	printf("%d\n",ans);
	cerr<<clock()<<endl;
}