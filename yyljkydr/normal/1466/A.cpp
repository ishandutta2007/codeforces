#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,x[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&x[i]);
		set<int>s;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				s.insert(x[j]-x[i]);
		printf("%d\n",s.size());
	}
}