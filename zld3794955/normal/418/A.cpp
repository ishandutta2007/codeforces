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
const int N=1010,M=2000200;
int n,k,last[N]={},next[M]={},end[M]={},total_edge=0;
int in[N]={},out[N]={},tot=0,w1[M]={},w2[M]={};
bool b[N][N]={};
int main()
{	
	scanf("%d%d",&n,&k);
	if(n-1<k*2)
		printf("-1");
	else
	{
		printf("%d\n",n*k);
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=i+k;++j)
				printf("%d %d\n",i,(j-1)%n+1);
	}
	return 0;
}