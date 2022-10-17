/*********************************************************************
    > File Name: 1385_C.cpp
    > Author: yuki
 *********************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int a[200005]={0};
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		int now=n;
		while((a[now]==a[now-1]) && (now>1)) now--;
		if(now == 1)
		{
			printf("0\n");
			continue;
		}
		int bef=0;
		if(a[now] < a[now-1]) bef=1;
		if(a[now] > a[now-1]) bef=-1;
		if(bef == 1)
		{
			while((a[now]<=a[now-1]) && (now>1))
				now--;
			bef=-1;
		}
		if(now == 1)
		{
			printf("0\n");
			continue;
		}
		if(bef == -1)
		{
			while((a[now]>=a[now-1]) && (now>1))
				now--;
		}
		printf("%d\n", now-1);
	}
	return 0;
}