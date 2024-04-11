#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n,d,a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&d);
		int mx=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),mx=max(mx,a[i]);
		if(d<mx)
		{
			int fl=0;
			for(int i=1;i<=n;i++)
				if(a[i]==d)
					fl=1;
			printf("%d\n",2-fl);
		}
		else
			printf("%d\n",(int)ceil(1.0*d/mx));
	}
}