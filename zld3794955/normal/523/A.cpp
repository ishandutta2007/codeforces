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
const int N=110,M=110;
char ch[N][M]={};
int main()
{	
	int n,m;
	cin>>m>>n;
	for(int i=0;i<n;++i)
	{
		char s[M]={};
		cin>>s;
		for(int j=0;j<m;++j)
			ch[j][i]=s[j];
	}
	for(int i=0;i<m+m;++i)
	{
		for(int j=0;j<n+n;++j)
			cout<<ch[i/2][j/2];
		cout<<endl;
	}
	return 0;
}