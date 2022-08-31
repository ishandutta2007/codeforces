#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main()
{
	int a,b,c,d,e,f;
	scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
	int sum=a+b+c;
	int all=sum*sum-a*a-c*c-e*e;
	printf("%d\n",all);
	return 0;
}