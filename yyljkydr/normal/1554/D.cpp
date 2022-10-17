#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n/2;i++)
			putchar('a');
		putchar('b');
		for(int i=1;i<=n/2-1;i++)
			putchar('a');
		if(n%2==1&&n>1)
			putchar('c');
		puts("");
	}
}