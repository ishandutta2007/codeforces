#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <queue>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int all=0,even=0,odd=0;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		a%=2;
		if(a==0) even++;
		else
		{
			odd++;
			all^=1;
		}
	}
	string s="Stannis";
	string t="Daenerys";
	if(n==k)
	{
		if(odd%2==1) printf("%s\n",s.c_str());
		else printf("%s\n",t.c_str());
	}
	else if((n-k)%2==0)
	{
		int S=(n-k)/2;
		if(even<=S&&k%2==1) printf("%s\n",s.c_str());
		else printf("%s\n",t.c_str());
	}
	else
	{
		int zan=n-k;
		int T=(n-k-1)/2;
		if(odd<=T||(even<=T&&k%2==0)) printf("%s\n",t.c_str());
		else printf("%s\n",s.c_str());
	}
	return 0;
}