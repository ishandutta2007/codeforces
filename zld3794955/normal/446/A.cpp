#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=100010;
int n,a[N]={},x[N]={},y[N]={};
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	x[1]=1;
	for(int i=2;i<=n;++i)
		if(a[i]>a[i-1])
			x[i]=x[i-1]+1;
		else
			x[i]=1;
	y[n]=1;
	for(int i=n-1;i>=1;--i)
		if(a[i]<a[i+1])
			y[i]=y[i+1]+1;
		else
			y[i]=1;
	a[n+1]=0x7fffffff;
	//for(int i=1;i<=n;++i)
	//	cout<<x[i]<<' '<<y[i]<<endl;
	int ans=1;
	for(int i=1;i<=n;++i)
		ans=max(x[i]+1,ans);
	for(int i=1;i<=n;++i)
		ans=max(y[i]+1,ans);
	ans=min(ans,n);
	for(int i=1;i<=n;++i)
		if(a[i-1]+1<a[i+1])
			ans=max(ans,x[i-1]+y[i+1]+1);
	printf("%d\n",ans);
	return 0;
}