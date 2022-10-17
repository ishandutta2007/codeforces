#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,k,a,b; 

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&k,&a,&b);
		if(a>b)
			swap(a,b);
		while(a>1&&k)
			a--,k--;
		while(b<n&&k)
			b++,k--;
		printf("%d\n",b-a);
	}
}