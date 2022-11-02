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
const int N=1010;
char ch[N+N]={},ans[N]={};
int n;
int minrepresent()
{
	int i=1,j=2,k=0;
	while(i<=n && j<=n && k<=n)
		if(ch[i+k]==ch[j+k])
			++k;
		else
		{
			(ch[i+k]<ch[j+k] ? j : i)+=k+1;
			j+=(i==j);
			k=0;
		}
	return min(i,j);
}
int main()
{
	cin>>n>>(ch+1);
	copy(ch+1,ch+n+1,ch+n+1);
	copy(ch+1,ch+n+1,ans+1);
	for(int t=1;t<=10;++t)
	{
		for(int j=1;j<=n+n;++j)
			ch[j]=ch[j]=='9' ? '0' : ch[j]+1;
		int pos=minrepresent();
		if(lexicographical_compare(ch+pos,ch+pos+n,ans+1,ans+n+1))
			copy(ch+pos,ch+pos+n,ans+1);
	}
	puts(ans+1);
	return 0;
}