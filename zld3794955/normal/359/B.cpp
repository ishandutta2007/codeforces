#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
using namespace std;
int n,k,a[100001]={},delta=0;
int main()
{	
	scanf("%d%d",&n,&k);
	n*=2;
	for(int i=1;i<=n;++i)
		a[i]=i;
	delta=0;
	if(k==0)
	{
		for(int i=1;i<=n;++i)
			printf("%d ",a[i]);
		printf("\n");
	}
	else
		for(int i=1;i<=n;i+=2)
		{
			swap(a[i],a[i+1]);
			delta+=2;
			if(delta==(k<<1))
			{
				for(int i=1;i<=n;++i)
					printf("%d ",a[i]);
				printf("\n");
				break;
			}
		}
	return 0;
}