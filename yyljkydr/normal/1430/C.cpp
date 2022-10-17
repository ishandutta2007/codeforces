#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,k;

int a[N];

vector<int>v[2];

vector<pair<int,int> >ans;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		puts("2");
		if(n==2)
			puts("1 2");
		else
		{
			printf("%d %d\n",n-2,n);
			printf("%d %d\n",n-1,n-1);
			for(int i=n-1;i>=3;i--)
				printf("%d %d\n",i,i-2);
		}		
	}
}