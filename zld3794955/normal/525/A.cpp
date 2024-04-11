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
int n,l=0,t[26]={},ans=0;
int main()
{	
	cin>>n>>(ch+1);
	l=strlen(ch+1);
	for(int i=1;i<=l;++i)
		if(isupper(ch[i]))
		{
			if(t[ch[i]-'A']==0)
				++ans;
			else
				--t[ch[i]-'A'];
		}
		else
			++t[ch[i]-'a'];
	cout<<ans<<endl;
	return 0;
}