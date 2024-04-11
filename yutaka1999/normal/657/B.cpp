#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005

using namespace std;
typedef long long int ll;

int A[SIZE];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	vector <int> vec;
	for(int i=0;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		A[i]=a;
		vec.push_back(a);
	}
	for(int i=0;i<vec.size();i++)
	{
		if(i+1==vec.size()&&(vec[i]==0||vec[i]==-1)) break;
		int a=vec[i];
		if(a>=0)
		{
			if(i+1<vec.size()) vec[i+1]+=a/2;
			else if(a/2!=0) vec.push_back(a/2);
		}
		else
		{
			if(i+1<vec.size())
			{
				if((-a)%2==0) vec[i+1]+=a/2;
				else vec[i+1]+=(a-1)/2;
			}
			else
			{
				if((-a)%2==0) vec.push_back(a/2);
				else if((a-1)/2!=0) vec.push_back((a-1)/2);
			}
		}
		if(abs(a)%2==0) vec[i]=0;
		else vec[i]=1;
	}
	int cnt=0;
	for(int i=0;i<vec.size();i++) cnt+=(vec[i]!=0);
	//for(int i=0;i<vec.size();i++) printf("%d ",vec[i]);puts("");
	int ret=0;
	ll now=0;
	for(int i=vec.size()-1;i>=0;i--)
	{
		now*=2;
		now+=vec[i];
		cnt-=(vec[i]!=0);
		if(llabs(now)>=3LL*(ll) k) break;
		if(i<=n&&abs(A[i]-now)<=k&&cnt==0)
		{
			if(i<n||A[i]!=now) ret++;
		}
	}
	printf("%d\n",ret);
	return 0;
}