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
		printf("%d\n",n>3?(n&1)+2:n-1);
	}
}