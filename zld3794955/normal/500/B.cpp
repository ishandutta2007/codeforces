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
const int N=330;
int n,p[N]={},root[N]={};
int get_root(int r)
{
	if(r!=root[r])
		root[r]=get_root(root[r]);
	return root[r];
}
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&p[i]),root[i]=i;
	scanf("\n");
	for(int i=1;i<=n;++i)
	{
		char ch[N]={};
		scanf("%s\n",ch+1);
		for(int j=1;j<=n;++j)
			if(ch[j]=='1')
				root[get_root(i)]=get_root(j);
	}
	for(int i=1;i<=n;++i)
	{
		int b=get_root(i),pos=i;
		for(int j=1;j<=n;++j)
			if(get_root(j)==b && p[j]<p[pos])
				pos=j;
		cout<<p[pos]<<' ';
		p[pos]=1<<20;
	}
	cout<<endl;
	return 0;
}