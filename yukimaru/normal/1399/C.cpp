/*********************************************************************
    > File Name: 1399_C.cpp
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
		int w[55]={0}, num[105]={0};
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &w[i]);
			num[w[i]]++;
		}
		int ans=0, tmp;
		for(int s=2; s<=2*n; s++)
		{
			tmp=0;
			for(int i=1; i<=(s/2); i++)
				tmp+=min(num[i], num[s-i]);
			if(s%2 == 0) tmp-=(num[s/2]-(num[s/2]/2));
			ans=max(ans, tmp);
		}
		printf("%d\n", ans);
	}
	return 0;
}