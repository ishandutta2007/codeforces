#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

long long a,b;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		cin>>a>>b;
		while(a!=b)
		{
			bool fd=0;
			for(int i=30;i>=0;i--)
			{
				if((a&(1<<i))&&(a+(1<<i))<=b)
				{
					a+=1<<i;
					fd=1;
					break;
				}
			}
			if(!fd)
				break;
			if(a>b)
				break;
		}
		puts(a==b?"YES":"NO");
	}
}