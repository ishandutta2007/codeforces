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
const int M=110;
int m,s,a[M]={},b[M]={};
int main()
{	
	cin>>m>>s;
	if(s==0 || s>m*9)
	{
		if(m==1 && s==0)
			cout<<0<<' '<<0<<endl;
		else
			cout<<-1<<' '<<-1<<endl;
		return 0;
	}
	int tmp=s,tot=0;
	while(tmp)
	{
		a[++tot]=min(tmp,9);
		tmp-=min(tmp,9);
	}
	tmp=s-1,tot=m+1;
	b[1]=1;
	while(tmp)
	{
		b[--tot]+=min(tmp,9);
		tmp-=min(tmp,9);
	}
	for(int i=1;i<=m;++i)
		cout<<b[i];
	cout<<' ';
	for(int i=1;i<=m;++i)
		cout<<a[i];
	cout<<endl;
	return 0;
}