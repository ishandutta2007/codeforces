/*********************************************************************
    > File Name: 1367_C.cpp
    > Author: yuki
 *********************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node
{
	int st, ed;
};

node a[200005];

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		char s[200005]={0};
		scanf("%s", s+1);
		int cnt=0;
		for(int i=1; i<=n; i++)
			if(s[i] == '1')
			{
				cnt++;
				a[cnt].st=max(i-k, 1);
				a[cnt].ed=min(i+k, n);
			}
		cnt++;
		a[cnt].st=n+1;
		a[cnt].ed=n+1;
		int ans=0, now=1;
		for(int i=1;;)
		{
			while(i < a[now].st)
			{
				ans++;
				i+=(k+1);
			}
			i=a[now].ed+1;
			if(i > n) break;
			now++;
		}
		printf("%d\n", ans);
	}
	return 0;
}