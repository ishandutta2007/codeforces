/*********************************************************************
    > File Name: 1355_B.cpp
    > Author: yuki
 *********************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, a[200005]={0};
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		sort(a+1, a+1+n);
		int ans=0, cnt=0;
		for(int i=1; i<=n; i++)
		{
			cnt++;
//			printf("!%d\n", cnt);
			if(cnt >= a[i])
			{
				ans++;
				cnt=0;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}