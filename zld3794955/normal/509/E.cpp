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
const int L=500050;
char ch[L];
int n,a[L]={},s1[L]={},s2[L]={};
int main()
{	
	gets(ch+1);
	n=strlen(ch+1);
	for(int i=1;i<=n;++i)
		a[i]=(ch[i]=='I'||ch[i]=='E'||ch[i]=='A'
			||ch[i]=='O'||ch[i]=='U'||ch[i]=='Y');
	for(int i=1;i<=n;++i)
		s1[i]=s1[i-1]+a[i];
	for(int i=n;i>=1;--i)
		s2[i]=s2[i+1]+a[i];
	long long S=s1[n],s=S;
	double ans=0;
	for(int i=1;i<=n;++i)
	{
		ans+=s*1.0/i;
		s+=S-s1[i]-s2[n-i+1];
	}
	printf("%.7f\n",ans);
	return 0;
}