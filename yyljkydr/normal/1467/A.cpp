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
		printf("9"); 
		for(int i=2,j=8;i<=n;i++,j=(j+1)%10)
			printf("%d",j);
		puts("");
	}
}