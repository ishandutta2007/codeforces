#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <functional>
#include <cmath>
#include <map>
#include <string>

using namespace std;
typedef long long int ll;
typedef pair <ll,char> P;

int main()
{
	ll a,b;
	scanf("%I64d %I64d",&a,&b);
	vector <P> vec;
	while(a!=b)
	{
		if(a<b)
		{
			if(b%a==0)
			{
				vec.push_back(P(b/a-1,'B'));
				b=a;
			}
			else
			{
				vec.push_back(P(b/a,'B'));
				b%=a;
			}
		}
		else
		{
			if(a%b==0)
			{
				vec.push_back(P(a/b-1,'A'));
				a=b;
			}
			else
			{
				vec.push_back(P(a/b,'A'));
				a%=b;
			}
		}
	}
	if(a!=1) puts("Impossible");
	else
	{
		for(int i=0;i<vec.size();i++)
		{
			printf("%I64d",vec[i].first);
			printf("%c",vec[i].second);
		}puts("");
	}
	return 0;
}