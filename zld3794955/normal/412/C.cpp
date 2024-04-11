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
const int N=100100;
int n,l=0;
char ch[N]={},ans[N]={};
int main()
{	
	scanf("%d\n",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s\n",ch+1);
		l=strlen(ch+1);
		for(int j=1;j<=l;++j)
			if(ch[j]!='?')
			{
				if(ans[j]==0)
					ans[j]=ch[j];
				else
					if(ans[j]!=ch[j])
						ans[j]='?';
			}
	}
	for(int i=1;i<=l;++i)
		if(ans[i]==0)
			ans[i]='a';
	printf("%s\n",ans+1);
	return 0;
}