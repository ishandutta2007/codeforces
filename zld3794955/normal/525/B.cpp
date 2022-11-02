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
const int L=200020;
char ch[L]={};
int n,m,a[L]={};
int main()
{	
	cin>>(ch+1);
	n=strlen(ch+1);
	cin>>m;
	for(int i=1;i<=m;++i)
		cin>>a[i];
	sort(a+1,a+m+1);
	for(int i=1,p=1;i<=n/2;++i)
	{
		while(p<=m && a[p]==i)
			++p;
		if(p%2==0)
			swap(ch[i],ch[n-i+1]);
	}
	puts(ch+1);
	return 0;
}