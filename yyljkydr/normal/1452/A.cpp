#include<bits/stdc++.h>
using namespace std;

int T,x,y;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&x,&y);
		int ans=min(x,y)*2+max((max(x,y)-min(x,y))*2-1,0);
		printf("%d\n",ans);
	}
}