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
const int N=110,M=110,V=110;
int n,m,a[N]={},b[M]={},t[V]={},ans=0;
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	cin>>m;
	for(int j=1;j<=m;++j)
	{
		cin>>b[j];
		++t[b[j]];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		if(t[a[i]-1])
		{
			++ans;
			--t[a[i]-1];
		}
		else
			if(t[a[i]])
			{
				++ans;
				--t[a[i]];
			}
			else
				if(t[a[i]+1])
				{
					++ans;
					--t[a[i]+1];
				}
	}
	cout<<ans<<endl;
	return 0;
}