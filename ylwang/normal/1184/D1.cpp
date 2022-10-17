#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,m,t;
	scanf("%d %d %d %d",&n,&k,&m,&t);
	while(t--)
	{
		int op,i;
		scanf("%d %d",&op,&i);
		if(op==1)
		{
			n++;
			if(i<=k)
				k++;
		}
		else
		{
			if(i<k)
			{
				k-=i;
				n-=i;
			}
			else
				n=i;
		}
		printf("%d %d\n",n,k);
	}
	return 0;
}