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
const int N=200020;
int n,a[N]={};
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
}
void work()
{
	int ans=0;
	for(int i=n;i>=1;--i)
	{
		if(a[i]/2<=ans)
			break;
		for(int k=2;a[i]/k>ans;++k)
		{
			int p=lower_bound(a+1,a+n+1,a[i]/k+1)-a;
			ans=max(ans,a[i]%a[p]);
			//cout<<"a[i]="<<a[i]<<" a[p]="<<a[p]<<endl;
		}
		//cout<<"ans="<<ans<<endl;
	}
	printf("%d\n",ans);
}
int main()
{	
	//freopen("tmp.txt","r",stdin);
	init();
	work();
	/*
	srand(time(0));
	freopen("tmp.txt","w",stdout);
	cout<<200000<<endl;
	for(int i=1;i<=200000;++i)
		cout<<rand()*rand()%1000000+1<<' ';
	cout<<endl;
	*/
	return 0;
}