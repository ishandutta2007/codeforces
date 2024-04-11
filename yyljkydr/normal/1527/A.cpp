#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=30;i>=0;i--)
		{
			if(n&(1<<i))
			{
				printf("%d\n",(1<<i)-1);
				break;
			}
		}
	}
}