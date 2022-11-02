#include <bits/stdc++.h>
using namespace std;
int ans[5],q;
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		int n;
		scanf("%d",&n);
		ans[2]=ans[3]=100000;
		ans[1]=ans[4]=-100000;
		for(int i=1;i<=n;i++)
		{
			int x,y,f[6];
			scanf("%d%d%d%d%d%d",&x,&y,&f[1],&f[2],&f[3],&f[4]);
			if(!f[1]) ans[1]=max(ans[1],x);
			if(!f[2]) ans[2]=min(ans[2],y);
			if(!f[3]) ans[3]=min(ans[3],x);
			if(!f[4]) ans[4]=max(ans[4],y);
		}
		if(ans[1]<=ans[3]&&ans[4]<=ans[2])
			printf("1 %d %d\n",ans[3],ans[2]);
		else printf("0\n");
	}
	return 0;
}