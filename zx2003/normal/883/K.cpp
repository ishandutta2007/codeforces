#include <cstdio>
#include <set>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ref(i,x,y)for(int i=x;i<=y;++i)
#define def(i,x,y)for(int i=x;i>=y;--i)
const int N=200001;
int n;
int r[N],s[N],g[N],G[N];
int main()
{
	scanf("%d",&n);
	ref(i,1,n)
	{
		scanf("%d%d",&s[i],&g[i]);
		g[i]+=s[i];
	}
	ref(i,1,n)G[i]=g[i]+i;
	def(i,n-1,1)G[i]=min(G[i],G[i+1]);
	ref(i,1,n)
	{
		r[i]=G[i]-i;
		if(i>1)r[i]=min(r[i],r[i-1]+1);
		if(r[i]<s[i])
		{
			cout<<"-1"<<endl;
			exit(0);
		}
	}
	long long ans=0;
	ref(i,1,n)ans+=r[i]-s[i];
	cout<<ans<<endl;
	ref(i,1,n)printf("%d ",r[i]);
	printf("\n");
}