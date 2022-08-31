#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 1000005

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

ll s1[SIZE];
ll s2[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int p;
		scanf("%d",&p);p--;
		if(p>=i)
		{
			s1[0]--;
			s1[p-i+1]++;
			s2[0]+=p-i;
			s2[p-i+1]-=p-i;
			
			s1[p-i+1]++;
			s1[n-i]--;
			s2[p-i+1]+=i-p;
			s2[n-i]-=i-p;
			
			s1[n-i]--;
			s2[n-i]+=p+n-i;
		}
		else
		{
			s1[0]++;
			s1[n-i]--;
			s2[0]+=i-p;
			s2[n-i]-=i-p;
			
			s1[n-i]--;
			s1[n-i+p+1]++;
			s2[n-i]+=p+n-i;
			s2[n-i+p+1]-=p+n-i;
			
			s1[n-i+p+1]++;
			s2[n-i+p+1]+=i-p-n;
		}
	}
	for(int i=1;i<n;i++) s1[i]+=s1[i-1],s2[i]+=s2[i-1];
	P ret=P(s2[0],0);
	for(int i=1;i<n;i++)
	{
		ll vl=s1[i]*(ll) i+s2[i];
		ret=min(ret,P(vl,i));
	}
	printf("%lld %d\n",ret.first,ret.second);
	return 0;
}