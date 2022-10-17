/*********************************************************************
    > File Name: 1367_B.cpp
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
		int n, a[50]={0};
		scanf("%d", &n);
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		int cnt1=0, cnt2=0;
		for(int i=0; i<n; i++)
			if(a[i]%2 != i%2)
			{
				if(a[i]%2 == 0) cnt1++;
				else cnt2++;
			}
		if(cnt1 != cnt2) printf("-1\n");
		else printf("%d\n", cnt1);
	}
	return 0;
}