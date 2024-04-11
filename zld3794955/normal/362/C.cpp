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
int n,a[5050]={},b[5050]={},tot=0;
int front[5050][5050]={},back[5050][5050]={};
void problem_function()
{
	for (int i = 2; i <= n; i = i + 1)
	{
   		int j = i; 
 	  	while (j > 1 && a[j] < a[j - 1])
   		{
    		swap(a[j], a[j - 1]); // swap elements a[j] and a[j - 1]
   			j = j - 1;
   			++tot;
   		}
	}
}
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	problem_function();
}
inline void copy()
{
	for(int i=1;i<=n;++i)
		a[i]=b[i];
}
void work()
{
	int t=0,max_de=0;
	copy();
	for(int i=1;i<=n;++i)
	{
		int t=0;
		for(int j=i+1;j<=n;++j)
		{	
			if(a[i]>a[j])
				++t;
			front[i][j]=t;
		}
	}
	for(int i=n;i>=1;--i)
	{
		int t=0;
		for(int j=i-1;j>=1;--j)
		{
			if(a[i]<a[j])
				++t;
			back[j][i]=t;
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
		{	
			int dd=front[i][j]-(j-i-front[i][j])+back[i][j]-(j-i-back[i][j])+(a[i]<a[j] ? 1 : -1);
			if(dd>max_de)
			{
				max_de=dd;
				t=1;
			}
			else
				if(dd==max_de)
					++t;
		}
	printf("%d %d\n",tot-max_de,t);
}
int main()
{	
	init();
	work();
	return 0;
}