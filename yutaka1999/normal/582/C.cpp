#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <cmath>
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int A[SIZE],mx[SIZE],gt[SIZE];
vector <int> L[SIZE];
bool use[SIZE];

int gcd(int a,int b)
{
	if(a==0) return b;
	return gcd(b%a,a);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	for(int i=1;i<n;i++) L[gcd(i,n)].push_back(i);
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		if(!L[i].empty())
		{
			for(int j=0;j<i;j++) mx[j]=0;
			for(int j=0;j<n;j++) mx[j%i]=max(mx[j%i],A[j]);
			for(int j=0;j<n;j++) use[j]=A[j]>=mx[j%i];
			memset(gt,0,sizeof(gt));
			for(int j=0;j<L[i].size();j++) gt[L[i][j]]++;
			for(int i=0;i<n;i++) gt[i+1]+=gt[i];
			int last=0;
			while(last<n-1&&use[last]) last++;
			last+=n;
			for(int j=n-1;j>=0;j--)
			{
				last=min(last,j+n-1);
				if(!use[j]) last=j;
				ret+=gt[last-j];
			}
		}
	}
	printf("%I64d\n",ret);
	return 0;
}