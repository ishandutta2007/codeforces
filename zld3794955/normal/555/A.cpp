#include<bits/stdc++.h>
using namespace std;
const int N=100010,K=100010;
int n,k;
vector<int> v[K];
void init()
{
	scanf("%d%d",&n,&k);
	for(int i=1,x,y;i<=k;++i)
	{
		scanf("%d",&x);
		while(x--)
		{
			scanf("%d",&y);
			v[i].push_back(y);
		}
	}
}
void work()
{
	int ans=n+n-k-1;
	for(int i=1;i<=k;++i)
	{
		if(v[i].front()==1)
			for(int j=1;j<(int)v[i].size();++j)
				if(v[i][j]==j+1)
					ans-=2;
	}
	printf("%d\n",ans);
}
int main()
{	
	init();
	work();
	return 0;
}