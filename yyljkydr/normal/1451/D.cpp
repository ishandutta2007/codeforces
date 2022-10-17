#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,d,k;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&d,&k);
		int x=0;
		while(2ll*(x+k)*(x+k)<=1ll*d*d)
			x+=k;
		if(1ll*x*x+1ll*(x+k)*(x+k)<=1ll*d*d)
			puts("Ashish");
		else
			puts("Utkarsh");
	}
}