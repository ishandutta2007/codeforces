#include<bits/stdc++.h>
using namespace std;

int T;

int a,b,c;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if((a+b+c)%9==0&&(a+b+c)/9<=min(min(a,b),c))
			puts("YES");
		else
			puts("NO");
	}
}