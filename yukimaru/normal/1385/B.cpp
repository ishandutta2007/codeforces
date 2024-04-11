/*********************************************************************
    > File Name: 1385_B.cpp
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
		int a[105]={0};
		for(int i=1; i<=2*n; i++) scanf("%d", &a[i]);
		bool f[55]={0};
		int cnt=0;
		for(int i=1; i<=2*n; i++)
			if(!f[a[i]])
			{
				f[a[i]]=1;
				printf("%d", a[i]);
				cnt++;
				if(cnt == n)
				{
					printf("\n");
					break;
				}
				else printf(" ");
			}
	}
	return 0;
}