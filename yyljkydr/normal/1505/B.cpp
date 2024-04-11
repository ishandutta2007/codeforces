#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	int ans=0;
	while(n)
	{
		ans+=n%10;
		n/=10;
	}
	printf("%d\n",(ans-1)%9+1);
}