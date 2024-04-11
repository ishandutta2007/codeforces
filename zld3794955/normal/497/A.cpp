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
const int N=1010,M=1010;
char ch[N][M]={};
int n,m,ans=0;
bool b[N]={};
int main()
{	
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%s\n",ch[i]+1);
		b[i]=true;
	}
	for(int j=1;j<=m;++j)
	{
		bool flag=true;
		for(int i=1;i<n && flag;++i)
			if(b[i] && ch[i][j]>ch[i+1][j])
				flag=false;
		if(flag)
			for(int i=1;i<n;++i)
				b[i]&=ch[i][j]==ch[i+1][j];
		else
			++ans;
	}
	printf("%d\n",ans);
	return 0;
}