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
int n,a[330]={};
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<n;++i)
	{	
		for(int j=1;j<a[i];++j)
		{	
			putchar('P');
			putchar('R');
			putchar('L');
		}
		if(a[i])
			putchar('P');
		putchar('R');
	}
	for(int j=1;j<a[n];++j)
	{
		putchar('P');
		putchar('L');
		putchar('R');
	}
	if(a[n])
		putchar('P');
	putchar('\n');
	return 0;
}