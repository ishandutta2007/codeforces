#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <cmath>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main()
{
	int b,n;
	scanf("%d %d",&b,&n);
	int ret=0;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if(i+1<n) a*=b;
		if(a%2==1) ret^=1;
	}
	if(ret) puts("odd");
	else puts("even");
	return 0;
}