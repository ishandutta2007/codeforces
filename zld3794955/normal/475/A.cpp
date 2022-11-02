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
int k;
int main()
{	
	cin>>k;
	cout<<"+------------------------+"<<endl;
	cout<<"|";
	if(k<=2)
	{
		for(int i=1;i<=(k+2)/3;++i)
			cout<<"O.";
		for(int i=(k+2)/3+1;i<=11;++i)
			cout<<"#.";
	}
	else
	{
		for(int i=1;i<=(k+1)/3;++i)
			cout<<"O.";
		for(int i=(k+1)/3+1;i<=11;++i)
			cout<<"#.";
	}
	cout<<"|D|)"<<endl;
	cout<<"|";
	if(k<=2)
	{
		for(int i=1;i<=(k+1)/3;++i)
			cout<<"O.";
		for(int i=(k+1)/3+1;i<=11;++i)
			cout<<"#.";
	}
	else
	{
		for(int i=1;i<=(k)/3;++i)
			cout<<"O.";
		for(int i=(k)/3+1;i<=11;++i)
			cout<<"#.";
	}
	cout<<"|.|"<<endl;
	cout<<"|";
	if(k>=3)
		cout<<"O";
	else
		cout<<"#";
	for(int i=1;i<=23;++i)
		cout<<".";
	cout<<"|"<<endl;
	cout<<"|";
	for(int i=1;i<=(k-1)/3;++i)
		cout<<"O.";
	for(int i=(k-1)/3+1;i<=11;++i)
		cout<<"#.";
	cout<<"|.|)"<<endl;
	cout<<"+------------------------+"<<endl;
	return 0;
}