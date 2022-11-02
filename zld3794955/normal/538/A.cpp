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
const char ch[20]="CODEFORCES";
const int l=10,L=300;
char c[L]={};
int main()
{	
	cin>>c;
	int p1=0,p2=l-1,n=strlen(c);
	for(int i=0;i<n && p1<l;++i)
		if(ch[p1]==c[i])
			++p1;
		else
			break;
	for(int i=n-1;i>=0 && p2>=0;--i)
		if(ch[p2]==c[i])
			--p2;
		else
			break;
	if(n>=l && p1>p2)
		puts("YES");
	else
		puts("NO");
	return 0;
}