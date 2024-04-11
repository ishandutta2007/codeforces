#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
using namespace std;
int n,x=1,a,s=0;
int main()
{	
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a);
		s+=a;
	}
	s= s>=0 ? s : -s;
	cout<<(s+x-1)/x<<endl;
	return 0;
}