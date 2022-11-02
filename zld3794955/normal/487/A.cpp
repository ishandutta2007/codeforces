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
int h1,a1,d1,h2,a2,d2,h,a,d;
int calc(int da,int dd)
{
	da+=a1,dd+=d1;
	if(da<=d2)
		return 1<<22;
	int per1=max(a2-dd,0),per2=da-d2;
	int t=(h2+per2-1)/per2;
	return max(0,t*per1-h1+1);
}
int main()
{	
	cin>>h1>>a1>>d1>>h2>>a2>>d2>>h>>a>>d;
	int ans=1<<30;
	for(int i=0;i<=200;++i)
		for(int j=0;j<=200;++j)
			ans=min(ans,calc(i,j)*h+i*a+j*d);
	cout<<ans<<endl;
	return 0;
}