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
const int K=5;
long long l,r,k,a[K]={},ans=1ll<<60,ansv[K]={},tot=0;
void tryy(long long now,int t)
{
	if(t>1)
	{
		long long sum=0;
		for(int i=1;i<t;++i)
			sum^=a[i];
		if(sum<ans)
		{
			ans=sum;
			tot=t-1;
			copy(a+1,a+tot+1,ansv+1);
		}
		if(t>k)
			return;
	}
	for(long long i=now;i<=r;++i)
	{
		a[t]=i;
		tryy(i+1,t+1);
	}
}
int main()
{	
	cin>>l>>r>>k;
	k=min(k,4ll);
	if(r-l<=5)
		tryy(l,1);
	else
	{
		if(k==1)
			ansv[tot=1]=ans=l;
		if(k==2)
		{
			ans=1;
			ansv[1]=l+1;
			ansv[tot=2]=l%2 ? l+2 : l;
		}
		if(k==3)
		{
			int b=60;
			for(int i=1;i<=b;++i)
			{
				//cout<<(1ll<<(i-1))<<' '<<(3ll<<(i-1))<<endl;
				if((1ll<<i)-1>=l && (3ll<<(i-1))<=r)
				{
					ans=0;
					ansv[1]=(1ll<<i)-1;
					ansv[2]=ansv[1]+(1ll<<(i-1));
					ansv[tot=3]=(3ll<<(i-1));
				}
			}
			if(ans!=0)
			{
				ans=1;
				ansv[1]=l+1;
				ansv[tot=2]=l%2 ? l+2 : l;
				--k;
			}
		}
		if(k==4)
		{
			ans=0;
			ansv[1]=l+1,ansv[2]=l+2,ansv[3]=l+3;
			ansv[tot=4]=l%2 ? l+4 : l;
		}
	}
	cout<<ans<<endl<<tot<<endl;
	for(int i=1;i<=tot;++i)
		cout<<ansv[i]<<' ';
	cout<<endl;
	return 0;
}