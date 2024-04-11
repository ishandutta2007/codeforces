#include<bits/stdc++.h>
using namespace std;
 
int T,n;
 
map<long long,int>vis;
 
int main()
{
	scanf("%d",&n);
	long long s=0;
	vis[s]=1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		s+=x;
		if(vis.count(s))
		{
			vis.clear();
			vis[0]=1;
			vis[x]=1;
			s=x;
			ans++;
		}
		else
			vis[s]=1;
	}
	printf("%d\n",ans);
}