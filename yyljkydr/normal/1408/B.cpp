#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,p[N];

int n,k,a[N],b[N],c[N];

set<int>s;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		s.clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),s.insert(a[i]);
		int t=s.size();
		if(k==1)
		{
			if(t==1)
				printf("%d\n",1);
			else
				printf("%d\n",-1);
		}
		else
		{
			printf("%d\n",max(1,(t-1+k-2)/(k-1)));
		}
	}
}