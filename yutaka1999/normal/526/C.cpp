#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <set>
#include <functional>
#include <queue>
#include <map>
#define SIZE 1000005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main()
{
	ll C,h1,h2,w1,w2;
	scanf("%I64d %I64d %I64d %I64d %I64d",&C,&h1,&h2,&w1,&w2);
	ll ret=0;
	for(int i=0;i<SIZE;i++)
	{
		ll o1=w1*(ll) i;
		if(o1<=C)
		{
			ll c2=(C-o1)/w2;
			ret=max(ret,h1*(ll) i+h2*c2);
		}
		ll o2=w2*(ll) i;
		if(o2<=C)
		{
			ll c1=(C-o2)/w1;
			ret=max(ret,h1*c1+h2*(ll) i);
		}
	}
	printf("%I64d\n",ret);
	return 0;
}