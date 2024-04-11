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
const int N=110;
int n,k;
char ch[N]={};
int main()
{	
	scanf("%d %d\n",&n,&k);
	scanf("%s\n",ch+1);
	if(k-1<n-k)
	{
		for(int i=1;i<k;++i)
			cout<<"LEFT"<<endl;
		for(int i=1;i<n;++i)
		{
			cout<<"PRINT "<<ch[i]<<endl;
			cout<<"RIGHT"<<endl;
		}
		cout<<"PRINT "<<ch[n]<<endl;
	}
	else
	{
		for(int i=k+1;i<=n;++i)
			cout<<"RIGHT"<<endl;
		for(int i=n;i>1;--i)
		{
			cout<<"PRINT "<<ch[i]<<endl;
			cout<<"LEFT"<<endl;
		}
		cout<<"PRINT "<<ch[1]<<endl;
	}
	return 0;
}