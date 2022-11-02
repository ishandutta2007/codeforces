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
const int N=110,L=110,P=26;
int n,l[N]={},total_edge=0;
bool b[P][P]={};
char name[N][L]={},ans[N]={};
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>(name[i]+1);
		l[i]=strlen(name[i]+1);
	}
	for(int i=2;i<=n;++i)
	{
		int pos=1;
		while(name[i][pos]==name[i-1][pos])
			++pos;
		if(pos>l[i])
		{
			puts("Impossible");
			return 0;
		}
		if(pos>l[i-1])
			continue;
		b[name[i][pos]-'a'][name[i-1][pos]-'a']=true;
	}
	bool v[P]={};
	for(int t=1;t<=P;++t)
	{
		int now=-1;
		for(int i=0;i<P && now==-1;++i)
		{
			if(v[i])
				continue;
			bool flag=true;
			for(int j=0;j<P && flag;++j)
				if(!v[j] && b[i][j])
					flag=false;
			if(flag)
				now=i,v[i]=true;
		}
		if(now==-1)
		{
			puts("Impossible");
			return 0;
		}
		else
			ans[t]=now+'a';
	}
	puts(ans+1);
	return 0;
}