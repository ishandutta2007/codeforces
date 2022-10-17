#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,m;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		m++;
		int ans=0;
		for(int i=29;i>=0;i--)
		{
			if((m&(1<<i)) && !(n&(1<<i)))
				ans+=1<<i;
			else if(!(m&(1<<i)) && (n&(1<<i)))
				break;
		}
		printf("%d\n",ans);
	}
}