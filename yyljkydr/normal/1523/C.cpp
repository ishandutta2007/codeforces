#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

int a[N];

int st[N],top;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		top=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
				st[++top]=1;
			else
			{
				while(top&&st[top]!=a[i]-1)
					top--;
				if(top)
					top--;
				st[++top]=a[i];
			}
			for(int i=1;i<=top;i++)
				printf("%d%c",st[i],".\n"[i==top]);
		}
	}
}