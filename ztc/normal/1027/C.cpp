#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int n,q,a,cnt,b,ans1,ans2;
priority_queue<int>Q;
int main()
{
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&n);
		ans1=10000;
		ans2=1;
		b=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a);
			Q.push(a);
		}
		a=Q.top();
		Q.pop();
		while(!Q.empty())
		{
			if(a==Q.top())
			{
				if(b&&a*ans1>b*ans2)
				{
					ans1=b;
					ans2=a;
				}
				b=a;
				a=0;
			}
			else a=Q.top();
			Q.pop();
		}
		printf("%d %d %d %d\n",ans1,ans1,ans2,ans2);
	}
}