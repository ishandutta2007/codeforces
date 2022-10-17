#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,w[N],n,x;

int isq(int x)
{
	int y=sqrt(x);
	while((y+1)*(y+1)<=x)
		y++;
	while(y*y>x)
		y--;
	return y*y==x;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n&1)
		{
			puts("NO");
			continue;
		}
		else
		{
			int k=n/2;
			if(isq(k))
			{
				puts("YES");
				continue;
			}
			if(k&1)
			{
				puts("NO");
				continue;
			}
			if(isq(k/2))
			{
				puts("YES");
				continue;
			}
			puts("NO");
		}
	}
}