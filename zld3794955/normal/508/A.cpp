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
const int N=1010,M=1010;
bool b[N][M]={};
int n,m,k;
bool check(int x,int y)
{
	return b[x][y] && b[x+1][y] && b[x][y+1] && b[x+1][y+1];
}
int main()
{	
	cin>>n>>m>>k;
	for(int i=1,x=0,y=0;i<=k;++i)
	{
		cin>>x>>y;
		b[x][y]=true;
		if(check(x-1,y-1) || check(x-1,y) || check(x,y-1) || check(x,y))
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<0<<endl;
	return 0;
}