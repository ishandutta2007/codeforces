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
const int L=100010;
char ch[L]={};
int n;
int main()
{	
	gets(ch+1);
	n=strlen(ch+1);
	for(int i=1;i<n;++i)
		if((ch[i]-'0')%2==0 && ch[i]<ch[n])
		{
			swap(ch[i],ch[n]);
			puts(ch+1);
			return 0;
		}
	int last=0;
	for(last=n-1;last && (/*ch[last]==ch[n] || */(ch[last]-'0')%2);--last)
		;
	if(last) // ch[] is odd now.
	{
		swap(ch[last],ch[n]);
		puts(ch+1);
	}
	else
		puts("-1");
	return 0;
}