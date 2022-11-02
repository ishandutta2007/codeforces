#include<bits/stdc++.h>
using namespace std;
const int N=1000100,v=1000000;
vector<int> d[N];
int n,pos[N]={},f[N]={},ans=0;
int main()
{
	scanf("%d",&n);
	for(int i=1,x=0;i<=n;++i)
	{
		scanf("%d",&x);
		pos[x]=i;
	}
	for(int i=v;i>=1;--i)
	{
		if(!pos[i])
			continue;
		for(int j=i;j<=v;j+=i)
			f[i]=max(f[i],f[j]+1);
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}