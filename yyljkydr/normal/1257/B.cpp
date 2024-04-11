#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

long long a,b; 

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&a,&b);
		bool flag=false;
		for(int i=1;i<=100;i++)
		{
			if(a>=b)
			{
				puts("Yes");
				flag=1;
				break;
			}
			if(a&1)
				a--;
			a=a/2*3;
		}
		if(!flag)
			puts("No");
	}
}