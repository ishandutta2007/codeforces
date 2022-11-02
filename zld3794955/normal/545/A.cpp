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
#include<numeric>
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
int n,a[110][110]={},ans[110]={},tot=0;
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			cin>>a[i][j];
	for(int i=1;i<=n;++i)
	{
		int s=0;
		for(int j=1;j<=n;++j)
			if(a[i][j]==1 || a[i][j]==3)
				++s;
		if(!s)
			ans[++tot]=i;
	}
	cout<<tot<<endl;
	for(int i=1;i<=tot;++i)
		cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}