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
int n,a[110]={}; 
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
}
bool check(int mid)
{
	//cout<<"check(mid="<<mid<<")"<<endl;
	int w[110]={};
	for(int i=1;i<=mid;++i)
		++w[i];
	for(int i=mid+1;i<=n;++i)
	{
		int minn=0x7fffffff,p=0;
		for(int j=1;j<=mid;++j)
			if(w[j]<minn)
				p=j,minn=w[j];
		if(minn>a[i])
			return false;
		else
			++w[p];
	}
	return true;
}
void work()
{
	int l=1,r=n;
	while(l!=r)
	{
		int mid=l+r>>1;
		if(!check(mid))
			l=mid+1;
		else
			r=mid;
	}
	printf("%d\n",l);
}
int main()
{	
	init();
	work();
	return 0;
}