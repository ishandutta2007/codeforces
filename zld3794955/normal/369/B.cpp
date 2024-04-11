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
int n,k,l,r,s_all,s_k,s,a[1010]={};
int main()
{	
	scanf("%d%d%d%d%d%d",&n,&k,&l,&r,&s_all,&s_k);
	for(int i=l;i<=r;++i)
	{
		if((s_all-s_k)<=i*(n-k) && (s_k<=r*k))
		{	
			s=i;
			break;
		}
	}
	int delta_sum=s*(n-k)-(s_all-s_k);
	for(int i=1;i<=n-k;++i)
	{
		if(delta_sum>0)
		{
			printf("%d ",s-min(delta_sum,s-l));
			delta_sum-=min(delta_sum,s-l);
		}
		else
			printf("%d ",s);
	}
	delta_sum=r*k-s_k;
	for(int i=1;i<=k;++i)
	{
		if(delta_sum>0)
		{
			printf("%d ",r-min(delta_sum,r-s));
			delta_sum-=min(delta_sum,r-s);
		}
		else
			printf("%d ",r);
	}
	cout<<endl;	 
	return 0;
}