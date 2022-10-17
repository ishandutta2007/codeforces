#include<bits/stdc++.h>
using namespace std;

int T,sx,sy,tx,ty;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
		if(sx==tx||sy==ty)
			printf("%d\n",abs(tx-sx)+abs(ty-sy));
		else
			printf("%d\n",abs(tx-sx)+abs(ty-sy)+2);
	}
}