#include<bits/stdc++.h>
using namespace std;
const int N=100010,K=100010,D=1000,Inf=1<<30;
int n,m,k,f[D]={},g[D]={};
vector<int> v[N+D];
int main()
{
	scanf("%d%d",&n,&k);
	m=min(D,min((int)sqrt(k*6),n)+3);
	for(int i=1,x,y;i<=k;++i)
	{
		scanf("%d%d",&x,&y);
		v[y].push_back(n+1-x);
	}
	for(int j=1;j<m;++j)
		f[j]=Inf;
	f[0]=0;
	int ans=Inf;
	for(int i=1;i<=n+m;++i)
	{
		sort(v[i].begin(),v[i].end());
		copy(f,f+m,g),fill(f,f+m,0);
		auto it=v[i].begin();
		int tmp=Inf;
		for(int j=0;j<m-1;++j)
		{
			while(it!=v[i].end() && *it==j)
				++it;
			tmp=min(g[j],tmp);
			f[j]=min(g[j+1],tmp+2+j*(j+1)/2)+3*(v[i].end()-it);
		}
		f[0]=min(f[0],g[0]+3*(int)v[i].size());
		f[m-1]=Inf;
		k-=v[i].size();
		if(k==0)
			ans=min(ans,f[0]);
	}
	printf("%d\n",ans);
	return 0;
}