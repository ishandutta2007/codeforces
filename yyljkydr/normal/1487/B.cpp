#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n,k;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		if(n%2==0)
		{
			printf("%d\n",(k-1)%n+1);
		}
		else
		{
			k--;
			int st=k/(n/2);
			st=st*(n/2+1);
			st%=n;
			st+=k%(n/2);
			st%=n;
			st++;
			printf("%d\n",st);
		}
	}
}