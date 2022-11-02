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
const int N=5050;
int n,t[4][N]={},tot[4]={};
int main()
{	
	cin>>n;
	for(int i=1,x=0;i<=n;++i)
	{
		cin>>x;
		t[x][++tot[x]]=i;
	}
	int ans=min(min(tot[1],tot[2]),tot[3]);
	cout<<ans<<endl;
	for(int i=1;i<=ans;++i)
		cout<<t[1][i]<<' '<<t[2][i]<<' '<<t[3][i]<<endl;
	return 0;
}