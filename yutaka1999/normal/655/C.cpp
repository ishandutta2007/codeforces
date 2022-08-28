#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define INF 100000000000000000LLL

using namespace std;
typedef long long int ll;

vector <int> vec;
char str[SIZE];
int dp[SIZE];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	scanf("%s",&str);
	for(int i=0;i<n;i++) if(str[i]=='0') vec.push_back(i);
	int l=-1,r=n;
	while(r-l>1)
	{
		int m=(l+r)/2;
		int to=0;
		for(int i=0;i<vec.size();i++)
		{
			while(to<i&&vec[i]-vec[to]>m) to++;
			dp[i]=i-to;
		}
		to=0;
		bool up=false;
		for(int i=0;i<vec.size();i++)
		{
			while(to<vec.size()&&vec[to]-vec[i]<=m) to++;
			dp[i]+=to-i;
			if(dp[i]>=k+1) up=true;
		}
		if(up) r=m;
		else l=m;
	}
	printf("%d\n",r);
	return 0;
}