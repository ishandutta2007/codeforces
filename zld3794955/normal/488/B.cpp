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
int n,a[4]={},v=1000000;
bool check()
{
	if(a[1]<=0 || a[2]<=0 || a[3]<=0 || a[0]<=0)
		return false;
	if(a[1]>v || a[2]>v || a[3]>v || a[0]>v)
		return false;
	int t[4]={};
	copy(a,a+4,t);
	sort(t,t+4);
	return t[1]+t[2]==t[0]+t[3] && t[1]+t[2]+t[0]+t[0]-t[3]-t[3]==0;
}
int main()
{	
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);
	if(n==0)
	{
		puts("YES\n1\n1\n3\n3");
		return 0;
	}
	else if(n==1)
	{
		cout<<"YES"<<endl<<a[0]+a[0]<<endl<<a[0]+a[0]<<endl<<a[0]*3<<endl;
		return 0;
	}
	else if(n==2)
	{
		if(a[0]*3>=a[1])
		{
			cout<<"YES"<<endl<<a[0]*3<<endl<<a[0]*4-a[1]<<endl;
			return 0;
		}
	}
	else if(n==3)
	{
		a[3]=a[0]+a[1]-a[2];
		if(check())
		{
			cout<<"YES"<<endl<<a[3]<<endl;
			return 0;
		}
		a[3]=a[0]+a[2]-a[1];
		if(check())
		{
			cout<<"YES"<<endl<<a[3]<<endl;
			return 0;
		}
		a[3]=a[1]+a[2]-a[0];
		if(check())
		{
			cout<<"YES"<<endl<<a[3]<<endl;
			return 0;
		}
	}
	else
		if(check())
		{
			puts("YES");
			return 0;
		}
	puts("NO");
	return 0;
}